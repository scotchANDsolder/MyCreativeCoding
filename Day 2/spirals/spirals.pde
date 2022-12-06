

  float centX;
  float centY;
  
  
  float x1,y1;
  float x2,y2;

  float centXNoise = random(10);
  float centYNoise = random(10);
  
  float midX = 0;
  float midY = 0;
  
  float radius = 5;
  float radiusNoise = random(0,100);
  float rNoise = random(0,100);
  
void setup(){
  midX = width/2; 
  midY = height/2; 
  
  //fullScreen();
  
  size(720, 640);
  background(0);
  centX = width/2;
  centY = height/2;
  
  
  noStroke();
  fill(255,0,0,120);
  
 
  
  for(int i = 0; i < 20; i++){
    
    centX = width/2 + random(-200,200);
  centY = height/2 + random(-200,200);
  
  for(float ang = 0 ; ang < 400; ang+=1){
    
    radiusNoise = 100 + ((noise(rNoise) * 100) - 5);
    radius = radiusNoise;

    
    float angle = radians(ang);
    
    float x = centX + radius * cos(angle);
    float y = centY + radius * sin(angle);

    
    
    circle(x,y, 5);
    
    rNoise+=0.01;
  }
    
    
    
  }
  
  
  
  
  
}
  
  
     

void draw(){
  
  
  
  
  
    
    
    
    
}
 
void keyPressed() {
   saveFrame("lineSmudge-######.png");

}
