#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	// ofSetupOpenGL(820,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	// ofRunApp(new ofApp());
	
	// Runs app in forced window size
	ofGLFWWindowSettings settings;
	settings.resizable = false;
	settings.setSize(820, 768);
	ofCreateWindow(settings);
	return ofRunApp(new ofApp);

}
