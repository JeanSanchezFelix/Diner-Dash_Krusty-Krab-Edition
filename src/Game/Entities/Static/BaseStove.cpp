#include "BaseStove.h"

BaseStove::BaseStove(int x, int y, int width, int height, Item* item, ofImage sprite) : BaseCounter(x, y, width, height, item, sprite){
    this->item = item;
    // this->cokedSprite = cokedSprite;
}

void BaseStove::cookItem(){

    if (item != nullptr && cooked){
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);

    }


}

void BaseStove::showItem(){
    if (item != nullptr){
        item->rawSprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}

void BaseStove::tick(){
    stoveTimer--;
    if(stoveTimer == 0){
        cooked = true;
    }
}


