#define _USE_MATH_DEFINES	// Visual C++��M_PI���g����悤��
#include <cmath>
#include "ShootingApp.h"
#include "EnemyA.h"

EnemyA::EnemyA() : Enemy()
{
	point = 20;
}


EnemyA::~EnemyA()
{
}

void EnemyA::init()
{
	FlyingObject::init();

	phase = App::rand() * M_PI;	// M_PI�̓�

	x = 100 + 500 * App::rand();
	y = 100 + 200 * App::rand();

	vx = 100 + 200 * App::rand();
	vy = 100 + 200 * App::rand();

	radius = 30;
}

void EnemyA::update()
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

	// update�̊Ԋu����������Ƃ��́A�����I��dt��ݒ�
	if (dt > 1.0 / 30)
		dt = 1.0 / 30;

	dx = vx * sin(2 * mt + phase) * dt;
	dy = vy * cos(5 * mt + phase) * dt;

	x += dx;
	y += dy;

	elapsed.reset();
}

void EnemyA::draw()
{
	if (status & COLLISION)
	{
		drawExplosion();
		return;
	}
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
}
