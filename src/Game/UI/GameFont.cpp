#include "GameFont.h"


GameFont::GameFont(ofTrueTypeFont font, string fontName, int size){
    this->font = font;
    this->fontName = fontName;
    this->size = size;
    
}

void GameFont::loadFont(){
}

void GameFont::render(string text, double xPos, double yPos){
    font.load(fontName, size);
    font.drawString(text, xPos,yPos);
}

ofTrueTypeFont& GameFont::getFont(){
    return font;
}

    

