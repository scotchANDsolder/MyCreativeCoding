import gab.opencv.*;
import processing.video.*;
import java.awt.*;

Capture video;
OpenCV opencv;


Mover[] movers = new Mover[10];




void setup() {
  size(640, 480);
  video = new Capture(this, "pipeline:autovideosrc");
  opencv = new OpenCV(this, 640, 480);
  opencv.loadCascade(OpenCV.CASCADE_FRONTALFACE);  

  video.start();
  
  for (int i = 0; i < movers.length; i++) {
    // Initialize each object in the array.
    movers[i] = new Mover();
  }
}

void draw() {
  opencv.loadImage(video);

  image(video, 0, 0 );

  noFill();
  stroke(0, 255, 0);
  strokeWeight(3);
  Rectangle[] faces = opencv.detect();
  println(faces.length);

  for (int x = 0; x < faces.length; x++) {
    println(faces[x].x + "," + faces[x].y);
  //  rect(faces[x].x, faces[i].y, faces[i].width, faces[i].height);
    
    for (int i = 0; i < movers.length; i++) {
    //[full] Calling functions on all the objects in the array
    movers[i].update(faces[x].x + faces[x].width/2, faces[x].y + faces[x].height/8);
    movers[i].checkEdges();
    movers[i].display();
    //[end]
  }
  }
  
  
}

void captureEvent(Capture c) {
  c.read();
}









class Mover {

  PVector location;
  PVector velocity;
  PVector acceleration;
  float topspeed;

  Mover() {
    location = new PVector(random(width),random(height));
    velocity = new PVector(0,0);
    topspeed = 8;
  }

  void update(float x, float y) {

    // <b><u>Our algorithm for calculating acceleration</b></u>:

    //[full] Find the vector pointing towards the mouse.
    PVector mouse = new PVector(x,y);
    PVector dir = PVector.sub(mouse,location);
    //[end]
    // Normalize.
    dir.normalize();
    // Scale.
    dir.mult(0.5);
    // Set to acceleration.
    acceleration = dir;

    //[full] Motion 101! Velocity changes by acceleration.  Location changes by velocity.
    velocity.add(acceleration);
    velocity.limit(topspeed);
    location.add(velocity);
    //[end]
  }

  // Display the Mover
  void display() {
    noStroke();
    fill(255,0,0,160);
    eyeShape(location.x,location.y);
  }

  // What to do at the edges
  void checkEdges() {

    if (location.x > width) {
      location.x = 0;
    } else if (location.x < 0) {
      location.x = width;
    }

    if (location.y > height) {
      location.y = 0;
    }  else if (location.y < 0) {
      location.y = height;
    }
  }
}

void eyeShape(float x, float y){
  pushMatrix();
  translate(x,y);
  circle(0,0,16);
  popMatrix();
  
}
