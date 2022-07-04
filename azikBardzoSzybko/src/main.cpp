#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "Kolory.hh"
#include "rover.h"
#include <vector.h>
#include <memory.h>


using namespace std;




/*!
 *  \brief Inicjalizuje połączenie z programem gnuplot oraz rozmiar świata.
 *
 *  Inicjalizuje podstawowe parametry "swiata", tzn. jego wymiary,
 *  które będą widoczne jako obszar objęty układem współrzędnych.
 *  Następnie w tle uruchamiany jest program gnuplot.
 *  \param[in] rLacze - nieaktywne łącze do gnuplota.
 */
void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze)
{
  rLacze.ZmienTrybRys(PzG::TR_3D);
  rLacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
  rLacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
  rLacze.UstawZakresZ(-0, 90);
  rLacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  rLacze.Inicjalizuj();  // Tutaj startuje gnuplot.
}



void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb)
{
  PzG::InfoPlikuDoRysowania *wInfoPliku;

  wInfoPliku = &rLacze.DodajNazwePliku(rOb.WezNazwePliku_BrylaRysowana());
  wInfoPliku->ZmienKolor(rOb.WezKolorID());
}



int main()
{
	PzG::LaczeDoGNUPlota  Lacze;

	Inicjalizuj_Lacze(Lacze);
	if (!Inicjalizuj_PowierzchnieMarsa(Lacze)) return 1;
  std::vector<std::shared_ptr<Rover>> rovers;
  rovers.emplace_back(std::make_shared<Rover>("bryly_wzorcowe/szescian3.dat", "FSR", Kolor_JasnoNiebieski, Vector3D{ 1.0,1.0,1.0 }, Vector3D{ 10.0,20.0,10.0 },1,1));
  rovers.emplace_back(std::make_shared<Rover>("bryly_wzorcowe/szescian3.dat", "Perseverance", Kolor_JasnoNiebieski, Vector3D{  20, 30, 1  }, Vector3D{ 10.0, 20.0, 10.0 },1,1));
  rovers.emplace_back(std::make_shared<Rover>("bryly_wzorcowe/szescian3.dat", "Curiosity", Kolor_JasnoNiebieski, Vector3D{ 50, 70, 1 }, Vector3D{ 10, 20, 10 },1,1));

  std::vector<std::shared_ptr<ObiektGeom>> objects;
  for (auto& ptr : rovers)
    objects.emplace_back(std::static_pointer_cast<ObiektGeom>(ptr));
  //Rover Ob1("bryly_wzorcowe/szescian3.dat", "FSR", Kolor_JasnoNiebieski, { 1.0,1.0,1.0 }, { 10.0,20.0,10.0 },1,1);
  //ObiektGeom  Ob2("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony, { 20.0, 20.0, 10.0 }, { 60.0, 60.0, 0.0 });
  //ObiektGeom  Ob3("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony, { 20, 20, 10 }, { -20, 70, 0 });

  for (auto& rover : rovers)
    DodajDoListyRysowania(Lacze, *rover);

  for (auto& rover : rovers)
    rover->Przelicz_i_Zapisz_Wierzcholki();
  Lacze.Rysuj();

  while(true) {
      cout << endl << "Starting gnuplot" << endl << endl;
      system("clear");
      cout<<"Choose rover:\n";
      cout<<"1 - Rover1\n";
      cout<<"2 - Rover2\n";
      cout<<"3 - Rover3\n";
      cout<<"e - exit\n\n";

      char number = '0';
      for (;number != '1'&& number != '2' && number != '3' && number !='e' ; cin >> number){}
      if(number=='e') break;
      system("clear");

      cout<<"Choose one of the following actions:\n\n";
      cout<<"t - turn rover by angle\n";
      cout<<"m - move rover\n";
      cout<<"e - exit current rover\n\n";
      int num = ((int)number)-48;
      bool imenu = true;
      char option;
      while(imenu){
        for (option = '\0'; option != 'm' && option != 't' && option !='e' ; cin >> option) {}

	      switch(option) {
		      case 'm':
            cout<<"insert distance:\n";
            double tempDistance;
            cin>> tempDistance;
            rovers[num-1]->move(tempDistance);
            break;
		      case 't':
            cout<<"insert angle:\n";
            double tempAngle;
            cin>> tempAngle;
            rovers[num-1]->rotate(tempAngle);
            break;
		      case 'e':
              imenu=false;
            break;
	      }
        if (rovers[num-1]->collide(objects, num - 1) != -1) {
            std::cout << "Collide\n";
        }
        rovers[num-1]->Przelicz_i_Zapisz_Wierzcholki();
	      Lacze.Rysuj();
      }
  }
}
