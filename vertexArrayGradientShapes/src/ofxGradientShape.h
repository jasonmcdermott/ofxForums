#pragma once

class ofxGradientShape {
public:
    
    ofVec3f pos, origin;
    int ID;
    float middleRadius;
    ofFloatColor	color;
    
    int BHGShapeType, BHGNumSides;
    float BHGBlur, BHGThickness, BHGDiameter;

    ofxGradientShape() {}
    
    ofxGradientShape(int ID_, ofVec3f centre_, int shapeType_, int numSides_, float blur_, float thickness_, float diam_, ofColor c_) {
        origin.set(centre_);
        pos.set(centre_);
        ID = ID_;
        color.set(c_);
        BHGShapeType = shapeType_;
        BHGNumSides = numSides_;
        BHGThickness = thickness_;
        BHGBlur = blur_;
        BHGDiameter = diam_;
    }

    void run() {}
    
    void renderBHGradients() {
        if (BHGShapeType == 0) {
            drawGradient(BHGDiameter-BHGBlur,0,color.a,0,BHGNumSides);
            drawGradient(BHGDiameter,BHGDiameter-BHGBlur,0,0,BHGNumSides);
        } else if (BHGShapeType == 1) {
            drawGradient(BHGDiameter+BHGThickness-BHGBlur,BHGDiameter-BHGThickness+BHGBlur,color.a,0,BHGNumSides);
            drawGradient(BHGDiameter+BHGThickness,BHGDiameter+BHGThickness-BHGBlur,0,0,BHGNumSides);
            drawGradient(BHGDiameter-BHGThickness,BHGDiameter-BHGThickness+BHGBlur,0,0,BHGNumSides);
        } else if (BHGShapeType == 2) {
            drawGradient(BHGDiameter-BHGThickness,BHGDiameter+BHGThickness,0,0,BHGNumSides);
            drawGradient(BHGDiameter+BHGThickness+BHGThickness*0.05, BHGDiameter+BHGThickness, 0, 0, BHGNumSides);
        }
    }
    
    void drawGradient(float opaque_, float transp_, float opac_, float blur_, int ns_) {
        
        ofPushMatrix();
        ofTranslate(pos.x,pos.y,pos.z);
        
        GLfloat* ver_coords = new GLfloat[ (ns_+1) * 4];
        GLfloat* ver_cols = new GLfloat[ (ns_+1) * 8];

        float angle;
        float angleSize =  2*PI/ns_;
        
        
        if (opaque_ < transp_) {
            middleRadius = opaque_ - ((transp_-opaque_)+blur_);
        } else {
            middleRadius = opaque_ - ((transp_-opaque_)+blur_);
        }
        
        middleRadius = (opaque_ + transp_)/2;
        
        for (int i=0; i< (1+ns_); i++) {
            angle = i* angleSize;
            ver_coords[i*4+0] = (opaque_*cos(angle));
            ver_coords[i*4+1] = (opaque_*sin(angle));
            ver_cols[i*8+0] = color.r;
            ver_cols[i*8+1] = color.g;
            ver_cols[i*8+2] = color.b;
            ver_cols[i*8+3] = opac_;
            ver_coords[i*4+2] = (transp_*cos(angle));
            ver_coords[i*4+3] = (transp_*sin(angle));
            ver_cols[i*8+4] = color.r;
            ver_cols[i*8+5] = color.g;
            ver_cols[i*8+6] = color.b;
            ver_cols[i*8+7] = color.a;
        }
        
        
        glVertexPointer( 2, GL_FLOAT, 0, ver_coords);
        glColorPointer(4, GL_FLOAT, 0, ver_cols);
        glDrawArrays( GL_TRIANGLE_STRIP, 0, ( ns_ + 1 ) * 2 );
        
        delete[] ver_coords;
        delete[] ver_cols;
        ofPopMatrix();
    }
    
};


