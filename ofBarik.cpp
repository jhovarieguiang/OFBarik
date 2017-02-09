//
//  ofBarik.cpp
//  ImageCombind
//
//  Created by Jhovarie on 2/9/17.
//
//

#include "ofBarik.hpp"

void ofImageLib::TestMethod() {
    
}

ofImage ofImageLib::blurImage(ofImage img,int blur) {
    cvimg.setFromPixels(img.getPixels());
    cvimg.blur(blur);
    img.setFromPixels(cvimg.getPixels());
    return img;
}
