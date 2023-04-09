#include "LoseState.h"

LoseState::LoseState() {
    game_over_screen.load("images/game_over_screen.jpg");

}
void LoseState::tick() {

}
void LoseState::render() {
    game_over_screen.draw(0,0,ofGetWidth(), ofGetHeight());

}

void LoseState::keyPressed(int key){

}

void LoseState::mousePressed(int x, int y, int button){
}

void LoseState::keyReleased(int key){
}

void LoseState::reset(){
    setFinished(false);
    setNextState("");
}