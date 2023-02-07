#include "Cell.h"

Cell::Cell(){

}

void Cell::addCell(float x, float y, int csize){

	cellsize = csize;
	xpos = x* cellsize;
	ypos = y * cellsize;

	alive = true;

	nextState = 0;
	movingState = 0;
	currCol = ofColor(255,0,0,200);

}

void Cell::addNeighbors(Cell &cell,int pos){
	switch(pos){
	case 1:
		leftabove = &cell;
		break;
	case 2:
		left = &cell;
		break;
	case 3:
		leftbelow = &cell;
		break;
	case 4:
		below = &cell;
		break;
	case 5:
		rightbelow = &cell;
		break;
	case 6:
		right = &cell;
		break;
	case 7:
		rightabove = &cell;
		break;
	case 8:
		above = &cell;
		break;

	}
	
}

void Cell::drawMe(){

	if(nextState != movingState){
		nextState++;
	}
	else{
		receivedSignal = false;
	}

	currState = nextState;


	if(alive){

	ofSetColor(currCol);
	ofFill();
	ofPushMatrix();
	ofTranslate(xpos,ypos);
	ofRotateDeg(currState);
	ofDrawTriangle(-cellsize/2,cellsize/2,0,-cellsize/2,cellsize/2,cellsize/2);
	ofPopMatrix();

	}
	else{

	ofSetColor(0);
	ofFill();
	ofPushMatrix();
	ofTranslate(xpos,ypos);
	ofDrawCircle(0,0,0);

	ofPopMatrix();

	}

	

	

}

//Logic for each cell 
void Cell::calcNextState(){

	if(receivedSignal == false){

	int coinToss = ofRandom(0,100000);
	int sendSignal = 0;
	if(coinToss == 1){
		movingState = ofRandom(0,360);
		sendSignal = int(ofRandom(1,9));
		switch(sendSignal){
		case 1:
			leftabove->signalValue = movingState;
			leftabove->receivedSignal = true;
			break;
		case 2:
			left->signalValue = movingState;
			left->receivedSignal = true;
			break;
		case 3:
			leftbelow->signalValue = movingState;
			leftbelow->receivedSignal = true;
			break;
		case 4:
			below->signalValue = movingState;
			below->receivedSignal = true;
			break;
		case 5:
			rightbelow->signalValue = movingState;
			rightbelow->receivedSignal = true;
			break;
		case 6:
			right->signalValue = movingState;
			right->receivedSignal = true;
			break;
		case 7:
			rightabove->signalValue = movingState;
			rightabove->receivedSignal = true;
			break;
		case 8:
			above->signalValue = movingState;
			above->receivedSignal = true;
			break;

		}

	}

	}
	else{



		movingState = signalValue;
		//receivedSignal = false;
	}

	












	if(nextState>360){
		nextState = 0;
	}
	if(nextState < 0){
		nextState = 0;
	}



}