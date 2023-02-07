#include "Rocket.h"
#include <math.h>

Rocket::Rocket(ofVec2f position, ofVec2f t, DNA* dna_){
	hitTarget = false;
	dna = dna_;
	target = t;
	location = position;
	velocity.set(0,0);
	acceleration.set(0,0);
	geneCounter = 0;
	hitObstacle = false;
};




void Rocket::calcFitness(){
	float d = location.distance(target);
	//cout<<d<<"\n";
	fitness = (1/d) * (1/d);
	if(hitObstacle){
		fitness*=0.1;
	}
}



void Rocket::applyForce(ofVec2f f){
	acceleration = acceleration + f;
}

void Rocket::update(){
	velocity = velocity + acceleration;
	location = location + velocity;
	acceleration = acceleration * 0;

}

void Rocket::run(vector<Obstacle*> o){
	if(!hitObstacle){
		checkTarget();
		if(!hitTarget){
			applyForce(dna->genes[geneCounter]);
			geneCounter++;
			update();
			checkObstacle(o);
		}

	display();

	}
	
	
}

void Rocket::checkTarget(){
	float d = location.distance(target);
	if(d<15){
		hitTarget = true;

	}
}

void Rocket::display(){

	//cout<<location<<"\n";

	float heading = std::atan2(velocity.y, velocity.x);
	ofSetColor(255,0,0,20);
	ofFill();
	ofPushMatrix();
	ofTranslate(location.x,location.y);
	ofRotateRad(heading);

	ofDrawCircle(0,0,1);
	ofPopMatrix();



}

DNA Rocket::getDNA(){
	return *dna;
}


void Rocket::checkObstacle(vector<Obstacle*> o){
	for(int i =0 ; i < o.size();i++){
		if(o[i]->contains(location)){
			hitObstacle = true;
		}
	}

}