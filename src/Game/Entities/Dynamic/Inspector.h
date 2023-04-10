#pragma once
#include "Client.h"
#include "Burger.h"
#include "Entity.h"
class Inspector: public Client{
    private:
        Client* client;
    public:
        // Inspector(){};
        Inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger);
        // virtual ~Inspector();
        // void tick();
        // void render();
        bool isLeavingInspec = false;



};