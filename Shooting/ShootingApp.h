#pragma once
#include "App.h"
#include "Fighter.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "EnemyC.h"
#include "MissileA.h"
#include "MissileB.h"
#include "Score.h"
#include "Sound.h" 

#include <vector>

#define N_ENEMY_A 2
#define N_ENEMY_B 3
#define N_ENEMY_C 5
#define N_MISSILE 10


class ShootingApp :public App
{
    private:
        Fighter fighter;
        EnemyA enemyA[N_ENEMY_A];
        EnemyB enemyB[N_ENEMY_B];
        EnemyC enemyC[N_ENEMY_C];
        MissileA missileA[N_MISSILE];
        MissileB missileB[N_MISSILE];

        std::vector<FlyingObject*> fos;
        std::vector<Enemy*> enemies;
        std::vector<Missile*> missiles;
        Score score;

        void init();
        void cleanup();
        void update();
        void draw();
        void keyDown(WPARAM key);
        void keyUp(WPARAM key);
};

