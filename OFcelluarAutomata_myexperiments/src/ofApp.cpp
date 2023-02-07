#include "ofApp.h"


void ofApp::setup(){

    ofSetCircleResolution(500);
    ofSetBackgroundColor(0);
    ofSetFrameRate(60);


    cellSize =50;
    numX = floor(ofGetWidth() / cellSize);
    numY = floor(ofGetHeight() / cellSize);
    cout<<numX;

    for(int i = 0 ; i<numX;i++){
        for(int j = 0;j<numX;j++){
            cellArray[i][j].addCell(i,j,cellSize);
        }
    }
    
    //adding neighbors
   for(int i = 0; i < numX;i++){
        for(int j =0; j < numY;j++){

        int above = j -1;
        int below = j + 1;
        int left = i - 1;
        int right = i + 1;

        //checking for edge cases and wrapping them
        if(above < 0){
            above = numY -1;
        }            
        if( below == numY){
            below = 0;
        }
        if(left < 0){
            left = numX -1;
        }
        if(right == numX){
            right = 0;
        }

        //Could I do this with pointers?
        cellArray[i][j].addNeighbors(cellArray[left][above],1);
        cellArray[i][j].addNeighbors(cellArray[left][j],2);
        cellArray[i][j].addNeighbors(cellArray[left][below],3);

        cellArray[i][j].addNeighbors(cellArray[i][below],4);
        cellArray[i][j].addNeighbors(cellArray[right][below],5);
        cellArray[i][j].addNeighbors(cellArray[right][j],6);
        cellArray[i][j].addNeighbors(cellArray[right][above],7);
        cellArray[i][j].addNeighbors(cellArray[i][above],8);



        }
    }


    

}

void ofApp::update(){


    

  
    
    
}

void ofApp::draw(){
    ofTranslate(cellSize/2,cellSize/2);
      for(int i = 0; i < numX;i++){
        for(int j =0; j < numY;j++){
            cellArray[i][j].drawMe();
        }
    }

     for(int i = 0; i < numX;i++){
        for(int j =0; j < numY;j++){
            cellArray[i][j].calcNextState();
        }
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
    for(int i = 0; i < numX;i++){
        for(int j =0; j < numY;j++){
            cellArray[i][j].calcNextState();
        }
    }   


      


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
