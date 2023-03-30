#include "LoseState.h"

LoseState::LoseState() {
//     gamestate = new GameState();
}
void LoseState::tick() {
    // gamestate->tick();
}
void LoseState::render() {
    // gamestate->render();
}

void LoseState::keyPressed(int key){
    // gamestate->keyPressed(key);
}

void LoseState::mousePressed(int x, int y, int button){
}

void LoseState::keyReleased(int key){
}

void LoseState::reset(){
    setFinished(false);
    setNextState("");
}