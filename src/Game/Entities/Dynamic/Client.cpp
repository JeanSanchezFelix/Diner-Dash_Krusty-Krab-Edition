#include "Client.h"
Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
    
}
Client::~Client(){
    delete burger;
}
void Client::render(){
    ofSetColor (255,255,255);
    burger->render();
    ofSetColor(255,patience,patience);
    sprite.draw(x, y, width, height);
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
    if(burger->getIngredients().size()==0){
        return 0;
    }
    if(nextClient==nullptr){
        return -1;
    }
    if(this->getBurger()->equals(burger)){
        isLeaving = true;
        return burger->getPrice();
    }
    return nextClient->serve(burger);
}