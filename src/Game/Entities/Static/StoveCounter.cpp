#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite) : BaseCounter(x, y, width, height, item, sprite){
    this->item = item;
}

void StoveCounter::showItem(){

    // Draws respectively if the item is cooked or not.
    if (item != nullptr && !cooked){
        item->rawSprite.draw(x+width/2 -25, y-30, 50, 30);
    }

    else if(item != nullptr && cooked){
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}

void StoveCounter::tick(){

    // When the timer reaches 0, it changes the value of cooked to true, and restarts the timer.
    stoveTimer--;
    if(stoveTimer == 0){
        cooked = true;
        stoveTimer = 200;
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
