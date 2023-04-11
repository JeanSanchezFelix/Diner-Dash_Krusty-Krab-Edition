//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "StoveCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "GameFont.h" 
#include "ofMain.h"
#include "Inspector.h"
#include "Client.h"
#include "Plankton.h"

class Restaurant {
    private:
        
        Player* player;
        EntityManager* entityManager;
        ofTrueTypeFont loadingFont;
        GameFont *krustyFont;
        int ticks = 0;
        unordered_map<Item*, int> pricedItem;
        std::vector<ofImage> people;
        int money = 0;
        int ClientRandomizer=0;
        bool plankServed = false;
        Burger* b;
        Plankton* plankton;

        
    public:
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* patty;
        Item* botBread;
        Item* topBread;
        ofImage floor;
        ofImage cockroach;
        ofImage krusty_krab_background;
        ofImage blue_orchid;
        ofImage pink_orchid;
        ofImage burger_background;
        ofImage client_background;
        ofImage money_background;
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        void keyReleased(int key);
        void restartBurger();
        bool getPlankServed();
        



        
        int getMoney(){return money;}
        int setMoney(int num){return money = num;}
        int restaurant_getPL(){
            return entityManager->getPL();
        }
        int restSetPL(int num){
            return entityManager->setPL(num);
        }
        bool setPlankStatus(bool status){
		    return plankServed = status;
	    }
	    bool getPlankStatus(){return plankServed;}

        auto getAllLeavingClients(bool leavingClient){
            return entityManager->removeAllClients(leavingClient);

        }
        
};
