#include "Cell.h"

Cell::Cell(){

}

void Cell::addCell(float x, float y, int csize){

	cellsize = csize;
	xpos = x* cellsize;
	ypos = y * cellsize;

	nextState = ofRandom(255);

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
	state = nextState;

	ofSetColor(state,0,0);
	ofFill();
	//ofDrawCircle(xpos,ypos,cellsize/2);
	ofDrawRectangle(xpos,ypos,cellsize,cellsize);

}

//Logic for each cell 
void Cell::calcNextState(){

	
	float total = 0;

	total = leftabove->state + left->state + leftbelow->state + below->state + rightbelow->state + right->state + rightabove->state + above->state;

	float avg = total/8;

	if(avg == 255){
		nextState = 0;
	}
	else if (avg == 0){
		nextState = 255;
	}
	else{
		nextState = nextState + avg;

		if(lastState > 0){
			nextState = nextState - lastState;
		}

		if(nextState > 255){
			nextState = 255;
		}
		if(nextState < 0){
			nextState = 0;
		}
	}

	lastState = state;

}