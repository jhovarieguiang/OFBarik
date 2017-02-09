//
//  ofImageLib.hpp
//  TestingLang
//
//  Created by Jhovarie on 2/7/17.
//
//

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofBarikImage {
private:
    ofxCvColorImage cvimg;
public:
    void Test();
    ofImage blurImage(ofImage img, int blur);
    ofImage overlayImage (ofImage img1, ofImage img2, int img2x, int img2y);
};
