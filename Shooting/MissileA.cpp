#include "MissileA.h"

void MissileA::init() {
	FlyingObject::init();
	vx = vy = 0;
	radius = 10;
}
