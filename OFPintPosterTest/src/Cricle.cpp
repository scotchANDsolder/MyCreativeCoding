#include "Circle.h"


Circle::Circle(int w, int h){


	loc.x = ofRandom(w);
	loc.y = ofRandom(h);

    radius = ofRandom(300) + 100;
	lineCol.set(ofRandom(255),ofRandom(255),ofRandom(255),150);
	currCol.set(255,0,0);
	fillCol.set(currCol);

	xmove = ofRandom(5) - 4;
	ymove = ofRandom(5)- 4;
	incollision = false;

	maxWidth = w;
	maxHeight = h;
	

}


void Circle::drawMe(){
	ofSetColor(fillCol);
	ofFill();
	ofDrawCircle(loc.x,loc.y,radius);
	
}

void Circle::updateMe(){
	loc.x+=xmove;
	loc.y+=ymove;
	if(loc.x >maxWidth + radius){
		loc.x = 0 - radius;
	}

	if( loc.x < 0 - radius){
		loc.x = maxWidth + radius;
	}

	if( loc.y > maxHeight  + radius) {
		loc.y = 0 - radius;
	}

	if(loc.y < 0 - radius){
		loc.y = maxHeight + radius;
	}

	if(incollision == true){
		fillCol.set(255,0,0,30);

	}
	else{
		fillCol.set(currCol);
	}
    
    //drawMe();
    
    
}

