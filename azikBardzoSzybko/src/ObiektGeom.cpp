#include <iostream>
#include <fstream>
#include "ObiektGeom.hh"



using namespace std;
void ObiektGeom::setRotationMatrix(double angle) {
    rotationMatrix = { Vector3D{cos(angle), -sin(angle), 0}, Vector3D{sin(angle), cos(angle), 0}, Vector3D{0, 0, 1 } };
}

ObiektGeom::ObiektGeom( const char*  sNazwaPliku_BrylaWzorcowa, const char*  sNazwaObiektu,int KolorID, Vector3D locationVec, Vector3D scaleVec)
:_NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";

  locationVector = locationVec;
  scaleVector = scaleVec;
}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki() {
  ifstream  StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream  StrmWy(_NazwaPliku_BrylaRysowana);

  if (!(StrmWe.is_open() && StrmWy.is_open())) {
    cerr << endl << "Nie mozna otworzyc jednego z plikow:" << endl
	 << "    " << _NazwaPliku_BrylaWzorcowa << endl
	 << "    " << _NazwaPliku_BrylaRysowana << endl
	 << endl;
    return false;
  }

  Vector3D wsp;

  int Indeks_Wiersza = 0;

  StrmWe >> wsp;

  if (StrmWe.fail())return false;

  do {
    hull.get().emplace_back(rotationMatrix * (scaleVector * wsp) + locationVector);
    StrmWy << hull.get().back() << '\n';
    ++Indeks_Wiersza;

    if (Indeks_Wiersza >= 4) {
      StrmWy << '\n';
      Indeks_Wiersza = 0;
    }

    StrmWe >> wsp;

  } while (!StrmWe.fail());

  if (!StrmWe.eof()) return false;

  return Indeks_Wiersza == 0 && !StrmWy.fail();
}
