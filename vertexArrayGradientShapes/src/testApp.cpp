
// Created by Jason McDermott
// http://www.jasonmcdermott.net
// Move the gradients around, change their size and shape.
// Have Fun!  

#include "testApp.h"


void testApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetCircleResolution(100);
    
	camDist  = 60;
	camera.setDistance(camDist);
}

void testApp::update(){
    ss.update();
}

void testApp::draw(){
    camera.begin();
    ss.render();
    camera.end();
}