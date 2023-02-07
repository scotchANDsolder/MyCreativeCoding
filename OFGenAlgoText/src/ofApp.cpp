#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	target = "death is the road to awe";
	popLen = 5000;
	mutationRate = 0.01;
	for(int i =0;i<popLen;i++){
		DNA newGene;
		newGene.randomSetupGenes(target.length());
		population.push_back(newGene);
	
	}


	
}

//--------------------------------------------------------------
void ofApp::update(){

	// //Calculate fitness
	for(int i =0;i<population.size();i++){
		population[i].calcFitness(target);
	}

	

	vector<DNA> matingPool;

	// // //Create mating pool
	for(int i = 0; i < population.size() ;i++){
		int n = population[i].fitness * 100; //Add more genes that have a higher fitness val
		
		for(int j =0; j < n;j++){
			matingPool.push_back(population[i]);
		}
	}

	

	if(matingPool.size() > 0){
		for(int i =0;i<population.size();i++){
		int a = rand()%matingPool.size();
		int b = rand()%matingPool.size();


		DNA partnerA = matingPool[a];
		DNA partnerB = matingPool[b];

		DNA child = partnerA.crossover(partnerB);
		child.mutate(mutationRate);
		child.calcFitness(target);

		population[i] = child;

		}

	}

	
	

	float maxFitness = (float)population[0].fitness;
	int bestAnswer = 0;
	
	for(int i =0;i<population.size();i++){

		

		if(maxFitness < population[i].fitness){
			bestAnswer = i;
			maxFitness = population[i].fitness;
		}


	 }

	cout<<population[bestAnswer].getPhrase()<<"  ";
	cout<<population[bestAnswer].fitness<<"\n";

	


}

//--------------------------------------------------------------
void ofApp::draw(){

	




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
