#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);

	height = ofGetHeight();
	width = ofGetWidth();



}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){


for (int y = 0; y < height; y++){
    for (int x = 0; x<width; x++){
        mesh.addVertex(ofPoint(x,y,0)); // make a new vertex
        mesh.addColor(ofFloatColor(0,0,0));  // add a color at that vertex
    }
}

// now it's important to make sure that each vertex is correctly connected with the
// other vertices around it. This is done using indices, which you can set up like so:
for (int y = 0; y<height-1; y++){
    for (int x=0; x<width-1; x++){
        mesh.addIndex(x+y*width);               // 0
        mesh.addIndex((x+1)+y*width);           // 1
        mesh.addIndex(x+(y+1)*width);           // 10

        mesh.addIndex((x+1)+y*width);           // 1
        mesh.addIndex((x+1)+(y+1)*width);       // 11
        mesh.addIndex(x+(y+1)*width);           // 10
    }
}



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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