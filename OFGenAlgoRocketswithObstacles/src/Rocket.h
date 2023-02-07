#include "ofMain.h"
#include "DNA.h"
#include "Obstacle.h"

class Rocket{
public:
	DNA* dna;
	float fitness;
	int geneCounter;
	float r; //Size of displayed rocket
	bool hitTarget;
	bool hitObstacle;

	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
	ofVec2f target;

	void calcFitness();
	void applyForce(ofVec2f f);
	void update();
	void run(vector<Obstacle*> o);
	void checkTarget();
	void display();
	DNA getDNA();
	void checkObstacle(vector<Obstacle*> o);

	Rocket(ofVec2f position, ofVec2f t, DNA* dna_);


};