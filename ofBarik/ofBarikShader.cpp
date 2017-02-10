
#include "ofBarikShader.h"

ofImage ofBarikShader::convertFBOtoImage(ofFbo fbo) {
    ofImage imgmagic;
    ofPixels hiResPixels;
    fbo.readToPixels(hiResPixels);
     imgmagic.setFromPixels(hiResPixels);
    return imgmagic;
}

void ofBarikShader::drawAlphaMask(int x, int y, int w, int h) {
    maskFbo_alphamask.begin();
    ofClear(255, 255, 255, 255);
    imagetomask_alphamask.draw(0, 0);
    maskFbo_alphamask.end();
    
    //------------------------------------------- draw to final fbo.
    fbo_alphamask.begin();
    ofClear(0, 0, 0,255);
    
    shader_alphamask.begin();
    shader_alphamask.setUniformTexture("texturemaskguide", imagemaskguide_alphamask, 1); //2
    shader_alphamask.setUniformTexture("imageMask", maskFbo_alphamask.getTextureReference(), 2);//4
    
    // we are drawing this fbo so it is used just as a frame.
    maskFbo_alphamask.draw(0, 0);
    shader_alphamask.end();
    fbo_alphamask.end();
    
    //-------------------------------------------
    fbo_alphamask.draw(x,y,w,h);
}

void ofBarikShader::drawOverLay(int x, int y, int w, int h) {
    maskFbo_overlay.begin();
    ofClear(255, 255, 255, 255);
    imgback_overlay.draw(0, 0);
    maskFbo_overlay.end();
    
    //------------------------------------------- draw to final fbo.
    fbo_overlay.begin();
    ofClear(0, 0, 0,255);
    
    shader_overlay.begin();
    shader_overlay.setUniformTexture("texturefront", imafront_overlay, 1); //2
    shader_overlay.setUniformTexture("textureback", maskFbo_overlay.getTextureReference(), 2);//4
    
    // we are drawing this fbo so it is used just as a frame.
    maskFbo_overlay.draw(0, 0);
    shader_overlay.end();
    fbo_overlay.end();
    
    //-------------------------------------------
    fbo_overlay.draw(x,y,w,h);
}

void ofBarikShader::setupShaderAlphaMask(ofImage imgtomask, ofImage imgmaskguide, int w, int h) {
#ifdef TARGET_OPENGLES
    shader_alphamask.load("shadersES2/alphamask");
#else
    if(ofIsGLProgrammableRenderer()){
        shader_alphamask.load("shadersGL3/alphamask");
    }else{
        shader_alphamask.load("shadersGL2/alphamask");
    }
#endif
    imagemaskguide_alphamask = imgmaskguide;
    imagetomask_alphamask = imgtomask;
    fbo_alphamask.allocate(w, h);
    maskFbo_alphamask.allocate(w, h);
}

void ofBarikShader::setupShaderOverLay(ofImage imgback, ofImage imgfront, int w, int h) {
#ifdef TARGET_OPENGLES
    shader_overlay.load("shadersES2/overlay");
#else
    if(ofIsGLProgrammableRenderer()){
        shader_overlay.load("shadersGL3/overlay");
    }else{
        shader_overlay.load("shadersGL2/overlay");
    }
#endif
    imafront_overlay = imgfront;
    imgback_overlay = imgback;
    fbo_overlay.allocate(w, h);
    maskFbo_overlay.allocate(w, h);
}

