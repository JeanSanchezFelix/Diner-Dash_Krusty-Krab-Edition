//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"

Player *Restaurant::getPlayer() { return player; }
void Restaurant::setPlayer(Player *player) { this->player = player; }

Restaurant::Restaurant() {
    floor.load("images/wood_floor.jpg");
    cockroach.load("images/cockroach_eating_burger.png");
    krusty_krab_background.load("images/krusty_krab_background.png");
    blue_orchid.load("images/Orchid.png");
    pink_orchid.load("images/pink_orchid.png");
    client_background.load("images/client_background.png");
    money_background.load("images/money_background.png");
    krustyFont = new GameFont(loadingFont, "Krabby Patty.ttf", 12);	
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/SpongeBob_Sprite_Sheet.png");
    this->player = new Player(0, 605, 100, 100, chefPlayerImage, entityManager);    
    initItems();
    initCounters();
    initClients();
    generateClient();

}
void Restaurant::initItems(){
    ofImage burgerSpriteSheet, rawBurgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, rawPattyImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    rawBurgerSpriteSheet.load("images/raw_burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    rawPattyImg.cropFrom(rawBurgerSpriteSheet,30, 134, 103, 48); // Raw patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    patty = new Item(burgerImg, rawPattyImg, "patty");
    botBread = new Item(botBreadImg, "botBread");
    topBread = new Item(topBreadImg, "topBread");
}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    emptyCounterImg.cropFrom(counterSheet,0,245,30,43);//Empty
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity( new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth*2,yOffset-1, counterWidth, 102, patty, stoveCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset-1, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset-1, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));

    entityManager->addEntity(new BaseCounter(counterWidth*8,yOffset-1, counterWidth, 102, nullptr, emptyCounterImg));
}
void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
    
}
void Restaurant::tick() {
    ticks++;
    if(ticks % 400 == 0){
        generateClient();
    }
    player->tick();
    entityManager->tick();

}


void Restaurant::generateClient(){
    vector<Item*> tempItems {patty, cheese, tomato, lettuce};
    Burger* b = new Burger(72, 100, 50, 25);

    b->addIngredient(botBread);
    for (int i = 0; i < ofRandom(3); i++){
        b->addIngredient(tempItems[ofRandom(tempItems.size())]);
    }
    b->addIngredient(topBread);

    entityManager->addClient(new Client(0, 50, 64, 72,people[ofRandom(8)], b));
}
void Restaurant::render() {
    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    krusty_krab_background.draw(0,0,ofGetWidth(), ofGetHeight()-200);
    cockroach.draw(ofGetWidth()-510, ofGetHeight()-520, 230, 230);
    blue_orchid.draw(ofGetWidth()-144, ofGetHeight()-482, 100 , 100);
    pink_orchid.draw(ofGetWidth()-642, ofGetHeight()-588, 100 , 100);
    client_background.draw(ofGetWidth()-150, ofGetHeight()-756.5, 135, 200);
    client_background.draw(-27.5, -1, 160, 455);
    money_background.draw(ofGetWidth()/2 - 63, 2.5, 125,30);
    player->render();
    entityManager->render();
    ofSetColor(0, 100, 0);
	krustyFont->render("Money: " + to_string(money), ofGetWidth()/2 - 36, 23.5);
    ofSetColor(256, 256, 256);


}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        money += entityManager->firstClient->serve(player->getBurger());
    }
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's'){
        serveClient();
    }
}
