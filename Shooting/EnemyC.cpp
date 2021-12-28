#define _USE_MATH_DEFINES
#include "EnemyC.h"
#include <cmath>
#include "ShootingApp.h"


EnemyC::EnemyC() {
	phase = 0;
	point = 30;
}

EnemyC::~EnemyC(){}

void EnemyC::init()
{
	FlyingObject::init();

	phase = App::rand() * M_PI;	

	x = 100 + 500 * App::rand();
	y = 100 + 200 * App::rand();

	vx = 150 + 200 * App::rand();
	vy = 150 + 200 * App::rand();

	radius = 5;
}

void EnemyC::update()
{
	if (status & COLLISION)
	{
		if (etimer.get() > 0.5)
			cleanup();
		return;
	}
	double dt = elapsed.get();
	double mt = mtimer.get();
	double dx, dy;

	if (dt > 1.0 / 30)
		dt = 1.0 / 30;

	dx = vx * sin(2 * mt + phase) * dt;
	dy = vy * cos(5 * mt + phase) * dt;

	x += dx;
	y += dy;

	elapsed.reset();
}

void EnemyC::draw()
{
	if (status & COLLISION)
	{
		drawExplosion();
		return;
	}
	Rectangle(App::hDC, x - radius, y - radius, x + radius, y + radius);
}

void EnemyC::drawExplosion()
{
	LPCWSTR c;
	double t = etimer.get();
	if (t > 0.4) {
		c = TEXT("*");
		TextOut(App::hDC, (int)x - 5, (int)y - 5, c, lstrlen(c));
	}
	else if (t > 0.3)
	{
		c = TEXT("***");
		TextOut(App::hDC, (int)x - 15, (int)y - 5, c, lstrlen(c));
	}
	else if (t > 0.2)
	{
		c = TEXT("(***)");
		TextOut(App::hDC, (int)x - 25, (int)y - 5, c, lstrlen(c));
	}
	else
	{
		Sound::getInstance()->request(TEXT("explosion"));
		c = TEXT("(*)");
		TextOut(App::hDC, (int)x - 15, (int)y - 5, c, lstrlen(c));
		radius = 100;
	}
}