#define _USE_MATH_DEFINES	// Visual C++でM_PIを使えるように
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

	phase = App::rand() * M_PI;	// M_PIはπ

	x = 100 + 500 * App::rand();
	y = 100 + 200 * App::rand();

	vx = 150 + 200 * App::rand();
	vy = 150 + 200 * App::rand();

	radius = 20;
}

void EnemyB::update()
{
	double dt = elapsed.get();
	double mt = mtimer.get();
	double dx, dy;

	// updateの間隔が長すぎるときは、強制的にdtを設定
	if (dt > 1.0 / 30)
		dt = 1.0 / 30;

	dx = vx * sin(2 * mt + phase) * dt;
	dy = vy * cos(5 * mt + phase) * dt;

	x += dx;
	y += dy;

	elapsed.reset();
}

void EnemyB::draw()
{
	Rectangle(App::hDC, x - radius, y - radius, x + radius, y + radius);
}