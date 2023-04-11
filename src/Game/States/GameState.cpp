#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick();
	if(restaurant->restaurant_getPL()>=10){
		setFinished(true);
		setNextState("Lose");

	}
	if(restaurant->getMoney()>=100){
		setFinished(true);
		setNextState("Win");	
	}

}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
	switch(key){
		case 'p':
			setFinished(true);
			setNextState("Pause");
			break;
	}
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
	restaurant->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
	restaurant->setMoney(0);
	restaurant->restSetPL(0);
	restaurant->getPeople().clear();
	// restaurant.Restaurant();

}