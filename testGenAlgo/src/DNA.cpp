#include "DNA.h"

DNA::DNA(){

};

//Populate genes randomly
void DNA::setup(int geneLen){
	genes = new char[geneLen]();
	for(int i = 0; i < geneLen;i++){
		genes[i] = (char)ofRandom(32,128);
	}
	
}
//Cacluate fitness based on provided target
void DNA::calcFitness(char* target){
	int score  = 0;

	for (int i = 0; i < sizeof(genes); i++){
		if (genes[i] == target[i]){
			score++;
		}
	}

	fitness = (float)(score / sizeof(target));
} 

//Crossover with partner gene
void DNA::crossover(DNA partner){
	// DNA child;
	// child.setup(sizeof(genes));
	int midpoint = ofRandom(sizeof(genes));

	for(int i = 0; i< sizeof(genes);i++){
		if(i > midpoint){
			strcpy(genes[i],partner.genes[i]);
		}

	


	//return child;
}


void DNA::mutate(float mutationRate){

	for(int i =0; i<sizeof(genes);i++){
		if(ofRandom(1) < mutationRate){
			genes[i] = (char)ofRandom(32,128);
		}
	}



}