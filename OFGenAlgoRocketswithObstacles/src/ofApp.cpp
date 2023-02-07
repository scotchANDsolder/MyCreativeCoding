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
	population = new Population(mutationRate,1000,target,lifeTime);
	int numObstacles = 20;

	for(int i = 0 ; i<numObstacles; i++){
		obstacleList.push_back(new Obstacle(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(50,200), ofRandom(50,100)));
	}

	
	

	
}

//--------------------------------------------------------------
void ofApp::update(){

	

}

//--------------------------------------------------------------
void ofApp::draw(){
    // ofSetColor(255,0,0);
    // ofFill();
	// ofDrawCircle(target.x,target.y,24);
	// ofSetColor(255);
	// ofFill();

	// for(int i = 0 ; i<obstacleList.size(); i++){
	// 	ofDrawRectangle(obstacleList[i]->location.x,obstacleList[i]->location.y,obstacleList[i]->w,obstacleList[i]->h);
	// }
	

	cout<<lifeCounter<<"\n";

	if(lifeCounter < lifeTime){
		population->live(obstacleList);
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
