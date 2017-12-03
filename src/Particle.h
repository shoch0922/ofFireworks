#pragma once
#include "ofMain.h"

class Particle {
    
public:
    Particle(int r, int g, int b);
    void update();
    void draw();
    
    void addForce(ofVec2f force);
    
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofVec2f gravity;
    
    float radius;
    float mass;
    float alpha;
    
    int r;
    int g;
    int b;
};
