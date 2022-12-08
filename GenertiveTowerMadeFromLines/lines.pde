float x = 1 ;
void setup(){
  size(720,640);
  background(180);
  strokeWeight(4);
  strokeCap(SQUARE);
  for(int h = 10; h <= height -5; h+=10){
    stroke(0,255-h/2);
    float indent = 10 + noise(x)*width/3;
    //float indent = random(10,width/3);
    line(indent,h,width-indent,h);
    stroke(255,h/2);
    line(indent,h+4,width-indent,h+4);
    x+=0.01;
  }
}

void draw(){}

void keyPressed(){
 saveFrame("lines-####.jpg");
}
