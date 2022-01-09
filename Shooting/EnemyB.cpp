#define _USE_MATH_DEFINES	
#include "EnemyB.h"
#include <cmath>
#include "ShootingApp.h"

EnemyB::EnemyB() : Enemy() 
{
	point = 10;
}


EnemyB::~EnemyB()
{
}

void EnemyB::init()
{
	FlyingObject::init();

	x = 100 + 500 * App::rand();
	y = 100 + 200 * App::rand();

	vx = -800 * App::rand();
	vy = 0;

	radius = 20;
}

void EnemyB::update()
{
	if(status & COLLISION)
	{
		if (etimer.get() > 0.5)
			cleanup();
		return;
	}
	double dt = elapsed.get();
	double mt = mtimer.get();
	double dx, dy;

	// update‚ÌŠÔŠu‚ª’·‚·‚¬‚é‚Æ‚«‚ÍA‹­§“I‚Édt‚ðÝ’è
	if (dt > 1.0 / 30)
		dt = 1.0 / 30;

	if (x > 800 || x < 0)
		vx = -vx;

	dx = vx * dt;
	dy = vy * cos(5 * mt + phase) * dt;

	x += dx;
	y += dy;

	elapsed.reset();
}

void EnemyB::draw()
{
	if (status & COLLISION)
	{
		drawExplosion();
		return;
	}
	Rectangle(App::hDC, x - radius, y - radius, x + radius, y + radius);
}