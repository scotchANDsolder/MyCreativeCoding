#include "ofMain.h"

class DNA{
public:

	char* genes;
	float fitness;

	void setup(int);
	void calcFitness(char*);
	void crossover(DNA);
	void mutate(float);

	char* getPhrase();

	DNA();


};