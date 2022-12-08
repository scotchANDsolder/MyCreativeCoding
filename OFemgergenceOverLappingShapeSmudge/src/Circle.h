
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

	Circle();
	
};
