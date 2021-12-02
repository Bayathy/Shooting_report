#pragma once
#include "Enemy.h"

class EnemyA : public Enemy{
	double phase;

public:
	EnemyA();
	~EnemyA();

	void init();
	void update();
	void draw();
};


