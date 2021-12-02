#include "ShootingApp.h"
#include "FlyingObject.h"

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
}

void FlyingObject::draw()
{
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
