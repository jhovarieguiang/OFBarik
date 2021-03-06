
#include "ofBarikShader.h"

ofImage ofBarikShader::convertFBOtoImage(ofFbo fbo) {
    ofImage imgmagic;
    ofPixels hiResPixels;
    fbo.readToPixels(hiResPixels);
     imgmagic.setFromPixels(hiResPixels);
    return imgmagic;
}

ofImage ofBarikShader::createAlphaMask(ofImage imgtomask, ofImage imgmaskguide, int w, int h) {
    //setup FBO
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
    
    //draw FBO
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
    fbo_alphamask.draw(0,0,w,h);
    
    return convertFBOtoImage(fbo_alphamask);
}

ofImage ofBarikShader::createOverLay(ofImage imgback, ofImage imgfront, int w, int h) {
    //setup FBO
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
    
    //draw FBO
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
    fbo_overlay.draw(0,0,w,h);
    return convertFBOtoImage(fbo_overlay);
}

ofImage ofBarikShader::createAlphaBlend(ofImage imgback, ofImage imgfront, float mixturePercent,int w, int h) {
    //setup FBO
#ifdef TARGET_OPENGLES
    shader_alphablend.load("shadersES2/alphablend");
#else
    if(ofIsGLProgrammableRenderer()){
        shader_alphablend.load("shadersGL3/alphablend");
    }else{
        shader_alphablend.load("shadersGL2/alphablend");
    }
#endif
    imafront_alphablend = imgfront;
    imgback_alphablend = imgback;
    fbo_alphablend.allocate(w, h);
    maskFbo_alphablend.allocate(w, h);
    
    //draw FBO
    maskFbo_alphablend.begin();
    ofClear(255, 255, 255, 255);
    imgback_alphablend.draw(0, 0);
    maskFbo_alphablend.end();
    
    //------------------------------------------- draw to final fbo.
    fbo_alphablend.begin();
    ofClear(0, 0, 0,255);
    
    shader_alphablend.begin();
    
    shader_alphablend.setUniform1f("mixturePercent", mixturePercent);
    shader_alphablend.setUniformTexture("texturefront", imafront_alphablend, 1); //2
    shader_alphablend.setUniformTexture("textureback", maskFbo_alphablend.getTextureReference(), 2);//4
    
    // we are drawing this fbo so it is used just as a frame.
    maskFbo_alphablend.draw(0, 0);
    shader_alphablend.end();
    fbo_alphablend.end();
    
    //-------------------------------------------
    fbo_alphablend.draw(0,0,w,h);
     return convertFBOtoImage(fbo_alphablend);
}
