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

// Applies a limit to the amount of ingredients
void Burger::addIngredient(Item *item) { 
    if(ingredients.size() <= 12){
        ingredients.push_back(item);
    }
}

// Checks whether there is a ingredient already in the vector, and then removes it.
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

    // Hashmap containing the names of the different ingredients as keys and their price as values
    unordered_map<string, int> pricedItem = {  
        {"topBread", 1},
        {"patty", 4},
        {"cheese", 3},
        {"tomato", 2},
        {"lettuce", 2},
        {"botBread", 1}};


        // Iterates over the hashmap and then compares with the vector of the player's added ingredients.
        for (auto item : pricedItem){
            for (unsigned int i = 0; i < ingredients.size(); i++){

                // If it finds a matching ingredient it grabs the value and adds it to the price.
                if (item.first == ingredients[i]->getName()){
                    price += item.second;
                    ingredients_market_cost++;
                }
            }
        }

    return price - ingredients_market_cost;
}
