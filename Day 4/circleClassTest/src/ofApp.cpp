#include "ofApp.h"


void ofApp::setup(){
    ofSetCircleResolution(500);
    for(int i =0; i < NCIRCS ;i++){
        myCircle[i].setID(i);

    }

    

}

void ofApp::update(){
    for(int i =0; i < NCIRCS ;i++){
        myCircle[i].updateMe();

    }

    for(int i =0; i < NCIRCS ;i++){\
        Circle currCircle = myCircle[i];
        for(int j = 0; j < NCIRCS; j++ ){
            if(currCircle.id != myCircle[j].id){

                float dis = currCircle.loc.distance(myCircle[j].loc);

                if(dis - (currCircle.radius + myCircle[j].radius) < 0){
                    myCircle[j].incollision = true;
                }
                else{
                    myCircle[j].incollision = false;
                }
            }

        }
        

    }




   
    
    
}

void ofApp::draw(){

    for(int i =0; i < NCIRCS ;i++){
        myCircle[i].drawMe();

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
