#pragma once
#include <Windows.h>

class Score
{
	int score;
public:
	Score();
	void init();
	void add(int point);
	void draw(int x, int y);
};


