#include "ShootingApp.h"
#include "FlyingObject.h"
#define sqr(x) ((x)*(x))

FlyingObject::FlyingObject() : x(0), vx(0),y(0),vy(0),radius(0),status(0)
{
}


FlyingObject::~FlyingObject()
{
}

void FlyingObject::init()
{
	x = 0;
	vx = 0;
	y = 0; 
	vy = 0;
	status = ACTIVE;
	mtimer.reset();
	elapsed.reset();
}

void FlyingObject::cleanup()
{
	status = 0;
}

void FlyingObject::update()
{

	if (status & COLLISION)
	{
		if (etimer.get() > 0.5)
			cleanup();
		return;
	}

}

void FlyingObject::draw()
{

	if (status & COLLISION)
	{
		drawExplosion();
		return; 
	}

}

void FlyingObject::drawExplosion()
{
	LPCWSTR c;
	double t = etimer.get();
	if (t > 0.4) {
		c = TEXT("*");
		TextOut(App::hDC, (int)x - 5, (int)y - 5, c, lstrlen(c));
	}
	else if ( t > 0.3)
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
		c = TEXT("(*)");
		TextOut(App::hDC, (int)x - 15, (int)y - 5, c, lstrlen(c));
	}
}


void FlyingObject::drawDebug() {
	HBRUSH hBrush, hBrush_old;
	HPEN hPen, hPen_old;
	hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
	hBrush_old = (HBRUSH)SelectObject(App::hDC, hBrush);
	hPen_old = (HPEN)SelectObject(App::hDC, hPen);
	Ellipse(App::hDC, x - radius , y - radius, x + radius, y + radius);
	DeleteObject(hPen);
	SelectObject(App::hDC, hBrush_old);
	SelectObject(App::hDC, hPen_old);
}

bool FlyingObject::checkCollision(FlyingObject* fo) {
	if (!(fo->status & ACTIVE))
		return false;

	if (sqr(radius + fo -> radius) < (sqr(x - fo->x) + sqr(y - fo -> y)))
		return false;

	if (!(status & COLLISION)) {
		status |= COLLISION;
		etimer.reset();
	}

	if (!(fo->status & COLLISION)) {
		fo->status |= COLLISION;
		fo->etimer.reset();
	}

	return true;
}
