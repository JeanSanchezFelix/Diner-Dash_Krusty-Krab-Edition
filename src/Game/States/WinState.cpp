#include "WinState.h"

WinState::WinState(){
        win_screen.load("images/win_screen.png");
}
void WinState::tick() {
}
void WinState::render() {
        
    win_screen.draw(0,0,ofGetWidth(), ofGetHeight());

}

void WinState::keyPressed(int key){

}

void WinState::mousePressed(int x, int y, int button){
}

void WinState::keyReleased(int key){
}

void WinState::reset(){
    setFinished(false);
    setNextState("");
}