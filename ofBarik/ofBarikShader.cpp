
#include "ofBarikShader.h"

void ofBarikShader::setupShader(ofImage imgtomask, ofImage imgmaskguide, int w, int h) {
#ifdef TARGET_OPENGLES
    shader2.load("shadersES2/alphamask");
#else
    if(ofIsGLProgrammableRenderer()){
        shader2.load("shadersGL3/alphamask");
    }else{
        shader2.load("shadersGL2/alphamask");
    }
#endif
    
    /*
    // image.loadImage("mask.png");
    imgmaskguide.loadImage("mask.png");
    // imagemaskguide.loadImage("maskred.png");
    // imageMask.loadImage("mask.jpg");
    // image.loadImage("topLayer.png");
    // imageMask.loadImage("mask.png");
    
    // imagetomask.loadImage("topLayer.png");
    // bottomLayer
    imgtomask.loadImage("bottomLayer.png");
    */
    
    imagemaskguide2 = imgmaskguide;
    imagetomask2 = imgtomask;
    
    fbo2.allocate(w, h);
    maskFbo2.allocate(w, h);
    
}

void ofBarikShader::draw(int x, int y, int w, int h) {
    maskFbo2.begin();
    ofClear(255, 255, 255, 255);
    imagetomask2.draw(0, 0);
    maskFbo2.end();
    
    //------------------------------------------- draw to final fbo.
    fbo2.begin();
    ofClear(0, 0, 0,255);
    
    shader2.begin();
    shader2.setUniformTexture("texturemaskguide", imagemaskguide2, 1); //2
    shader2.setUniformTexture("imageMask", maskFbo2.getTextureReference(), 2);//4
    
    // we are drawing this fbo so it is used just as a frame.
    maskFbo2.draw(0, 0);
    shader2.end();
    fbo2.end();
    
    //-------------------------------------------
    fbo2.draw(x,y,w,h);
}

