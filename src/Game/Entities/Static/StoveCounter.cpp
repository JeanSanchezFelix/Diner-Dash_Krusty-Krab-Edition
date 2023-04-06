#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite) : BaseCounter(x, y, width, height, item, sprite){
    this->item = item;
}

void StoveCounter::showItem(){

    // Draws respectively if the item is cooked or not.
    if (item != nullptr && !cooked){
        item->rawSprite.draw(x+width/2 -25, y-30, 50, 30); 

        ofSetColor(256, 256, 256);
        ofRectangle Progress_Bar_bg(ofGetWidth()/2 - 217.6, ofGetHeight()/2 + 168, 95, 9); // Progress Bar Background
        ofDrawRectRounded(Progress_Bar_bg, 10);

        ofSetColor(0,255,0);
        ofRectangle Progress_Bar(ofGetWidth()/2 - 217.6, ofGetHeight()/2 + 168, clock , 9); // Progress Bar 
        ofDrawRectRounded(Progress_Bar, 10);    

        ofSetColor(256, 256, 256);

    }

    else if(item != nullptr && cooked){
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);

        ofSetColor(0,255,0);
        ofRectangle Progress_Bar(ofGetWidth()/2 - 217.6, ofGetHeight()/2 + 168, 95, 9); // Progress Bar 
        ofDrawRectRounded(Progress_Bar, 10);

        ofSetColor(256, 256, 256);    
    }
}

void StoveCounter::tick(){

    // When the clock reaches the stove timer, it changes the value of cooked to true, and restarts the clock.
    clock++;
    if(clock == stoveTimer){
        cooked = true;
        clock = 0;
    }
}

bool StoveCounter::isCooked(){

    // Returns whether or not the the item is cooked.
    return cooked;
}

void StoveCounter::setNewIngredient(){

    // Setter that resets the ingredient to an uncooked state.
    cooked = false;
}

int StoveCounter::getStoveTimer(){
    return stoveTimer;
}

int StoveCounter::getClock(){return clock;}
