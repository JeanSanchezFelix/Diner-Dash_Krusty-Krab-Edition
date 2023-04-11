#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Dinner Dash (Krusty Krab edition)");
	//States
	menuState = new MenuState();
    gameState = new GameState(); 
    loseState = new LoseState(); //this is something i need to fix
	winState = new WinState();
	pauseState = new PauseState();
	previewState = new PreviewState();
	
	// Initial State
	currentState = menuState;

	
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
				SecondSound.load("Spongebob_Bubbles_Sound.wav");
				SecondSound.play();
				currentState = menuState;
				sound.load("Spongebob_Goo_Lagoon.wav");
				sound.setLoop(true);
				sound.play();
			}else if(currentState->getNextState() == "Game"){
				SecondSound.load("Spongebob_Bubbles_Sound.wav");
				SecondSound.play();
				currentState = gameState;
				sound.load("Spongebob_Jellyfish_Fields.wav");
				sound.setLoop(true);
				sound.play();
			
			}else if(currentState->getNextState() == "Lose"){
				currentState = loseState;
				sound.load("Spongebob_Steel_Sting.wav");
				sound.setLoop(false);
				sound.play();
				SecondSound.load("Oh_Brother_this_Guy_Stinks.wav");
				SecondSound.setLoop(false);
				SecondSound.play();


			}else if(currentState->getNextState() == "Win"){
				currentState = winState;
				sound.load("Ocean_Man_Spongebob.wav");
				sound.setLoop(true);
				sound.play();

			}else if(currentState->getNextState() == "Pause"){
				SecondSound.load("Retro_Pause_Sound.wav");
				SecondSound.setLoop(false);
				SecondSound.play();
				currentState = pauseState;
				sound.load("Spongebob_Puka_A.wav");
				sound.setLoop(true);
				sound.play();
			}else if(currentState->getNextState() == "Preview"){
				SecondSound.load("Spongebob_Bubbles_Sound.wav");
				SecondSound.play();
				currentState = previewState;
				sound.load("Spongebob_Tip_Top_Polka.wav");
				sound.setLoop(true);
				sound.play();
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

