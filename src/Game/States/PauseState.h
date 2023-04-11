#pragma once
#include "State.h"
#include "Button.h"


class PauseState: public State{

    private:
        ofImage pause_screen;
        ofImage Bubble_Bass;
        ofImage Plankton;
        GameFont *krustyFont_H;
        GameFont *krustyFont;
        ofTrueTypeFont loadingFont;

        ofImage playButtonImg;
        Button* playButton;



        ofImage quitButtonImg;
        Button* quitButton;

    public: 
        PauseState();
        void reset();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void keyReleased(int key);
};