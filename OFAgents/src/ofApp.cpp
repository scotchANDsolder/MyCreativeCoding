#include "ofApp.h"


void ofApp::setup(){

    ofSetCircleResolution(500);
    ofSetBackgroundColor(0);
    ofSetFrameRate(30);


    
    numAngets = 5;

    for(int i = 0; i < numAngets;i++){
        agentSize = (ofGetWidth()/numAngets) / 5;
        agentArray[i].addAgent((ofGetWidth()/numAngets)*i,ofGetHeight()/2,agentSize);
    }

    
    
    //adding neighbors
   for(int i = 0; i < numAngets;i++){
       

        
        int left = i - 1;
        int right = i + 1;

        
        if(left < 0){
            left = 0;
        }
        if(right == numAngets){
            right = numAngets;
        }
        //1 is left, 2 is right
        agentArray[i].addNeighbors(agentArray[left],1);
        agentArray[i].addNeighbors(agentArray[right],2);
      


        
    }


    

}

void ofApp::update(){


    

  
    
    
}

void ofApp::draw(){

      for(int i = 0; i < numAngets;i++){
        
            agentArray[i].drawMe();
        
    }

     for(int i = 0; i < numAngets;i++){
        
            agentArray[i].calcNextState();
        
    }

   



  

    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f'){
        ofToggleFullscreen();

    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
