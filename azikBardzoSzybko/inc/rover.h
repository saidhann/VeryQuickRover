#pragma once
#include <ObiektGeom.hh>
#include <vector.h>
#include <memory>

class Rover
:public ObiektGeom
{
private:
	double speed;

	Vector3D oldLocation;

	Matrix3D oldFacing{Vector3D{1,0,0}, Vector3D{0,1,0}, Vector3D{0,0,1}};

	double facing;
public:
	void rotate(double angle);

	void move(double howFar);

	Rover(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, Vector3D tempLocationVector, Vector3D tempScaleVector,
		double tempFacing, double tempSpeed);

	int collide(std::vector<std::shared_ptr<ObiektGeom>> const& entities, int numb) const;
};