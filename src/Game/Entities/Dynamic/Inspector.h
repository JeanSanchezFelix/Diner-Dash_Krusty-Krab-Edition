#pragma once
#include "Client.h"
#include "Burger.h"
#include "Entity.h"
class Inspector: public Client{
    private:
        Client* client;
    public:
        Inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger);
        bool isLeavingInspec = false;



};