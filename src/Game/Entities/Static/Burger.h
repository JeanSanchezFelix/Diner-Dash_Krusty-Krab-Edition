//
// Created by joshu on 11/4/2020.
//
#pragma once

#include "Entity.h"
#include "Item.h"

class Burger {
  private:
    int x, y, width, height;
    int price = 0;
    int ingredients_market_cost = 0;
    vector<Item *> ingredients;

  public:
    Burger(int, int, int, int);
    Burger(int, int, int, int, int);
    void addIngredient(Item *item);
    void removeIngredient();
    void render();
    void clear();
    int getPrice();
    vector<Item *> getIngredients(){return ingredients;}
    void setY(int y) {this->y = y;}
    bool equals(Burger *burger);
};
