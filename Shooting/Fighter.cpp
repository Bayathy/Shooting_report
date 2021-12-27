#include "ShootingApp.h"
#include "Fighter.h"

Fighter::Fighter() : FlyingObject(), dir(STOP)
{
}

Fighter::~Fighter()
{
}

void Fighter::init()
{
	FlyingObject::init();

	x = 400;
	vx = 200;
	y = 400;
	vy = 200;
	radius = 28;
}

void Fighter::cleanup()
{
	FlyingObject::cleanup();
	Amissiles.clear();
	Bmissiles.clear();
}

void Fighter::update()
{
	if (status & COLLISION) { // 衝突していたら座標を更新しない
		if (etimer.get() > 0.5) // 衝突期間が終わったら、
			cleanup(); // 終了手続き
		return;
	}


	double dx = 0;
	double dy = 0;
	double dt = elapsed.get();

	if (dir & LEFT)
		dx -= vx * dt;
	if (dir & RIGHT)
		dx += vx * dt;
	if (dir & FORE)
		dy -= vy * dt;
	if (dir & BACK)
		dy += vy * dt;

	y += dy;
	x += dx;
	elapsed.reset();
}

void Fighter::draw()
{
	if (status & COLLISION)
	{
		drawExplosion();
		return;
	}
	LPCWSTR c;
	c = TEXT("|");
	TextOut(App::hDC, (int)x - 2, (int)y - 22, c, lstrlen(c));
	c = TEXT("--+--");
	TextOut(App::hDC, (int)x - 28, (int)y - 8, c, lstrlen(c));
	c = TEXT("-+-");
	TextOut(App::hDC, (int)x - 17, (int)y + 6, c, lstrlen(c));
	drawDebug();
}


void Fighter::move(DIRECTION dir)
{
	this->dir |= dir;
}

void Fighter::stop(DIRECTION dir)
{
	this->dir &= ~dir;
}

void Fighter::loadMissileA(Missile* m)
{
	Amissiles.push_back(m);
}

void Fighter::loadMissileB(Missile* m)
{
	Bmissiles.push_back(m);
}

void Fighter::shootA()
{
	for (size_t i = 0; i < Amissiles.size(); i++)
		if (!(Amissiles[i]->status & ACTIVE)) {
			Amissiles[i]->init();
			Amissiles[i]->fire(x, y - radius, 0, -400);
			Sound::getInstance()->request(TEXT("shoot"));
			return;
		}
}

void Fighter::shootB()
{
	for (size_t i = 0; i < Bmissiles.size(); i++)
		if (!(Bmissiles[i]->status & ACTIVE)) {
			Bmissiles[i]->init();
			Bmissiles[i]->fire(x, y - radius, 0, -800);
			Sound::getInstance()->request(TEXT("shoot"));
			return;
		}
}
