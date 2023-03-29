#pragma once

#include "State.h"
#include "Button.h"

class MenuState : public State {
private:
	ofImage menuImage;
	ofImage startImg;
	Button *startButton;
	ofTrueTypeFont font;


public:
	MenuState();
	MenuState(ofTrueTypeFont* font);
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
