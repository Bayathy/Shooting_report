#include "ShootingApp.h"

void ShootingApp::init() {
	App::init();
	fighter.init();
	fos.push_back(&fighter);
	for (size_t i = 0; i < N_ENEMY_A; i++)
	{
		enemyA[i].init();
		fos.push_back(&enemyA[i]);
	}
	for (size_t i = 0; i < N_MISSILE; i++)
	{
		fos.push_back(&missile[i]);
	}
}

void ShootingApp::cleanup() {
	App::cleanup();
	for (size_t i = 0; i < fos.size(); i++)
	{
		fos[i]->cleanup();
	}
	fos.clear();
}

void ShootingApp::update() {
	App::update();
	for (int i = 0; i < N_ENEMY_A; i++)
		enemyA[i].update();
	for (int i = 0; i < N_MISSILE; i++)
		missile[i].update();
	fighter.update();
}

void ShootingApp::draw() {
	App::draw();
	for (int i = 0; i < N_ENEMY_A; i++)
		enemyA[i].draw();
	for (int i = 0; i < N_MISSILE; i++)
		missile[i].draw();
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