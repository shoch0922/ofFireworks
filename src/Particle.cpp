#include "Particle.h"

Particle::Particle(int _r, int _g, int _b){
    mass = 1.6;
    position = ofVec2f(ofGetWidth()/2.0, ofGetHeight()/2.0);
    velocity = ofVec2f(0, 0);
    alpha = 255.0;
    gravity = ofVec2f(0, ofRandom(0.02, 0.04));
    acceleration = ofVec2f(0,0);
    r = _r;
    g = _g;
    b = _b;
}

void Particle::update(){
    acceleration += gravity;
    velocity += acceleration;
    position += velocity;
    acceleration.set(0, 0);
    alpha -= ofRandom(0, 5);
}

void Particle::draw(){
    float radius = ofRandom(1.0, 2.0);
    ofSetColor(r, g ,b, alpha);
    ofDrawCircle(position.x, position.y, radius);
}

void Particle::addForce(ofVec2f _force){
    acceleration += _force / mass;
}

