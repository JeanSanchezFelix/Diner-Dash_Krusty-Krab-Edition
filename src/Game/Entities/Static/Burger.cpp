//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height, int price){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->price = price;
}

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}

void Burger::removeIngredient() {
    if (!ingredients.empty()) {
    ingredients.pop_back();
    }
}


void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++;
    }
}

void Burger::clear(){
    ingredients.empty();
}

int Burger::getPrice(){
    price = 0;
    ingredients_market_cost = 0;

    unordered_map<string, int> pricedItem = {  
        {"topBread", 1},
        {"patty", 4},
        {"cheese", 3},
        {"tomato", 2},
        {"lettuce", 2},
        {"botBread", 1}};


        for (auto item : pricedItem){
            for (unsigned int i = 0; i < ingredients.size(); i++){
                if (item.first == ingredients[i]->getName()){
                    price += item.second;
                    ingredients_market_cost++;
                }
            }
        }

    return price - ingredients_market_cost;
}
bool Burger::equals(Burger* burger){

    for(int i = 0; i<burger.size(; i++){
        if(!burger[1] == ingredients[1] && burger[burger.size()-1] == ingredients[ingredients.size()-1]){
            return false;
        }
        
    }
    if(entitymanager->firstClient->getBurger()==burger){
        return true;
    }else{return false;}
}