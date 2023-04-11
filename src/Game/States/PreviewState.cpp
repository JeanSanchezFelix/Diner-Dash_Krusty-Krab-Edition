#include "PreviewState.h"

PreviewState::PreviewState() {
    quitButtonImg.load("images/Quit_Button.png");
    quitButton = new Button(ofGetWidth()-200,ofGetHeight()-550, ofGetWidth()/5, ofGetHeight()/7, quitButtonImg );
    playButtonImg.load("images/Play_Button.png");
    playButton = new Button(ofGetWidth()-380,ofGetHeight()-550, ofGetWidth()/5, ofGetHeight()/7, playButtonImg );

    preview_screen.load("images/pre_start_screen.png");
    krustyFont_H = new GameFont(loadingFont, "Krabby Patty.ttf", 20);
    krustyFont = new GameFont(loadingFont, "Krabby Patty.ttf", 15);
    Bubble_Bass.load("images/People/Fish People/p_BubbleBass.png");
    Plankton.load("images/People/Fish People/p_Plankton.png");
}
void PreviewState::tick() {
    playButton->tick();
    quitButton->tick();
    if(playButton->wasPressed()){
        setNextState("Game");
		setFinished(true);
    }
    else if(quitButton->wasPressed()){
        setNextState("Menu");
		setFinished(true);
    }
}
void PreviewState::render() {
    preview_screen.draw(0,0,ofGetWidth(), ofGetHeight());
    ofSetColor(255,255,255);

    krustyFont_H->render("Remember the basic controls: ", 53, 198);
	krustyFont->render("Use  '<-'  and  '->'  to  Navigate", 83, 235);
	krustyFont->render("Press  's'  to  serve  the  Burger", 83, 235 + 30);
	krustyFont->render("Press  'e'  to  pickup  Ingredients", 83, 235 + 30*2);
	krustyFont->render("Press  'u'  to  remove  Ingredients", 83, 235 + 30*3);

    krustyFont_H->render("You can also, change the states the of the game: ", 53, 384);
    krustyFont->render("When in game, you can pause it with 'p'", 83, 421);
	krustyFont->render("While the game is pause you can resume it with 'g' or go to the menu with 'm'", 83, 421 + 30);

    krustyFont_H->render("Keep in mind this special characters: ", 53, 510);    
    Bubble_Bass.draw(90, 520, 64*2, 72*2);
    krustyFont_H->render("Bubble Bass", 83, ofGetHeight()/2 + 310);
    krustyFont->render("With this character you'll", 235, 550);
    krustyFont->render("need give him his order", 235, 550 + 30);
    krustyFont->render("before he goes, or he'll", 235, 550 + 30*2);
    krustyFont->render("take half of your money", 235, 550 + 30*3);

    Plankton.draw(435, 530, 64*2, 72*2);
    krustyFont_H->render("Plankton (In disguise)", 439, ofGetHeight()/2 + 325);
    krustyFont->render("With this character what ", 569, 550);
    krustyFont->render("ever you do, do not give", 569, 550 + 30);
    krustyFont->render("him his order, or you'll", 569, 550 + 30*2);
    krustyFont->render("instantly lose the game", 569, 550 + 30*3);

    playButton->render(ofGetWidth()-380, ofGetHeight()-550,ofGetWidth()/5, ofGetHeight()/7);
    quitButton->render(ofGetWidth()-200,ofGetHeight()-550, ofGetWidth()/5, ofGetHeight()/7);



    
    // krustyFont_H->render("Plankton", ofGetWidth()/2 - 340 , ofGetHeight()/2 + 250);
    // krustyFont->render("Whatever you do, do not serve him his order, or you'll instantly lose", ofGetWidth()/2 - 340 , ofGetHeight()/2 + 200);

}


void PreviewState::keyPressed(int key){

    switch(key){
        case 'm': 
            setFinished(true);
            setNextState("Menu");
            break;

        case 'g':
            setFinished(true);
            setNextState("Game");
            break;

    }
}

void PreviewState::mousePressed(int x, int y, int button){
    playButton->mousePressed(x,y);
    quitButton->mousePressed(x,y);

}

void PreviewState::keyReleased(int key){
}

void PreviewState::reset(){
    setFinished(false);
    setNextState("");
    playButton->reset();
    quitButton->reset();
}