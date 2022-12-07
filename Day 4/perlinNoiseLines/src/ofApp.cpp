#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofSetBackgroundAuto(false);

    centX = ofGetWidth()/2;
    centY = ofGetHeight()/2;

    radius = ofRandom(300,600);
    startAng = 90;
    angNoise = ofRandom(1);
    strokeCol = 254;
    strokeChange = -1;

    

}

void ofApp::update(){
    centX = ofGetWidth()/2 + 600*ofNoise(ofGetElapsedTimef()) - 300;
    centY = ofGetHeight()/2 + 600*ofNoise(ofGetElapsedTimef() * 0.4) - 300;

    startAng = startAng + 6 * ofNoise(angNoise) - 3;
    angNoise+=0.01;

    if(startAng > 360){
        startAng-=360;
    }
    if(startAng < 0){
        startAng+=360;
    }
    radius = ofGetWidth() *ofNoise(ofGetElapsedTimef() * 0.1);

    strokeCol+=strokeChange;

    if(strokeCol > 254){
        strokeChange = -1;
    }
    if(strokeCol < 0){
        strokeChange = 1;
    }
    

    
    
}

void ofApp::draw(){
    
    ofSetColor(strokeCol,0,0,60);
    ofSetLineWidth(10);

    
    int x1 = centX + radius * cos(ofDegToRad(startAng));
    int y1 = centY + radius * sin(ofDegToRad(startAng));
    int x2 = centX + radius * cos(ofDegToRad(startAng+180));
    int y2 = centY + radius * sin(ofDegToRad(startAng+180));

    ofDrawLine(x1,y1,x2,y2);

    

    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f'){
        ofToggleFullscreen();

    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
