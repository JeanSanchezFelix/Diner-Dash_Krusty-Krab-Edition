#include "Player.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em) : Entity(x, y, width, height, sprite){

    this->burger = new Burger(ofGetWidth()-110, 100, 100, 50);

    ofImage temp;

    // New sprite for the moving animation
    vector<ofImage> BobMovingAnim;
    temp.cropFrom(sprite, 6,114,32,38);
    BobMovingAnim.push_back(temp);
    temp.cropFrom(sprite, 46,113,29,39);
    BobMovingAnim.push_back(temp);
    temp.cropFrom(sprite, 87, 115,25,37);
    BobMovingAnim.push_back(temp);
    temp.cropFrom(sprite, 124,116,27,36);
    BobMovingAnim.push_back(temp);
    temp.cropFrom(sprite, 160,116,29,36);
    BobMovingAnim.push_back(temp);
    temp.cropFrom(sprite, 201,114,30,38);
    BobMovingAnim.push_back(temp);
    temp.cropFrom(sprite, 243,113,28,39);
    BobMovingAnim.push_back(temp);
    temp.cropFrom(sprite, 288,115,26,36);
    BobMovingAnim.push_back(temp);
    temp.cropFrom(sprite, 328,116,26,36);
    BobMovingAnim.push_back(temp);
    temp.cropFrom(sprite, 367,114,28,38);
    BobMovingAnim.push_back(temp);

    MovingAnim = new Animation(3, BobMovingAnim);

    // New sprite for the idle animation
    vector<ofImage> BobIdleAnim;
    temp.cropFrom(sprite, 5,10,30,36);
    BobIdleAnim.push_back(temp);
    temp.cropFrom(sprite, 39,10,30,36);
    BobIdleAnim.push_back(temp);
    temp.cropFrom(sprite, 74,10,30,36);
    BobIdleAnim.push_back(temp);
    temp.cropFrom(sprite, 108,10,30,36);
    BobIdleAnim.push_back(temp);
    temp.cropFrom(sprite, 144,11,30,35);
    BobIdleAnim.push_back(temp);
    temp.cropFrom(sprite, 180,12,30,34);
    BobIdleAnim.push_back(temp);
    temp.cropFrom(sprite, 216,12,30,34);
    BobIdleAnim.push_back(temp);
    temp.cropFrom(sprite, 252,11,30,35);
    BobIdleAnim.push_back(temp);
    temp.cropFrom(sprite, 291,11,30,35);
    BobIdleAnim.push_back(temp);

    IdleAnim = new Animation(5, BobIdleAnim);

    this->currentAnim = IdleAnim;

    this->entityManager = em;
    
}

void Player::tick(){

    currentAnim->tick();
    ofSetColor(256, 256, 256);
    
    // Checks if the player is moving to change the current animation respectively
    if (!idle) {
            currentAnim = MovingAnim;
    }
    else{
         currentAnim = IdleAnim;
    }

    // Checks if the 'e' key is pressed
    if (pressed) {
    StoveCounter* as = getActiveStove();
        if (as != nullptr){
            Item* item = as->getItem();
            if (item != nullptr){
                if(!as->isCooked()){
                    // "Cooks the item" and then shows the cooked item
                    as->tick();
                    as->showItem();
                }  
            }  
        }
    }
}

void Player::render(){
    BaseCounter *ac = getActiveCounter();
    if (ac != nullptr) {
        ac->showItem();
    }
    ofSetColor(256, 256, 256);
    ofImage currentFrame = currentAnim->getCurrentFrame();
    if (facing == "left") {
        currentFrame.mirror(false, true);
    }
    currentFrame.draw(x, y, width, height);
    burger->render();
}

void Player::keyPressed(int key){
    if(key == 'e'){

        // Boolean to keep track if the player has pressed the key
        pressed = true;

        BaseCounter* ac = getActiveCounter();
        StoveCounter* as = getActiveStove();

        // Checks if the item can be find and manipulated in the stove class
        if(as != nullptr){
            Item* item = as->getItem();
            if(item != nullptr){

                // Checks if the ingredient is already cooked when you press the second time
                if(as->isCooked()){

                    // Deactivates the tick() method, restarts the item to uncooked and shows said item.
                    pressed = false;
                    burger->addIngredient(item);
                    as->setNewIngredient();
                    as->showItem();
                }
            }
        }

        // Otherwise it just adds it to the vector of ingredients
        else if (ac != nullptr){
            Item* item = ac->getItem();
            if(item != nullptr){
                burger->addIngredient(item);
            }
        }
    }

    if(key == 'u'){
        BaseCounter* ac = getActiveCounter();
        if (ac != nullptr){
            Item* item = ac->getItem();
            if (item != nullptr){
                burger->removeIngredient();
            }
        }
    }

    // Moves the chef keeping in mind their respective boundaries.
    if (key == OF_KEY_LEFT){
        facing = "left";
        if(x >= 0){
            x-=speed;
            idle = false;
        }
    }

    if(key == OF_KEY_RIGHT){
        facing = "right";
        if(x + width <= ofGetWidth()){
            x+=speed;
            idle = false; 
            
        }
    }

}

BaseCounter* Player::getActiveCounter(){
    for(Entity* e:entityManager->entities){
        BaseCounter* c = dynamic_cast<BaseCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

// Creates a getter for the StoveCounters class
StoveCounter* Player::getActiveStove(){
    for(Entity* e:entityManager->entities){
        StoveCounter* c = dynamic_cast<StoveCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

void Player::keyReleased(int key) {
    if (key == OF_KEY_RIGHT || key == OF_KEY_LEFT) {
        idle = true;
    }
}

void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }

bool Player::isPressed(){return pressed; }