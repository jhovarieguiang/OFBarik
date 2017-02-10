#include "ofMain.h"
#include "ofxOpenCv.h"

class ofBarikShader {
private:
    ofxCvColorImage cvimg;
    
    //for alphamask
    ofImage imagemaskguide_alphamask;
    ofImage imagetomask_alphamask;
    ofFbo fbo_alphamask;
    ofFbo maskFbo_alphamask;
    ofShader shader_alphamask;
    
    //for overlay
    ofImage imafront_overlay;
    ofImage imgback_overlay;
    ofFbo fbo_overlay;
    ofFbo maskFbo_overlay;
    ofShader shader_overlay;
public:
    ofImage convertFBOtoImage(ofFbo fbo);
    /*
    void drawAlphaMask(int x, int y,int w, int h);
    void drawOverLay(int x, int y,int w, int h);
    void setupShaderAlphaMask(ofImage imgtomask, ofImage imgmaskguide, int w, int h);
    void setupShaderOverLay(ofImage imgback, ofImage imgfront, int w, int h);
    */
    
   ofImage createAlphaMask(ofImage imgtomask, ofImage imgmaskguide, int w, int h);
   ofImage createOverLay(ofImage imgback, ofImage imgfront, int w, int h);
};

