#include "ShootingApp.h"

void ShootingApp::init() {
	//App::init();
	fighter.init();
	fos.push_back(&fighter);
	for (size_t i = 0; i < N_ENEMY_A; i++)
	{
		enemyA[i].init();
		fos.push_back(&enemyA[i]);
	}
	for (size_t i = 0; i < N_MISSILE; i++)
	{
		fighter.loadMissile(&missile[i]);
		fos.push_back(&missile[i]);
	}
}

void ShootingApp::cleanup() {
	//App::cleanup();
	for (size_t i = 0; i < fos.size(); i++)
	{
		fos[i]->cleanup();
	}
	fos.clear();
}

void ShootingApp::update() {
	//App::update();
	for (size_t i = 0; i < fos.size(); i++)
	{
		if (fos[i]->status & FlyingObject::ACTIVE)
				fos[i]->update();
	}
}

void ShootingApp::draw() {
	//App::draw();
	for (size_t i = 0; i < fos.size(); i++)
	{
		if (fos[i]->status & FlyingObject::ACTIVE)
				fos[i]->draw();
	}
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
	case VK_SPACE:
		fighter.shoot();
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