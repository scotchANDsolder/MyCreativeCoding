#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetCircleResolution(1000);
    ofSetBackgroundColor(0);
    ofSetBackgroundAuto(false);

    
    // assume our target is 8.5x11 -- we can caluate the w/h of the largest
    // texture at that aspect ratio
    
    int value;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &value);   //Returns 1 value
    float total = 11 + 8.5;
    w = (8.5 / total) * (value-1);
    h = (11.0 / total) * (value-1);
    largeOffscreenImage.allocate(w, h, GL_RGBA);

    for (int i = 0; i < NCIRCS; i++){
        myCircle.push_back(Circle(w,h));
        
    }
    
    //ofClear(0,0,0,255);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
    largeOffscreenImage.begin();
    ofSetBackgroundColor(0);
    ofSetBackgroundAuto(false);
    
    

    // for (int i = 0; i < NCIRCS; i++){
    //      myCircle[i].drawMe();
    //  }



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
                    ofSetColor(255,0,0,255);
                    overlap*=-1;
                    ofDrawEllipse(midx, midy, overlap,overlap);

                }
            }

        }
        
        
       myCircle[i].updateMe();
        

    }


    












    largeOffscreenImage.end();
    
    ofRectangle bounds(0,0, ofGetWidth(), ofGetHeight());
    ofRectangle target(0,0,w,h);
    target.scaleTo(bounds);
    
    largeOffscreenImage.draw(target);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
   
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