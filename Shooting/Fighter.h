#pragma once
#include "FlyingObject.h"
#include "Missile.h"
#include <vector>

class Fighter : public FlyingObject
{
	unsigned int dir;		// Œ»İ‚ÌˆÚ“®•ûŒü

public:

	enum DIRECTION {
		STOP = 0,
		FORE = 1,
		BACK = 2,
		LEFT = 4,
		RIGHT = 8
	};

	std::vector<Missile*> missiles;

	Fighter();
	~Fighter();

	void loadMissile(Missile* m);
	void shoot();
	void init();
	void cleanup();
	void update();
	void draw();

	void move(DIRECTION dir);
	void stop(DIRECTION dir);
};

