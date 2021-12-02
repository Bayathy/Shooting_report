#include "ShootingApp.h"

void ShootingApp::init() {
	App::init();
	fighter.init();
}

void ShootingApp::cleanup() {
	App::cleanup();
	fighter.cleanup();
}

void ShootingApp::update() {
	App::update();
	fighter.update();
}

void ShootingApp::draw() {
	App::draw();
	fighter.draw();
}

void ShootingApp::keyDown(WPARAM key) {
	switch (key)
	{
	case VK_LEFT:
		fighter.move(Fighter::LEFT);
		break;
	case VK_RIGHT:
		fighter.move(Fighter::RIGHT);
		break;
	case VK_UP:
		fighter.move(Fighter::FORE);
		break;
	case VK_DOWN:
		fighter.move(Fighter::BACK);
		break;
	default:
		break;
	}
}

void ShootingApp::keyUp(WPARAM key) {
	switch (key)
	{
	case VK_LEFT:
		fighter.stop(Fighter::LEFT);
		break;
	case VK_RIGHT:
		fighter.stop(Fighter::RIGHT);
		break;
	case VK_UP:
		fighter.stop(Fighter::FORE);
		break;
	case VK_DOWN:
		fighter.stop(Fighter::BACK);
		break;
	default:
		break;
	}
}