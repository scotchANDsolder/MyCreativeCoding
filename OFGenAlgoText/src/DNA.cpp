#include "DNA.h"

DNA::DNA(){

};

void DNA::randomSetupGenes(int targetLen){

	for(int i=0;i<targetLen;i++){

		genes.push_back(' ' + rand()%95); //ascii from space to ~
	}

	geneLen = genes.size();

}

void DNA::calcFitness(string target){
	int score = 0;

	for(int i;i<geneLen;i++){
		if(genes[i] == target[i]){
			score++;
		}
	}

	//fitness = (float)score/(float)geneLen;
	fitness = (float) score*score / float (geneLen*geneLen);
	//cout<<fitness<<"\n";
}


DNA DNA::crossover(DNA partner){
	DNA child;
	child.randomSetupGenes(geneLen);

	int midpoint = rand()%geneLen;
	for(int i=0;i<geneLen;i++){
		if(i > midpoint){
			child.genes[i] = genes[i];
		}
		else{
			child.genes[i] = partner.genes[i];
		}
	}


	return child;
}

void DNA::mutate(float mutationRate){
	for(int i = 0;i<geneLen;i++){
		if((float)(rand()) / (float)(RAND_MAX) < mutationRate){
			genes[i] = (char)(' ' + rand()%95);
		}
	}
}




//Phenotype
string DNA::getPhrase(){

	string phrase;

	for(int i =0;i<this->geneLen;i++){
		phrase.push_back(genes[i]);
	}

	return phrase;


}


