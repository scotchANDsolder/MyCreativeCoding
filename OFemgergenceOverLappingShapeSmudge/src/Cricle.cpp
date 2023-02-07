#include "Circle.h"

Circle::Circle(){


	loc.x = ofRandom(ofGetWidth());
	loc.y = ofRandom(ofGetHeight());

    radius = ofRandom(50) + 10;
	lineCol.set(ofRandom(255),ofRandom(255),ofRandom(255),150);
	currCol.set(255,0,0);
	fillCol.set(currCol);

	xmove = ofRandom(1) - 0.5;
	ymove = ofRandom(1)- 0.5;
	incollision = false;
	

}


void Circle::drawMe(){
	ofSetColor(fillCol);
	ofFill();
	ofDrawCircle(loc.x,loc.y,radius);
	
}

void Circle::updateMe(){
	loc.x+=xmove;
	loc.y+=ymove;
	if(loc.x >ofGetWidth() + radius){
		loc.x = 0 - radius;
	}

	if( loc.x < 0 - radius){
		loc.x = ofGetWidth() + radius;
	}

	if( loc.y > ofGetWidth()  + radius) {
		loc.y = 0 - radius;
	}

	if(loc.y < 0 - radius){
		loc.y = ofGetHeight() + radius;
	}

	if(incollision == true){
		fillCol.set(255,0,0,10);

	}
	else{
		fillCol.set(currCol);
	}
    
    //drawMe();
    
    
}

