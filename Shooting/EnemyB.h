#pragma once
#include "Enemy.h"
class EnemyB :
    public Enemy
{
	double phase;

public:
	EnemyB();
	~EnemyB();

	void init();
	void update();
	void draw();
};

