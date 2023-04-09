#pragma once
#include "State.h"


class PauseState: public State{

    private:
        ofImage pause_screen;
        ofImage Bubble_Bass;
        GameFont *krustyFont_H;
        GameFont *krustyFont;
        ofTrueTypeFont loadingFont;

    public: 
        PauseState();
        void reset();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void keyReleased(int key);
};