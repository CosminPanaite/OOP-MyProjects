//
//

#include "Image.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


Image::Image() {
    /// default constructor

    m_width = 0;
    m_height = 0;
    m_data = nullptr;
}


Image::Image(unsigned int width, unsigned int height, const int *m_data) {
    /// constructor with parametres

    m_width = width;
    m_height = height;
    this->m_data = new int[m_width * m_height];
    for (int i = 0; i < m_width * m_height; i++)
        this->m_data[i] = m_data[i];
}

Image::Image(const Image &other) {
    /// copy constructor

    m_width = other.m_width;
    m_height = other.m_height;
    this->m_data = new int[other.m_width * other.m_height];
    for (int i = 0; i < m_width * m_height; i++)
        this->m_data[i] = m_data[i];
}

Image::~Image() {
    /// destructor
    release();

}

void Image::release() {
    if (m_data != nullptr) {
        delete[] m_data;
        m_data = nullptr;
    }
    m_height = 0;
    m_width = 0;  ///dezalocate and free the memory of our image
}

Image &Image::operator=(const Image &other) {
    /// overloading of self-assignment

    if (this != &other) {
        m_width = other.m_width;
        m_height = other.m_height;
        for (int i = 0; i < m_width * m_height; i++)
            this->m_data[i] = other.m_data[i];
    }
    return *this;
}


Image Image::operator+(const Image &image) const {
    int i;
    unsigned int new_m_width = m_width + image.m_width;
    unsigned int new_m_height = m_height + image.m_height;
    for (i = 0; i < m_width * m_height; i++)
        m_data[i] = m_data[i] + image.m_data[i];
    return Image(new_m_width, new_m_height, m_data);
}

Image Image::operator-(const Image &image) const {
    int i;
    unsigned int new_m_width = m_width + image.m_width;
    unsigned int new_m_height = m_height + image.m_height;
    for (i = 0; i < m_width * m_height; i++)
        m_data[i] -= image.m_data[i];
    return Image(new_m_width, new_m_height, m_data);

}

Image Image::operator*(const Image &image) const {
    int i;
    unsigned int new_m_width = m_width + image.m_width;
    unsigned int new_m_height = m_height + image.m_height;
    for (i = 0; i < m_width * m_height; i++)
        m_data[i] *= image.m_data[i];
    return Image(new_m_width, new_m_height, m_data);
}


unsigned int Image::getWidth() const {
    return m_width;
}

unsigned int Image::getHeight() const {
    return m_height;
}

void Image::setHeight(unsigned int new_height) {
    m_height = new_height;
}

void Image::setWidth(unsigned int new_width) {
    m_width = new_width;
}


bool Image::load(char imagePath[100]) {
    // A function that loads a picture from a file into an pgm object
    // returns true or false
    ifstream f(imagePath);
    unsigned int b = 0, c = 0, max = 0;
    char s[4];
    f >> s >> b >> c >> max;
    m_width = b;
    m_height = c;
    m_data = new int[b * c];
    for (int i = 0; i <= b * c; i++)
        f >> m_data[i];
    f.close();
    return true;
}

bool Image::save(char imagePath[100]) {
    // A function that saves the stored picture in the Image object into a file
    //  returns true or false depending on the success or lack thereof the operation
    ofstream g(imagePath);
    g << "P2" << "\n";
    g << m_width << " " << m_height << "\n";
    g << 255 << "\n";
    for (int i = 0; i < m_height * m_width; i++) {
        g << m_data[i] << " ";
        if (i && i % 15 == 0)
            g << endl;
    }
    g.close();
    return true;
}

bool Image::isEmpty() const {
    if (!m_width || !m_height)
        return true;
    return false;
}

ostream &operator<<(ostream &os, const Image &dt) {
    cout << "The image with the width of" << dt.m_width << " and the height of " << dt.m_height << " is:" << endl;
    for (int i = 0; i < dt.m_width * dt.m_height; i++) {
        cout << dt.m_data[i] << " ";
        if (i % 15 == 0 && i)
            cout << endl;
    }
    return os;
}


bool Image::isInBounds(Rectangle &roiRect) const {
    if (roiRect.getRectWidth() >= m_width || roiRect.getRectWidth() < 0 || roiRect.getRectHeight() >= m_height ||
        roiRect.getRectHeight() < 0)
        return false;
    return true;

}

bool Image::isInBounds(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const {
    if (m_width < width + x)
        return false;
    if (m_height < height + y)
        return false;
    return true;
}

bool Image::getROI(Image &roiImg, Rectangle &roiRect) const {
    if (!isInBounds(roiRect))
        return false;
    else {
        int *data = new int[roiRect.getRectHeight() * roiRect.getRectWidth()];
        for (int i = 0; i < roiRect.getRectHeight() * roiRect.getRectWidth(); i++)
            data[i] = roiImg.m_data[i];
        Image i1(roiRect.getRectWidth(), roiRect.getRectHeight(), data);
        roiImg = i1;
        bool saved = roiImg.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\getROIUsingRectangleClass.pgm");
        delete[] data;
        return saved;
    }
}

bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) const {
    if (!isInBounds(x, y, width, height))
        return false;
    else {
        int *data = new int[width * height];
        for (unsigned int i = x * y; i < width * height; i++)
            data[i] = roiImg.m_data[i];
        Image i1(width, height, data);
        roiImg = i1;
        bool saved = roiImg.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\getRectangleROI.pgm");
        delete[] data;
        return saved;
    }
}

void Image::setPixels(int p1, int p2, int h, int w, int pixel) {
    for (int i = p1 * p2; i < w * h; i++)
        m_data[i] = pixel; /// This function is setting new values for pixels in form of a rectangle formed by 4 positions p1,p2,h and w;

}

void Image::setLineOfPixels(Point &p1, Point &p2, int k, int pixel) {
    /// p1->pos 1 , p2 pos 2 , k ->remainder
    int line = int(sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2)));
    for (int i = 0; i < line * line; i++)
        if (i % 16 == k)
            m_data[i] = pixel;  /// This function helps me with setting new values for pixels in the form of line depening on
            ///remainder of i % 16

}

void Image::setDots(Point &p1, Point &p2, int k, int pixel) {
    int line = int(sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2)));///euclidian ditance for line
    for (int i = 0; i < line * line; i++)
        if (i % 100 == k)
            m_data[i] = pixel; /// using it for drawing points
}


void Image::setPixelAtGivenPosition(int position, int pixel) {
    if (pixel > 0 && pixel < 255)
        m_data[position] = pixel;   /// this function gives a new value for a pixel but it shold remain in the [0,255]
}

int Image::getPixel(int position) const {
    return m_data[position]; ///i obtain a value of a pixel at a specified position
}

Image Image::zeros(unsigned int width, unsigned int height) {
    int i;
    for (i = 0; i < width * height; i++)
        m_data[i] = 0;
    return Image(width, height, m_data); /// i only put 0 pixels in image
}

Image Image::ones(unsigned int width, unsigned int height) {
    int i;
    for (i = 0; i < width * height; i++)
        m_data[i] = 1;
    return Image(width, height, m_data); ////// i only put 1 pixels in image
}