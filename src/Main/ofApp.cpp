#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Dinner Dash (Krusty Krab edition)");
	//States
	menuState = new MenuState();
    gameState = new GameState();
    // loseState = new LoseState(); this is something i need to fix
	// Initial State
	currentState = menuState;

	// Load font
	font.load("Krabby Patty.ttf", 56);
	
	// Sound
	sound.load("Spongebob_Goo_Lagoon.wav");
	sound.setLoop(true);
	sound.play();

}

//--------------------------------------------------------------
void ofApp::update(){
	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu"){
				currentState = menuState;
				sound.load("Spongebob_Goo_Lagoon.wav");
				sound.setLoop(true);
				sound.play();
			}else if(currentState->getNextState() == "Game"){
				currentState = gameState;
				sound.load("Spongebob_Jellyfish_Fields.wav");
				sound.setLoop(true);
				sound.play();
				if(player_left>=10){
					// currentState = loseState;
				}
			}
			currentState->reset();
		}
	}
		
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr)
		currentState->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr)
		currentState->keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}

ofTrueTypeFont& ofApp::getFont() {
    return font;
}
