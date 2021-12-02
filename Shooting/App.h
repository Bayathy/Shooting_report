#pragma once
#pragma once
#include <Windows.h>
#include <random>

class App
{
	static std::mt19937 mt;
public:
	static HWND hWnd;
	static HDC hDC;
	static double rand();

	App();
	virtual ~App();

	virtual void init();
	virtual void cleanup();
	virtual void update();
	virtual void draw();
	virtual void keyDown(WPARAM key);
	virtual void keyUp(WPARAM key);
};
