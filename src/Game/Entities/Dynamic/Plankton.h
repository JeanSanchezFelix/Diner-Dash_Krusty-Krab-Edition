#pragma once
#include "Client.h"
#include "Burger.h"
#include "Entity.h"

class Plankton: public Client{

    public:
        Plankton(int x, int y, int width, int height, ofImage sprite, Burger* burger);
        



};