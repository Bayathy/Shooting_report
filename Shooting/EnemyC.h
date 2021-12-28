#pragma once
#include "Enemy.h"
class EnemyC :
    public Enemy
{
    double phase;

public:
    EnemyC();
    ~EnemyC();

    void init();
    void update();
    void draw();
    void drawExplosion();
};

