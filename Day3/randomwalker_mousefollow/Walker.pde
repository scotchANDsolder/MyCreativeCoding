class Walker{
  int x;
  int y;
  
  Walker(){
    x = width/2;
    y = height /2;
  }
  
  void display(){
    stroke(0);
    point(x,y);
  }
  
  void step(){
    int probX = int(random(4));
    int probY = int(random(4));
    int[] movementArrayX = new int[5];
    int[] movementArrayY = new int[5];
    
    int dirX = mouseX;
    int dirY = mouseY;
    
    if(dirX < x){
      //move left
      movementArrayX[0] = 0;
      movementArrayX[1] = 1;
      movementArrayX[2] = -1;
      movementArrayX[3] = -1;
      movementArrayX[4] = -1;
      
    }
    else{
      //move move right
      movementArrayX[0] = 0;
      movementArrayX[1] = 1;
      movementArrayX[2] = -1;
      movementArrayX[3] = 1;
      movementArrayX[4] = 1;
    }
    
    if (dirY > y){
      //move down
      movementArrayY[0] = 0;
      movementArrayY[1] = 1;
      movementArrayY[2] = -1;
      movementArrayY[3] = 1;
      movementArrayY[4] = 1;
    }
    else{
      //move up
      movementArrayY[0] = 0;
      movementArrayY[1] = 1;
      movementArrayY[2] = -1;
      movementArrayY[3] = -1;
      movementArrayY[4] = -1;
    }
    
    x+=movementArrayX[probX];
    y+=movementArrayY[probY];

    
    
    
  }
}
