#include "ofApp.h"
#include <vector>

//--------------------------------------------------------------
void ofApp::setup(){
	totalPopulation = 500;
	mutationRate = 0.01;

	target ="to be or not to be";
	population = new DNA[totalPopulation]();

	for(int i = 0; i < sizeof(population);i++){
		population[i].setup((int)sizeof(target));
	}

}

//--------------------------------------------------------------
void ofApp::update(){

	for(int i =0 ; i <sizeof(population);i++){
		population[i].calcFitness(target);
	}

	for(int i =0 ; i <sizeof(population);i++){
		int n = (int) population[i].fitness * 100;
		for(int j = 0 ; j < n ;j++){
			matingPool.push_back(population[i]);
		}
	}

	for(int i =0 ; i <sizeof(population);i++){
		int a = (int)ofRandom(matingPool.size());
		int b = (int)ofRandom(matingPool.size());
		DNA partnerA = matingPool[a];
		DNA partnerB = matingPool[b];

		partnerA.crossover(partnerB);
		//child.mutate(mutationRate);


		//population[i] = child;


	}


}

//--------------------------------------------------------------
void ofApp::draw(){

	for(int i =0 ; i <sizeof(population);i++){
		cout<<population[i].genes;
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
