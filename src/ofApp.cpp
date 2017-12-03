#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particles.size(); i++) {
        particles[i].update();
        if(particles[i].alpha < 0) {
            particles.erase(particles.begin() + i);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(ofRandom(1) < 0.02) {
        ofVec2f randomPos = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight() /2));
        addFireworks(randomPos);
    }
    for(int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ofVec2f mousePos = ofVec2f(x,y);
    addFireworks(mousePos);
}

void ofApp::addFireworks(ofVec2f pos) {
    int r = 0;
    int g = 0;
    int b = 0;
    
    
    if(ofRandom(1) < 0.5) {
        r = ofRandom(255);
        g = 10;
        b = 255;
    } else {
        r = ofRandom(100,255);
        g = 255;
        b = 10;
    }
    
    for (int i = 0; i < num; i++) {
        Particle p(r, g, b);
        
        p.position = pos;
        p.velocity = ofVec2f(0, 0);
        
        float length = ofRandom(5.0);
        float angle = ofRandom(2.0 * PI);
        ofVec2f force = ofVec2f(length * cos(angle), length * sin(angle));
        
        p.addForce(force);
        particles.push_back(p);
    }
}

