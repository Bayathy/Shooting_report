#pragma once
#include "Timer.h"
#include "Sound.h"

class FlyingObject
{
protected:
	double x;		// ���݂̈ʒu (pixel)
	double vx;		// ���݂̈ړ����x (pixel/s)
	double y;
	double vy;
	double radius;
	Timer mtimer;
	Timer etimer;
	Timer elapsed;	// �O���update����̌o�ߎ��Ԍv���p
public:
	unsigned int status;

	enum STATUS
	{
		ACTIVE = 1,
		COLLISION = 2
	};

	FlyingObject();
	virtual ~FlyingObject();       

	virtual void init();
	virtual void cleanup();
	virtual void update();
	virtual void draw();
	void drawExplosion();
	void drawDebug();
	bool checkCollision(FlyingObject* fo);
};

