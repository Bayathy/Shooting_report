#pragma once
#include "App.h"
#include "Fighter.h"

class ShootingApp :public App
{
    private:
        Fighter fighter;
        void init();
        void cleanup();
        void update();
        void draw();
        void keyDown(WPARAM key);
        void keyUp(WPARAM key);
};

