#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	ofGLFWWindowSettings settings;
    settings.setSize(1024, 768);
	settings.monitor = 1; //set it to use the second monitor
	//settings.setPosition(glm::vec2(1920,0)); //if the above doesn't work try this line instead
	settings.windowMode = OF_FULLSCREEN;
	
	//make the window
	auto mainWindow = ofCreateWindow(settings);

	//run the app 
	shared_ptr<ofApp> mainApp(new ofApp);

	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();

}
