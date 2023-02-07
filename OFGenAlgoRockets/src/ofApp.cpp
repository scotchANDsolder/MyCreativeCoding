#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
	ofBackground(0);
	lifeTime = 700;
	cout<<lifeTime;
	lifeCounter = 0;
	target.set(ofGetWidth()/2,24);
	float mutationRate = 0.1;
	population = new Population(mutationRate,500,target,lifeTime);

	
}

//--------------------------------------------------------------
void ofApp::update(){

	

}

//--------------------------------------------------------------
void ofApp::draw(){
    // ofSetColor(255,0,0);
    // ofFill();
	// ofDrawCircle(target.x,target.y,24);
	cout<<lifeCounter<<"\n";

	if(lifeCounter < lifeTime){
		population->live();
		lifeCounter++;

	}
	else{
		cout<<"dome";
		lifeCounter = 0;
		population->fitness();
		population->selection();
		population->reproduction();
	}

	

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
