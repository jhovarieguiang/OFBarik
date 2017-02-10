#include "ofMain.h"
#include "ofxOpenCv.h"

class ofBarikShader {
private:
    ofxCvColorImage cvimg;
    
    ofImage imagemaskguide2;
    ofImage imagetomask2;
    ofFbo fbo2;
    ofFbo maskFbo2;
    ofShader shader2;
    
public:
    ofImage convertFBOtoImage(ofFbo fbo);
    void draw(int x, int y,int w, int h);
    void setupShader(ofImage imgtomask, ofImage imgmaskguide, int w, int h);
};

