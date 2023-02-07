#include "Population.h"

Population::Population(float m, int num, ofVec2f t,int lTime){

	mutationRate = m;
	generations = 0;
	lifeTime = lTime;
	target = t;

	for(int i = 0;i < num;i++){
		ofVec2f position;
		position.set(ofGetWidth()/2, ofGetHeight()+20);
		Rocket* r = new Rocket(position,target, new DNA(lifeTime));
		population.push_back(r);
		
	}



};




void Population::live(vector<Obstacle*> o){
	for(int i=0;i<population.size();i++){
		population[i]->run(o);
	}
}

void Population::fitness(){
	for(int i =0;i<population.size();i++){
		population[i]->calcFitness();
	}
}

void Population::selection(){
	matingPool.clear();


	float maxFitness = 0;

	for(int i =0;i<population.size();i++){
		if(maxFitness < population[i]->fitness){
			maxFitness = population[i]->fitness;
		}
	}
	
	for(int i =0;i<population.size();i++){
		float fitnessNormal = (float) ofMap(population[i]->fitness,0,maxFitness,0,1);
		int n = (int)(fitnessNormal * 100);
		for(int j = 0; j < n; j++){
			matingPool.push_back(*population[i]);
		}
	}
}

void Population::reproduction(){
	for(int i =0;i<population.size();i++){
		int m = rand() % matingPool.size();
		int n = rand() % matingPool.size();

		Rocket mom = matingPool[m];
		Rocket dad = matingPool[n];

		DNA momDNA = mom.getDNA();
		DNA dadDNA = dad.getDNA();
		DNA* child = new DNA(momDNA.genes); 
		child->crossover(dadDNA);
		child->mutate(mutationRate);

		ofVec2f position;
		position.set(ofGetWidth()/2, ofGetHeight()+20);
		population[i] = new Rocket(position,target,child);
		

	}
	generations++;



}
