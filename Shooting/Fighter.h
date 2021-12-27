#pragma once
#include "FlyingObject.h"
#include "Missile.h"
#include <vector>

class Fighter : public FlyingObject
{
	unsigned int dir;		// åªç›ÇÃà⁄ìÆï˚å¸

public:

	enum DIRECTION {
		STOP = 0,
		FORE = 1,
		BACK = 2,
		LEFT = 4,
		RIGHT = 8
	};

	std::vector<Missile*> Amissiles;
	std::vector<Missile*> Bmissiles;

	Fighter();
	~Fighter();

	void loadMissileA(Missile* m);
	void loadMissileB(Missile* m);

	void shootA();
	void shootB();
	void init();
	void cleanup();
	void update();
	void draw();

	void move(DIRECTION dir);
	void stop(DIRECTION dir);
};

