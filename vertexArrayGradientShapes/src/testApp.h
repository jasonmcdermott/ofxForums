#pragma once

#include "ofMain.h"
#include "ofxShapeSystem.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    
    ofEasyCam camera;
    float camDist;
    ofxShapeSystem ss;
};
