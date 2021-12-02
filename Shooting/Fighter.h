#pragma once
#include "FlyingObject.h"

class Fighter : public FlyingObject
{
	unsigned int dir;		// ���݂̈ړ�����

public:
	enum DIRECTION {
		STOP = 0,
		FORE = 1,
		BACK = 2,
		LEFT = 4,
		RIGHT = 8
	};

	Fighter();
	~Fighter();

	void init();
	void cleanup();
	void update();
	void draw();

	void move(DIRECTION dir);
	void stop(DIRECTION dir);
};

