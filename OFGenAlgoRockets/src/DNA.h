#include "ofMain.h"
#include <vector>


class DNA{
public:

	vector<ofVec2f> genes;
	float maxForce;

	int geneLen;
	
	void crossover(DNA partner);
	void mutate(float mutationRate);


	DNA(int lifeTime);
	DNA(vector<ofVec2f> newgenes);


};