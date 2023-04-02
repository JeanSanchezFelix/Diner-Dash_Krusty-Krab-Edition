#pragma once
#include "State.h"


class PauseState: public State{
    public: 
        PauseState();
        void reset();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void keyReleased(int key);
};