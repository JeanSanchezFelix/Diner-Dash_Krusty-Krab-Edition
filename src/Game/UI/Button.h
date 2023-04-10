#pragma once
#include "ofMain.h"

class Button {
    
    public:
        Button();
        Button(int, int, int, int, string);
        Button(int, int, int, int, ofImage);
        void mousePressed(int x, int y);
        void tick();
        void render(int xPos, int yPos, int width, int height);
        bool wasPressed();
        void reset();

    private:
        int xPos, yPos, width, height;
        ofImage buttonImage;
        ofImage clickedButtonImage;
        bool pressed = false;
        int pressedCounter = -1;
        string buttonText;
};