//
//

#ifndef IMAGE_EXTRA_IMAGEPROCESSING_H
#define IMAGE_EXTRA_IMAGEPROCESSING_H


#include "Image.h"

class ImageProcessing {
private:
    int alpha;
    int beta;
    int gamma;
public:
    ImageProcessing();

    ImageProcessing(int alpha, int beta, int gamma);

    ~ImageProcessing();

    void adjustBrightnessConstrast(Image &img, int alpha, int beta);

    void gammaCorrection(Image &img, int gamma, int correction);

    void ImageConvolution(Image &img, Image &kernel);
};


#endif //IMAGE_EXTRA_IMAGEPROCESSING_H
