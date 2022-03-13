//
//

#ifndef IMAGE_EXTRA_IMAGE_H
#define IMAGE_EXTRA_IMAGE_H

#include <iostream>
#include "Rectangle.h"
#include "Point.h"

using namespace std;

class Image {
private:
    unsigned int m_width;
    unsigned int m_height;
    int *m_data;

public:
    Image();

    Image(unsigned int width, unsigned int height, const int *m_data);

    Image(const Image &other);

    ~Image();

    bool load(char imagePath[]);

    bool save(char imagePath[]);

    Image &operator=(const Image &other);


    Image operator+(const Image &i) const;

    Image operator-(const Image &i) const;

    Image operator*(const Image &i) const;

    int getPixel(int position) const;

    unsigned int getWidth() const;

    unsigned int getHeight() const;

    void setWidth(unsigned int new_width);

    void setHeight(unsigned int new_height);

    void setPixels(int p1, int p2, int h, int w, int pixel);

    void release();

    bool isEmpty() const;

    friend ostream &operator<<(ostream &os, const Image &dt);

    Image zeros(unsigned int width, unsigned int height);

    Image ones(unsigned int width, unsigned int height);

    bool getROI(Image &roiImg, Rectangle &roiRect) const;

    bool isInBounds(Rectangle &roiRect) const;

    bool isInBounds(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const;

    bool getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) const;

    void setLineOfPixels(Point &p1, Point &p2, int k, int pixel);

    void setPixelAtGivenPosition(int position, int pixel);

    void setDots(Point &p1, Point &p2, int k, int pixel);

};


#endif //IMAGE_EXTRA_IMAGE_H
