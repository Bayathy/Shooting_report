#include "Score.h"
#include "ShootingApp.h"

Score::Score() : score(0)
{
}

void Score::init()
{
	score = 0;
}

void Score::add(int point)
{
	score += point;
}

void Score::draw(int x, int y)
{
	TCHAR c[64];
	wsprintf(c,TEXT("score = %d"), score);
	TextOut(App::hDC, x, y, c, lstrlen(c));
}
