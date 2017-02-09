//
//  ofBarik.hpp
//  ImageCombind
//
//  Created by Jhovarie on 2/9/17.
//
//

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofBarik {
private:
    ofxCvColorImage cvimg;
public:
    void TestMethod();
    ofImage blurImage(ofImage img, int blur);
};
