//
// Created by Cosmin on 28/03/2021.
//

#include "ImageProcessing.h"

ImageProcessing::ImageProcessing() {
    alpha = 1;
    beta = 0;
    gamma = 0;
}

ImageProcessing::~ImageProcessing() {
    alpha = -1;
    beta = -1;
    gamma = -1;
}

ImageProcessing::ImageProcessing(int alpha, int beta, int gamma) {
    this->alpha = alpha;
    this->beta = beta;
    this->gamma = gamma;
}

void ImageProcessing::adjustBrightnessConstrast(Image &img, int alpha1, int beta1) {
    int i, value = 0;
    for (i = 0; i < img.getWidth() * img.getHeight(); i++) {
        value = img.getPixel(i);
        if (value * alpha1 + beta1 < 255)
            img.setPixelAtGivenPosition(i, value * alpha1 + beta1);
        else
            img.setPixelAtGivenPosition(i, value);
    }
    bool saved = img.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\adjustLena.pgm");
    if (saved)
        cout << "The image has been successfully adjusted" << endl;
    else cout << "Retry" << endl;
}

void ImageProcessing::gammaCorrection(Image &img, int gamma1, int correction) {
    bool saved;
    int value, i;
    if (gamma1 == 1) {
        saved = img.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\gammaCorrectionLena.pgm");
        if (saved)
            cout << "The image has been successfully gamma-corrected" << endl;
        else cout << "Retry" << endl;
    } else if (gamma1 < 1) {
        for (i = 0; i < img.getWidth() * img.getHeight(); i++) {
            value = img.getPixel(i);
            if (value - correction > 0)
                img.setPixelAtGivenPosition(i, value - correction);
            else
                img.setPixelAtGivenPosition(i, value);
        }
        saved = img.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\gammaCorrectionLena.pgm");
        if (saved)
            cout << "The image has been successfully  gamma-corrected" << endl;
        else cout << "Retry" << endl;


    } else {
        for (i = 0; i < img.getWidth() * img.getHeight(); i++) {
            value = img.getPixel(i);
            if (value + correction < 255)
                img.setPixelAtGivenPosition(i, value + correction);
            else
                img.setPixelAtGivenPosition(i, value);
        }
        saved = img.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\gammaCorrectionLena.pgm");
        if (saved)
            cout << "The image has been successfully  gamma-corrected" << endl;
        else cout << "Retry" << endl;

    }
}

void ImageProcessing::ImageConvolution(Image &img, Image &kernel) {
    int i, j;
    int newPixel;
    for (i = kernel.getWidth() * kernel.getWidth();
         i < img.getWidth() * img.getHeight() - kernel.getWidth() * kernel.getWidth(); i++) {
        for (j = 0; j < kernel.getWidth() * kernel.getWidth(); j++) {
            newPixel = newPixel + img.getPixel(int(i + j)) * kernel.getPixel(int(j));
            img.setPixelAtGivenPosition(i, newPixel);
        }
    }
    bool saved = img.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\convolutionLena.pgm");
    if (saved)
        cout << "The image has been successfully convoluted" << endl;
    else cout << "Retry" << endl;
}