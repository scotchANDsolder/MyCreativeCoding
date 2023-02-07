#include "DNA.h"

DNA::DNA(int lifeTime){
	maxForce = 0.1;
	for(int i=0;i<lifeTime;i++){
		float angle = ofRandom(0,2*M_PI);
		ofVec2f v;
		v.set(cos(angle),sin(angle)); //random floats
		float randForce = ofRandom(0,maxForce);
		v = v*randForce;
		genes.push_back(v);
	}

	geneLen = genes.size();

};

DNA::DNA(vector<ofVec2f> newgenes){
	genes = newgenes;
	geneLen = genes.size();
}



void DNA::crossover(DNA partner){
	int midpoint = rand()%geneLen;
	for(int i=0;i<geneLen;i++){
		if(i > midpoint){
			genes[i] = partner.genes[i];
		}
	
	}

}

void DNA::mutate(float mutationRate){
	for(int i = 0;i<geneLen;i++){
		if(ofRandom(1) < mutationRate){
			float angle = ofRandom(0,2*M_PI);
			ofVec2f v;
			v.set(cos(angle),sin(angle)); //random floats
			float randForce = ofRandom(0,maxForce);
			v = v*randForce;
			genes[i] = v;
		}
	}
}





