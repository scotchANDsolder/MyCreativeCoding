
#include "ofMain.h"

class Agent{
public:

	void addNeighbors(Agent &agnet,int pos);
	void calcNextState();
	void drawMe();

	float xpos;
	float ypos;
	int agentSize;
	int growthRate;

	bool state;
	bool nextState;

	int aliveNeighbors; 
	ofColor agentCol;

	
	//Make this into a struct
	Agent* left;
	Agent* right;


	void addAgent(float x, float y, int asize);
	Agent();

	
};
