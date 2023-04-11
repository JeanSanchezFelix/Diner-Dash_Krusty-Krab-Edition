#include "Plankton.h"

Plankton::Plankton(int x, int y, int width, int height, ofImage sprite, Burger* burger): Client(x, y, width, height, sprite, burger) {
    
}

int Plankton::serve(Burger* burger){
    if(burger->getIngredients().size()==0){
        return 0;
    }
    if(nextClient==nullptr){
        return -1;
    }
    if(this->getBurger()->equals(burger)){
        isLeaving = true;
        isPlankServed = true;
        return burger->getPrice();
    }
    return nextClient->serve(burger);
}