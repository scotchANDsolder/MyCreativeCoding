#include "Cell.h"

Cell::Cell(){

}

void Cell::addCell(float x, float y, int csize){

	cellsize = csize;
	xpos = x* cellsize;
	ypos = y * cellsize;
	//cout<<xpos<<" ";
	if(rand()% 2 == 1){
		nextState = true;
	}
	else{
		nextState = false;
	}

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

	if(state == true){
		ofSetColor(255,0,0);
	}
	else{
		ofSetColor(0);
	}

	ofFill();
	ofDrawCircle(xpos,ypos,cellsize/2);

}

//Logic for each cell 
void Cell::calcNextState(){

	
	//GOL
	// int liveCount = 0;

	

	// if(leftabove->state == true){
	// 	liveCount++;
	// }

	// if(left->state == true){
	// 	liveCount++;
	// }

	// if(leftbelow->state == true){
	// 	liveCount++;
	// }


	// if(below->state == true){
	// 	liveCount++;
	// }


	// if(rightbelow->state == true){
	// 	liveCount++;
	// }


	// if(right->state == true){
	// 	liveCount++;
	// }


	// if(rightabove->state == true){
	// 	liveCount++;
	// }


	// if(above->state == true){
	// 	liveCount++;
	// }




	// if(state == true){
	// 	if(liveCount == 2 || liveCount == 3){
	// 		nextState = true;
	// 	}
	// 	else{
	// 		nextState = false;
	// 	}
	// }

	// else{
	// 	if(liveCount == 3){
	// 		nextState = true;
	// 	}
	// 	else{
	// 		nextState = false;
	// 	}
	// }


	//Vichnaic
	int liveCount = 0;

	if(leftabove->state == true){
		liveCount++;
	}

	if(left->state == true){
		liveCount++;
	}

	if(leftbelow->state == true){
		liveCount++;
	}


	if(below->state == true){
		liveCount++;
	}


	if(rightbelow->state == true){
		liveCount++;
	}


	if(right->state == true){
		liveCount++;
	}


	if(rightabove->state == true){
		liveCount++;
	}


	if(above->state == true){
		liveCount++;
	}

	if(state){
		liveCount++;
	}

	if(liveCount <=4){
		nextState = false;
	}
	else if(liveCount >4){
		nextState = true;
	}

	if(liveCount ==4 || liveCount ==5){
		nextState=!nextState;
	}

}