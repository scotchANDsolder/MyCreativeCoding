#include "ofMain.h"
#include <vector>
#include <string>

class DNA{
public:

	vector<char> genes;
	int geneLen;
	float fitness;
	
	void randomSetupGenes(int targetLen);
	void calcFitness(string target);
	DNA crossover(DNA partner);
	void mutate(float mutationRate);
	string getPhrase();
	

	DNA();


};