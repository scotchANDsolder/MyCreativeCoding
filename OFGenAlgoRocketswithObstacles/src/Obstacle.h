#include "ofMain.h"

class Obstacle{
    public:
    Obstacle(float x, float y, float width, float height);

    ofVec2f location;
    float w,h;
    bool contains(ofVec2f v);


};