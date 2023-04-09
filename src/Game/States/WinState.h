#pragma once
#include "State.h"


class WinState: public State{

    private:
        ofImage win_screen;


    public: 
        WinState();
        void reset();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void keyReleased(int key);









};