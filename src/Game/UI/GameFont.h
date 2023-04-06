#pragma once

#include "ofMain.h"


class GameFont{

    private:
        ofTrueTypeFont font; 
        int size;
        string fontName;
        double xPos;
        double yPos;
        string text;

    public:

    GameFont();
    GameFont(ofTrueTypeFont, string, int);
    void loadFont();
    void render(string, double, double);
    ofTrueTypeFont& getFont();
};





