#include "MenuState.h"

MenuState::MenuState() {
	// New image button to start the game
	startImg.load("images/ImgButton.png");
	startButton = new Button(ofGetWidth()-320,ofGetHeight()-302, ofGetWidth()/2.5, ofGetHeight()/2.5, startImg);
	menuImage.load("images/MenuBG.jpg");

	krustyFont = new GameFont(loadingFont, "Krabby Patty.ttf", 12);	

}

void MenuState::tick() {	
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Preview");
		setFinished(true);

	}
}
void MenuState::render() {
	ofSetColor(256, 256, 256);
	menuImage.draw(0,0, ofGetWidth(), ofGetHeight());
	startButton->render(ofGetWidth()-320,ofGetHeight()-302, ofGetWidth()/2.5, ofGetHeight()/2.5);

	// Instructions for the key presses 
	ofSetColor(0);
	krustyFont->render("Use  '<-'  and  '->'  to  Navigate", ofGetWidth()/2 - 340 , ofGetHeight()/2 + 150);
	krustyFont->render("Press  's'  to  serve  the  Burger", ofGetWidth()/2 - 340 , ofGetHeight()/2 + 200);
	krustyFont->render("Press  'e'  to  pickup  Ingredients", ofGetWidth()/2 - 340 , ofGetHeight()/2 + 250);
	krustyFont->render("Press  'u'  to  remove  Ingredients", ofGetWidth()/2 - 340 , ofGetHeight()/2 + 300);
	krustyFont->render("Click  below  to  start  the  game", ofGetWidth()/2 + 132, ofGetHeight()/2 + 87);

}

void MenuState::keyPressed(int key){
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);

}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}