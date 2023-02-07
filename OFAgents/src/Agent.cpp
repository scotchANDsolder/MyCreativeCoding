#include "Agent.h"

Agent::Agent(){

}

void Agent::addAgent(float x, float y, int asize){

	agentSize = asize;
	xpos = x;
	ypos = y;
	
	growthRate = ofRandom(1,4);
	if(rand()%2 == 1){
		growthRate*=-1;
	}	
	agentCol = ofColor(ofRandom(255),ofRandom(255),ofRandom(255),120);

}

void Agent::addNeighbors(Agent &agent,int pos){
	switch(pos){
	case 1:
		left = &agent;
		break;
	case 2:
		right = &agent;
		break;
	

	}
	
}

void Agent::drawMe(){
	
	ofSetColor(agentCol);
	ofFill();
	
	ofDrawCircle(xpos,ypos,agentSize);

}

//Logic for each cell 
void Agent::calcNextState(){

	
	
	int force1 = ofDist(xpos,ypos,left->xpos,left->ypos);
	int force2 = ofDist(xpos,ypos,right->xpos,right->ypos);

	if(force1+force2 == 0){

	}
	growthRate = growthRate/(force1+force2);
	

	ypos = growthRate + ypos;
	

	if(ypos > ofGetHeight() - agentSize){
		growthRate *=-1;
	}

	if(ypos < agentSize){
		growthRate *=-1;
	}




}