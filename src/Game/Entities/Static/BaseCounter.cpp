//
// Created by joshu on 11/3/2020.
//

#include "BaseCounter.h"

BaseCounter::BaseCounter(int x, int y, int width, int height,Item* item, ofImage sprite) : Entity(x, y, width, height, sprite){
    this->item = item;
}

Item* BaseCounter::getItem(){
    return item;
}

void BaseCounter::showItem(){
    if (item != nullptr){
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}
