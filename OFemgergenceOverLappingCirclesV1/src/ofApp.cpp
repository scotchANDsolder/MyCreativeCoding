#include "ofApp.h"


void ofApp::setup(){
    ofSetCircleResolution(500);
    ofSetBackgroundColor(0);

    int value;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &value);   //Returns 1 value
    float total = 11 + 8.5;
    w = (8.5 / total) * (value-1);
    h = (11.0 / total) * (value-1);
    largeOffscreenImage.allocate(w, h, GL_RGBA);
    

    

}

void ofApp::update(){
    

   

    
    
}

void ofApp::draw(){
    largeOffscreenImage.begin();
    
    ofClear(255,255,255,255);
    


   for(int i =0; i < NCIRCS ;i++){
    ofSetColor(255,0,0,30);
       myCircle[i].drawMe();

   }
    
    // for(int i =0; i < NCIRCS ;i++){
        
    //     for(int j = 0; j < NCIRCS; j++ ){
            
    //         if(i != j){

    //             float overlap = myCircle[i].loc.distance(myCircle[j].loc) - (myCircle[i].radius + myCircle[j].radius);
                
    //             if(overlap < 0){
    //                 float midx;
    //                 float midy;
    //                 midx = (myCircle[i].loc.x + myCircle[j].loc.x) / 2;
    //                 midy = (myCircle[i].loc.y + myCircle[j].loc.y) / 2;
    //                 ofNoFill();
    //                 ofSetColor(255,0,0,30);
    //                 overlap*=-1;
    //                 ofDrawCircle(midx, midy, overlap);
    //             }
    //         }

    //     }
        
        
    //    myCircle[i].updateMe();
        

    // }
    


    
    largeOffscreenImage.end();

    

    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f'){
        ofToggleFullscreen();

    }

    if(key == 'x'){
    
    
    ofRectangle bounds(0,0, ofGetWidth(), ofGetHeight());
    ofRectangle target(0,0,w,h);
    target.scaleTo(bounds);
    
    largeOffscreenImage.draw(target);
        ofPixels p;
        largeOffscreenImage.readToPixels(p);
        ofSaveImage(p, ofGetTimestampString() + ".png");
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
