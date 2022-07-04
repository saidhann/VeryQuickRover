#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include "ConvexHull.h"
#include "matrix.h"
#include <math.h>

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "pliki_do_rysowania"
typedef Vector<double, 3> Vector3D;
typedef Matrix<double, 3> Matrix3D;

class ObiektGeom {
    std::string   _NazwaPliku_BrylaWzorcowa;
    std::string   _NazwaPliku_BrylaRysowana;
    std::string   _NazwaObiektu;
    int _KolorID;

 protected:
    ConvexHull  hull;
    Vector3D locationVector;
    Vector3D scaleVector{ 1,1,1 };
    Matrix3D rotationMatrix{Vector3D{1,0,0}, Vector3D{0,1,0}, Vector3D{0,0,1}};

  public:
    void setRotationMatrix(double angle);

    ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa,const char* sNazwaObiektu,int KolorID,Vector3D tempLocationVector , Vector3D tempScaleVector);

    int WezKolorID() const {
        return _KolorID;
    }

    const std::string& WezNazweObiektu() const {
        return _NazwaObiektu;
    }

    const std::string & WezNazwePliku_BrylaRysowana() const {
        return _NazwaPliku_BrylaRysowana;
    }

    ConvexHull const& getHull(void) const {
        return hull;
    }

    bool Przelicz_i_Zapisz_Wierzcholki();

    virtual ~ObiektGeom(void) noexcept = default;
};


#endif
