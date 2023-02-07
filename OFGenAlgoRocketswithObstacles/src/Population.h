#include "ofMain.h"
#include "Rocket.h"



class Population{
public:
	Population(float m, int num,ofVec2f t,int lTime);

	float mutationRate;
	ofVec2f target;
	int lifeTime;
	
	vector<Rocket*> population;
	vector<Rocket> matingPool;
	int generations;

	void fitness();
	void selection();
	void reproduction();
	void live(vector<Obstacle*> o);
};