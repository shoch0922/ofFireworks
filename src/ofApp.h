#pragma once

#include "ofMain.h"
#include "Particle.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();

    void mouseReleased(int x, int y, int button);
    void addFireworks(ofVec2f pos);
    
    static const int num = 2000;
    vector <Particle> particles;
};

