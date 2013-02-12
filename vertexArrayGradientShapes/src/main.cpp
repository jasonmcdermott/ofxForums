#include "testApp.h"
#include "ofAppGlutWindow.h"

//--------------------------------------------------------------
int main(){
	ofAppGlutWindow window; // create a window
    window.setGlutDisplayString("rgba double depth alpha samples>=4");    
	// set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
	ofSetupOpenGL(&window, 1020, 768, OF_WINDOW);
	ofRunApp(new testApp()); // start the app
}
