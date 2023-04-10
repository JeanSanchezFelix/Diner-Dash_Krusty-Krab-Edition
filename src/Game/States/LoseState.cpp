#include "LoseState.h"

LoseState::LoseState() {
    restartButtonImg.load("images/Restart_Button.png");
    quitButtonImg.load("images/Quit_Button.png");
    quitButton = new Button(ofGetWidth()-600,ofGetHeight()-380, ofGetWidth()/5, ofGetHeight()/7, quitButtonImg );
    restartButton = new Button(ofGetWidth()-750, ofGetHeight()-380,ofGetWidth()/5, ofGetHeight()/7, restartButtonImg);
    game_over_screen.load("images/game_over_screen.jpg");

}
void LoseState::tick() {
    restartButton->tick();
    quitButton->tick();
    if(restartButton->wasPressed()){
        setNextState("Game");
		setFinished(true);
    }
    else if(quitButton->wasPressed()){
        setNextState("Menu");
		setFinished(true);
    }
}
void LoseState::render() {
    game_over_screen.draw(0,0,ofGetWidth(), ofGetHeight());
    restartButton->render(ofGetWidth()-780, ofGetHeight()-380,ofGetWidth()/5, ofGetHeight()/7);
    quitButton->render(ofGetWidth()-600,ofGetHeight()-380, ofGetWidth()/5, ofGetHeight()/7);
    

}

void LoseState::keyPressed(int key){

}

void LoseState::mousePressed(int x, int y, int button){
    restartButton->mousePressed(x,y);
    quitButton->mousePressed(x,y);
}

void LoseState::keyReleased(int key){
}

void LoseState::reset(){
    setFinished(false);
    setNextState("");
    restartButton->reset();
    quitButton->reset();
}