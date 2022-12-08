import java.util.*;

Random xPosGenerator;
Random yPosGenerator;

Random rColGenerator;
Random gColGenerator;
Random bColGenerator;

float std = 200.0;

float stdCol = 100.0;

void setup(){
  
  //size(620,320);
  fullScreen();
  xPosGenerator = new Random();
  yPosGenerator = new Random();
  
  rColGenerator = new Random();
  bColGenerator = new Random();
  gColGenerator = new Random();
  
  
  
}

void draw(){
  
  float xPos = (float) xPosGenerator.nextGaussian();
  float yPos = (float) yPosGenerator.nextGaussian();
  
  xPos = xPos * std + width/2;
  yPos = yPos * std + height/2;
  
  noStroke();
  
  float rCol = (float) rColGenerator.nextGaussian();
  
  rCol = rCol * stdCol + 255;
  if (rCol > 255) {
    rCol = 255;
  }
  
  float bCol = (float) bColGenerator.nextGaussian();
  
  bCol = bCol * stdCol + 255;
  if (bCol > 255) {
    bCol = 255;
  }
  
  float gCol = (float) gColGenerator.nextGaussian();
  
  gCol = gCol * stdCol + 255;
  if (gCol > 255) {
    gCol = 255;
  }
  
  fill(rCol,bCol,gCol,160);
  circle(xPos, yPos,30);
  
  println(rCol);
}
