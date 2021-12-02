#pragma once
#include "App.h"
#include "Fighter.h"
#include "EnemyA.h"
#include "Missile.h"
#include <vector>

#define N_ENEMY_A 2
#define N_MISSILE 10


class ShootingApp :public App
{
    private:
        Fighter fighter;
        EnemyA enemyA[N_ENEMY_A];
        Missile missile[N_MISSILE];
        std::vector<FlyingObject*> fos;
        void init();
        void cleanup();
        void update();
        void draw();
        void keyDown(WPARAM key);
        void keyUp(WPARAM key);
};

