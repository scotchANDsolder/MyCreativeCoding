#include "ofApp.h"


void ofApp::setup(){
    ofSetCircleResolution(500);
    ofSetBackgroundColor(0);
    ofSetBackgroundAuto(false);
    

    

}

void ofApp::update(){
    

   

    
    
}

void ofApp::draw(){

//    for(int i =0; i < NCIRCS ;i++){
//        myCircle[i].drawMe();
//
//    }
    
    for(int i =0; i < NCIRCS ;i++){
        
        for(int j = 0; j < NCIRCS; j++ ){
            
            if(i != j){

                float overlap = myCircle[i].loc.distance(myCircle[j].loc) - (myCircle[i].radius + myCircle[j].radius);
                
                if(overlap < 0){
                    float midx;
                    float midy;
                    midx = (myCircle[i].loc.x + myCircle[j].loc.x) / 2;
                    midy = (myCircle[i].loc.y + myCircle[j].loc.y) / 2;
                    ofNoFill();
                    ofSetColor(255,0,0,30);
                    overlap*=-1;
                    ofDrawEllipse(midx, midy, overlap,overlap);
                }
            }

        }
        
        
       myCircle[i].updateMe();
        

    }
    
    

    

    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f'){
        ofToggleFullscreen();

    }
    if(key == 'r'){
        ofSetBackgroundAuto(true);
    }
    if(key == 't'){
        ofSetBackgroundAuto(false);
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
