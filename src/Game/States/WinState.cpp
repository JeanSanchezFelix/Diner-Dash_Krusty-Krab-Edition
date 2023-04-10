#include "WinState.h"

WinState::WinState(){
    restartButtonImg.load("images/Restart_Button.png");
    quitButtonImg.load("images/Quit_Button.png");
    quitButton = new Button(ofGetWidth()-292,ofGetHeight()-725, ofGetWidth()/3, ofGetHeight()/5 ,quitButtonImg );
    restartButton = new Button(ofGetWidth()-292, ofGetHeight()-550,ofGetWidth()/3, ofGetHeight()/5, restartButtonImg);
    win_screen.load("images/win_screen.png");
    
    



}
void WinState::tick() {
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
void WinState::render() {
        
    win_screen.draw(0,0,ofGetWidth(), ofGetHeight());
    restartButton->render(ofGetWidth()-292, ofGetHeight()-550,ofGetWidth()/3, ofGetHeight()/5);
    quitButton->render(ofGetWidth()-292,ofGetHeight()-725, ofGetWidth()/3, ofGetHeight()/5);
    


}

void WinState::keyPressed(int key){

}

void WinState::mousePressed(int x, int y, int button){
    restartButton->mousePressed(x,y);
    quitButton->mousePressed(x,y);
}

void WinState::keyReleased(int key){

}

void WinState::reset(){
    setFinished(false);
    setNextState("");
    restartButton->reset();
    quitButton->reset();
}