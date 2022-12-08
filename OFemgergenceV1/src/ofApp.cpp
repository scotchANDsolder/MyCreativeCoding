#include "ofApp.h"


void ofApp::setup(){
    ofSetCircleResolution(500);
    ofSetBackgroundColor(60);
    

    

}

void ofApp::update(){
    

    for(int i =0; i < NCIRCS ;i++){
        
        for(int j = 0; j < NCIRCS; j++ ){
            
            if(i != j){

                float dis = myCircle[i].loc.distance(myCircle[j].loc);
                //cout<<dis - (currCircle.radius + myCircle[j].radius)<<"\n";
                
                if(dis - (myCircle[i].radius + myCircle[j].radius) < 0){
                    myCircle[i].incollision = true;
                    myCircle[j].incollision = true;
                    break;
                }
                else{
                    myCircle[i].incollision = false;
                    myCircle[j].incollision = false;
                }
            }

        }
        
        
       myCircle[i].updateMe();
        

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
