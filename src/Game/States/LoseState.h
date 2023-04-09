#pragma once
#include "State.h"


class LoseState: public State{

    private:
        ofImage game_over_screen;

    public: 
        LoseState();
        void reset();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void keyReleased(int key);









};