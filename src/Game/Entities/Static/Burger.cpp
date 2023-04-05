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
    ingredients.clear(); // changed from ingredients.empty()
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
bool Burger::equals(Burger* paramBurger){ // player burger 
    vector<Item*> target = this->getIngredients();
    vector<Item*> param = paramBurger->getIngredients();
    int tarCheese=0;
    int tarPatty=0;
    int tarTomato=0;
    int tarLettuce=0;

    int parCheese=0;
    int parPatty=0;
    int parTomato=0;
    int parLettuce=0;


    if(!(this->getIngredients()[1] == paramBurger->getIngredients()[1] && 
    this->getIngredients()[this->getIngredients().size()-1] == paramBurger->getIngredients()[paramBurger->getIngredients().size()-1]))
        return false;

    for(int i = 0; i<target.size(); i++){
        if(target[i]->getName() == "lettuce"){
            tarLettuce++;
        }
        else if(target[i]->getName() == "patty"){
            tarPatty++;
       }
        else if(target[i]->getName() == "tomato"){
            tarTomato++;
       }
        else if(target[i]->getName() == "cheese"){
            tarCheese++;
       }


    }

    for(int i = 0; i<param.size(); i++){
        if(param[i]->getName() == "lettuce"){
            parLettuce++;
        }
        else if(param[i]->getName() == "patty"){
            parPatty++;
       }
        else if(param[i]->getName() == "tomato"){
            parTomato++;
       }
        else if(param[i]->getName() == "cheese"){
            parCheese++;
       }


    }

    if(!(tarCheese == parCheese)){
        return false;
    }
    if(!(tarPatty == parPatty)){
        return false;
    }
    if(!(tarTomato == parTomato)){
        return false;
    }
    if(!(tarLettuce == parLettuce)){
        return false;
    }
    else{return true;}
}

// command shift p then reload window