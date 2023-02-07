
#include "ofMain.h"

class Circle{
public:

	void drawMe();
	void updateMe();

	int id;
	bool incollision;

	ofVec2f loc;
	float radius;
	ofColor lineCol;
	ofColor fillCol;
	ofColor currCol;
	float xmove;
	float ymove;

	int maxWidth; //the size of the poster we want to print
	int maxHeight;


	Circle(int x, int h);
	
};
