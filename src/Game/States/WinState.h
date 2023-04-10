#pragma once
#include "State.h"
#include "Button.h"
// #include "GameState.h"


class WinState: public State{

    private:
        // GameState* game;
        ofImage win_screen;
        ofImage restartButtonImg;
        Button* restartButton;
        ofImage quitButtonImg;
        Button* quitButton;

    public: 
        WinState();
        void reset();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void keyReleased(int key);









};