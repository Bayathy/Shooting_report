#include "ShootingApp.h"

void ShootingApp::init() {
	fighter.init();
	fos.push_back(&fighter);
	for (size_t i = 0; i < N_ENEMY_A; i++)
	{
		enemyA[i].init();
		enemies.push_back(&enemyA[i]);
		fos.push_back(&enemyA[i]);
	}
	for (size_t i = 0; i < N_ENEMY_B; i++)
	{
		enemyB[i].init();
		enemies.push_back(&enemyB[i]);
		fos.push_back(&enemyB[i]);
	}
	for (size_t i = 0; i < N_MISSILE; i++)
	{
		fighter.loadMissile(&missile[i]);
		missiles.push_back(&missile[i]);
		fos.push_back(&missile[i]);
	}
	score.init();
}

void ShootingApp::cleanup() {
	//App::cleanup();
	for (size_t i = 0; i < fos.size(); i++)
	{
		fos[i]->cleanup();
	}
	fos.clear();
	enemies.clear();
	missiles.clear();
}

void ShootingApp::update() {
	//App::update();
	for (size_t i = 0; i < fos.size(); i++)
	{
		if (fos[i]->status & FlyingObject::ACTIVE)
				fos[i]->update();
	}

	for (size_t i = 0; i < enemies.size(); i++) {
		if (!(enemies[i]->status & FlyingObject::ACTIVE)) // アクティブでなければ
			continue; // 判定しない
		for (size_t j = 0; j < missiles.size(); j++) // すべてのミサイルについて
			if (enemies[i]->checkCollision(missiles[j])) // 衝突していたら
				score.add(enemies[i]->point);
		enemies[i]->checkCollision(&fighter);
	}

	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (!enemies[i]->status)
			enemies[i]->init();

		if (!fighter.status) {
			cleanup();
			init();
		}
	}
}

void ShootingApp::draw() {
	//App::draw();
	for (size_t i = 0; i < fos.size(); i++)
	{
		if (fos[i]->status & FlyingObject::ACTIVE)
				fos[i]->draw();
	}
	score.draw(100 ,100);
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