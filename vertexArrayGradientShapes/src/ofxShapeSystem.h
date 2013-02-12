#pragma once
#include "ofxGradientShape.h"


class ofxShapeSystem {
public:
    ofVec3f centre;
    vector <ofxGradientShape> shapes;
    int shapeCount;
    ofFloatColor	color, bgColor;

    // BRIGHT HEARTS GRADIENTS
    int BHGShapeType, BHGNumSides;
    float BHGBlur, BHGThickness, BHGDiameter;
    
    ofxShapeSystem() {
        centre.set(0,0,0);
        bgColor.set(0,0,0);
        ofColor c;

        // centre, BHGShapeType, BHGNumSides, BHGBlur, BHGThickness, BHGDiameter, color
        float offset = 10;
        
        c.set(255,255,255,80);
        centre.z -= offset;
        addGradientShape(centre, 2, 4, 0, -5, 35, c); // square outward-fading gradient
        
        centre.z -= offset;
        c.set(255,255,255,80);
        addGradientShape(centre, 1, 4, 8, 5, 20, c);  // white square
        
        centre.z -= offset;
        c.set(255,0,0,125);
        addGradientShape(centre, 1, 60, 8, 8, 25, c);  // red round ring

        centre.z -= offset;
        c.set(255,255,255,200);
        addGradientShape(centre, 0, 60, 5, 0, 10, c);  // white inner 'sphere'
        
        centre.z -= offset;
        c.set(0,0,255,85);
        addGradientShape(centre, 1, 60, 5.5, 7.5, 12, c);  // blue inner ring
        
        centre.z -= offset;
        c.set(125,0,255,50);
        addGradientShape(centre, 1, 60, 1, 1.5, 25, c);  // purple ring
        
        centre.z -= offset;
        c.set(125,0,255,50);
        addGradientShape(centre, 1, 60, 1, 1.5, 20, c);  // purple ring
        
        centre.z -= offset;
        c.set(125,0,255,100);
        addGradientShape(centre, 1, 60, 1, 1.5, 15, c);  // purple ring
        
        centre.z -= offset;
        c.set(125,0,255,50);
        addGradientShape(centre, 1, 60, 1, 1, 10, c);  // purple ring
    
    }
    
    void update() {
        for(int i=0;i<shapes.size();i++) {
            shapes[i].run();
        }
    }
        
    void render() {
        ofBackground(bgColor);
        ofEnableAlphaBlending();
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        
        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        for(int i=0;i<shapes.size();i++) {
            shapes[i].renderBHGradients();
        }
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        
        ofDisableAlphaBlending();
    }
    
    void addGradientShape(ofVec3f centre, int BHGShapeType, int BHGNumSides, float BHGBlur, float BHGThickness, float BHGDiameter, ofColor c_) {
        shapes.push_back(ofxGradientShape(shapeCount, centre, BHGShapeType, BHGNumSides, BHGBlur, BHGThickness,BHGDiameter, c_));
        shapeCount++;
    }
    
};

