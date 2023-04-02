#include "PauseState.h"

PauseState::PauseState() {
//     gamestate = new GameState();
}
void PauseState::tick() {
    // gamestate->tick();
}
void PauseState::render() {
    // gamestate->render();
}

void PauseState::keyPressed(int key){
    // gamestate->keyPressed(key);
    switch(key){
        case 'm': 
            setFinished(true);
            setNextState("Menu");
            break;
        case 'g':
            setFinished(true);
            setNextState("Game");
            break;
        // case 'r':
            // resume shit
            // break;
    }
}

void PauseState::mousePressed(int x, int y, int button){

}

void PauseState::keyReleased(int key){
}

void PauseState::reset(){
    setFinished(false);
    setNextState("");
}