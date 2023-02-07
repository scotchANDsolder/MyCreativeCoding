

  float centX;
  float centY;
  
  float startAng = 10;
  float endAng = 280;
  float radius = 0;
  
  float x1,y1;
  float x2,y2;
  int strokeCol = 0;
  int strokeChange = -1;
    
  float radiusNoise = random(10);
  float angleNoise = random(10);
  float centXNoise = random(10);
  float centYNoise = random(10);
  float ang = -PI/2;
  
void setup(){
  
  //size(500,300);
  fullScreen();
  background(0);
  centX = width/2;
  centY = height/2;
  
  
  
  strokeWeight(5);
  
  
}
  
  
     

void draw(){
  radiusNoise+=0.005;
  radius = 1 + (noise(radiusNoise) * 700);
      
  angleNoise+=0.005;
  ang = ang + (noise(angleNoise) * 6) - 3;
    
  if(ang > 360){
      ang-=360;
    }
  if(ang < 0){
      ang+=360;
    }
    
   float rad = radians(ang);
   centXNoise+=0.01;
   centYNoise+=0.01;
       
   centX = width/2 + (noise(centXNoise) *100) - 50;
   centY = height/2 + (noise(centYNoise) *100) - 50;

    
    x1 = centX + radius * cos(rad);
    y1 = centY + radius * sin(rad);
    
    x2 = centX + radius * cos(rad + PI);
    y2 = centY + radius * sin(rad + PI);
    
    line(x1,y1,x2,y2);
    
    strokeCol+=strokeChange;
    if(strokeCol > 254){
      strokeChange = -1;
    }
    if(strokeCol < 0){
      strokeChange = 1;
    }
    stroke(strokeCol,0,0, 60);
    
    
    
    
 }
