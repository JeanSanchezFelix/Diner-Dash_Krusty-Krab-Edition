#include "MenuState.h"

MenuState::MenuState() {
	startImg.load("images/ImgButton.png");
	startButton = new Button(ofGetWidth()-320,ofGetHeight()-302, ofGetWidth()/2.5, ofGetHeight()/2.5, startImg);
	// string text = "Start";
	// startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Start");
	menuImage.load("images/MenuBG.jpg");	

}

void MenuState::tick() {	
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	ofSetColor(256, 256, 256);
	// ofTrueTypeFont& font = getFont();
	// font.drawString("Font String", 100, 100);
	menuImage.draw(0,0, ofGetWidth(), ofGetHeight());
	startButton->render();

	ofSetColor(0);
	ofDrawBitmapString("Use '<-' and '->' to Navigate", ofGetWidth()/2 - 335 , ofGetHeight()/2 + 150);
    ofDrawBitmapString("Press 's' to serve the Burger", ofGetWidth()/2 - 335 , ofGetHeight()/2 + 200);
	ofDrawBitmapString("Press 'e' to pickup Ingredients", ofGetWidth()/2 - 335 , ofGetHeight()/2 + 250);
	ofDrawBitmapString("Press 'u' to remove Ingredients", ofGetWidth()/2 - 335 , ofGetHeight()/2 + 300);
	ofDrawBitmapString("Click below to start the game", ofGetWidth()/2 + 133, ofGetHeight()/2 + 85);
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