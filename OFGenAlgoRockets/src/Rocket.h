#include "ofMain.h"
#include "DNA.h"

class Rocket{
public:
	DNA* dna;
	float fitness;
	int geneCounter;
	float r; //Size of displayed rocket
	bool hitTarget;

	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
	ofVec2f target;

	void calcFitness();
	void applyForce(ofVec2f f);
	void update();
	void run();
	void checkTarget();
	void display();
	DNA getDNA();

	Rocket(ofVec2f position, ofVec2f t, DNA* dna_);


};