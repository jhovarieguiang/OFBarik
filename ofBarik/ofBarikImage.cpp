//
//  ofImageLib.cpp
//  TestingLang
//
//  Created by Jhovarie on 2/7/17.
//
//

#include "ofBarikImage.h"

void ofBarikImage::Test() {
    
}

ofImage ofBarikImage::blurImage(ofImage img,int blur) {
    cvimg.setFromPixels(img.getPixels());
    cvimg.blur(blur);
    img.setFromPixels(cvimg.getPixels());
    return img;
}

ofImage ofBarikImage::overlayImage (ofImage img1, ofImage img2, int img2x, int img2y) {
    int w = img1.getWidth();
    int h = img1.getHeight();
    
    for(int x = 0; x < w; x++) {
        for(int y = 0; y < h; y++) {
            ofColor color= img1.getColor(x, y);
            if(x > img2x && x < img2.getWidth() + img2x &&
               y > img2y && y < img2.getHeight() + img2y) {
                color= img2.getColor(x-img2x, y-img2y);
            }
            img1.setColor(x, y, color);
        }
    }
    img1.update();
    return img1;
}
