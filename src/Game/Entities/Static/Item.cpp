//
// Created by joshu on 11/4/2020.
//

#include "Item.h"

Item::Item(ofImage sprite, string name){
    this->name = name;
    this->sprite = sprite;

}

Item::Item(ofImage sprite, ofImage rawSprite, string name){
    this->name = name;
    this->sprite = sprite;
    this->rawSprite = rawSprite;

}

string Item::getName(){ 
    return name; 
}