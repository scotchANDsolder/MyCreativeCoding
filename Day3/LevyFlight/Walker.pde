import java.util.*;
Random xGen;
Random yGen;

class Walker{
  float x;
  float y;
  
  float std = 5;
  
  Walker(){
    x = width/2;
    y = height /2;
    xGen = new Random();
    yGen = new Random();
    
  }
  
  void display(){
    stroke(0);
    point(x,y);
  }
  
  void step(){
    
    float xStep = (float) xGen.nextGaussian();
    float yStep = (float) yGen.nextGaussian();
    
    int xBound = int(xStep*std + 10);
    int yBound = int(yStep*std + 10);
    
    x = x + random(-xBound,xBound);
    y = y + random(-yBound,yBound);
    
    
    
  }
    
}
