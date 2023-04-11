#pragma once
#include "State.h"
#include "Button.h"
#include "GameState.h"

class LoseState: public State{

    private:
        GameState *game = new GameState();
        ofImage game_over_screen;
        ofImage restartButtonImg;
        Button* restartButton;
        ofImage quitButtonImg;
        Button* quitButton;

    public: 
        LoseState();
        void reset();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void keyReleased(int key);









};