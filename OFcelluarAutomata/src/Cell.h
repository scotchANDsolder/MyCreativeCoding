
#include "ofMain.h"

class Cell{
public:

	void addNeighbors(Cell &cell,int pos);
	void calcNextState();
	void drawMe();

	float xpos;
	float ypos;
	int cellsize;
	bool state;
	bool nextState;

	int aliveNeighbors; 
	
	//Make this into a struct
	Cell* left;
	Cell* right;
	Cell* leftabove;
	Cell* leftbelow;
	Cell* below;
	Cell* rightbelow;
	Cell* rightabove;
	Cell* above;

	void addCell(float x, float y, int csize);
	Cell();

	
};
