//
// Created by joshu on 11/4/2020.
//
#pragma once

#include "ofMain.h"

class Item {    
public:
    Item(ofImage, string);
    Item(ofImage, ofImage, string);
    ofImage sprite;
    ofImage rawSprite;
    string name;
    string getName();  
};
