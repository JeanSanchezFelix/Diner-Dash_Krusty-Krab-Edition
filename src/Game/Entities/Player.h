#pragma once
#include "Animation.h"
#include "Burger.h"
#include "EntityManager.h"
#include "BaseCounter.h"
#include "StoveCounter.h"
class Player: public Entity{

    private:
        int speed = 15;
        string facing = "right";
        int idleTimer = 0;
        bool idle = true;
        bool pressed = false;

        Animation *currentAnim;
        Animation *IdleAnim;
        Animation *MovingAnim;

        Burger *burger;
        EntityManager* entityManager;
    public:
        Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void mousePressed(int, int, int);
        void setFacing(string);
        BaseCounter* getActiveCounter();
        StoveCounter* getActiveStove();
        Burger* getBurger(){ return burger;
        }
        bool isPressed();
};