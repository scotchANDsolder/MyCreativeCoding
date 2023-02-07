#include "Obstacle.h"

Obstacle::Obstacle(float x, float y, float width, float height){
    location.set(x,y);
    w = width;
    h = height;
    
};

bool Obstacle::contains(ofVec2f v){
    if(v.x > location.x && v.x <location.x + w && v.y > location.y && v.y < location.y + h){
        return true;
    }
    else{
        return false; 
    }
}