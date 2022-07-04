#include "rover.h"

void Rover::rotate(double angle) {
	oldFacing=rotationMatrix;
	setRotationMatrix(angle + facing);
}

void Rover::move(double howFar) {
	oldLocation=locationVector;
	locationVector += rotationMatrix * Vector3D{1., 0., 0.} * howFar * speed;
}

Rover::Rover(
	const char* sNazwaPliku_BrylaWzorcowa,
	const char* sNazwaObiektu,
	int KolorID,
	Vector3D tempLocationVector,
	Vector3D tempScaleVector,
	double tempFacing,
	double tempSpeed)
		:ObiektGeom{sNazwaPliku_BrylaWzorcowa,sNazwaObiektu,KolorID,tempLocationVector,tempScaleVector}
{
	facing = tempFacing;
	oldLocation = tempLocationVector;
	speed = tempSpeed;
}

int Rover::collide(std::vector<std::shared_ptr<ObiektGeom>> const& entities, int numb) const {
	std::cout<<"col\n";
	for (int i = 0;static_cast<uint>(i) < entities.size(); ++i) {
		//std::cout<<i<<" @ "<<numb<<"\n";
		if (i != numb && notIntersect(hull, entities[i]->getHull())) {
			//rotationMatrix = oldFacing;
			//locationVector = oldLocation;
			std::cout<<"kolizja!!!!\n";
			return i;
			}
	}
	return -1;
}
