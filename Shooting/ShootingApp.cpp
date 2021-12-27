#include "ShootingApp.h"

void ShootingApp::init() {
	Sound::getInstance()->registerFile(TEXT("bomb2.mp3"), TEXT("explosion"));
	Sound::getInstance()->registerFile(TEXT("shot1.mp3"), TEXT("shoot"));
	Sound::getInstance()->registerFile(TEXT("menuettm.mp3"), TEXT("bgm"));
	Sound::getInstance()->request(TEXT("bgm"));

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
		fighter.loadMissileA(&missileA[i]);
		fighter.loadMissileB(&missileB[i]);

		missiles.push_back(&missileA[i]);
		missiles.push_back(&missileB[i]);
		fos.push_back(&missileB[i]);
		fos.push_back(&missileA[i]);
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
	Sound::getInstance()->cleanup();
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
	Sound::getInstance()->play();
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
		fighter.shootA();
		break;
	case 0x56: //Vキー
		fighter.shootB();
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