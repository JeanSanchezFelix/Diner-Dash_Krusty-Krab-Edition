#pragma once

#include "Item.h"
#include "BaseCounter.h"

class BaseStove: public BaseCounter {
    private:
        Item *item;
        int stoveTimer = 1000;
        bool cooked = false;
  
    public:
        BaseStove(int x, int y, int width, int height, Item* item, ofImage sprite);
        virtual void showItem();
        void cookItem();
        void tick();

};

