#pragma once
#include "State.h"


class PreviewState: public State{

    private:
        ofImage preview_screen;
        ofImage Bubble_Bass;
        GameFont *krustyFont_H;
        GameFont *krustyFont;
        ofTrueTypeFont loadingFont;

    public: 
        PreviewState();
        void reset();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void keyReleased(int key);
};