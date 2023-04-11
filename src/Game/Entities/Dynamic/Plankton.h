#pragma once
#include "Client.h"
#include "Burger.h"
#include "Entity.h"

class Plankton: public Client{

    private: 
        Client* client;

    public:
        Plankton(int x, int y, int width, int height, ofImage sprite, Burger* burger);
        bool isPlankServed = false;
        virtual int serve(Burger*);

        bool getPlankServed(){
            return isPlankServed;
        }

};