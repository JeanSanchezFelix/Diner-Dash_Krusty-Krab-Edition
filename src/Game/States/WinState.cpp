#include "WinState.h"

WinState::WinState(){
//     gamestate = new GameState();
}
void WinState::tick() {
    // gamestate->tick();
}
void WinState::render() {

    // gamestate->render();
}

void WinState::keyPressed(int key){
    // gamestate->keyPressed(key);
}

void WinState::mousePressed(int x, int y, int button){
}

void WinState::keyReleased(int key){
}

void WinState::reset(){
    setFinished(false);
    setNextState("");
}