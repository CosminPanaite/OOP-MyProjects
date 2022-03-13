//
// Created by Cosmin on 28/03/2021.
//

#include "DrawShapes.h"

DrawShapes::DrawShapes() {
    command = 0;
}

DrawShapes::DrawShapes(int command) {
    this->command = command;
}

DrawShapes::~DrawShapes() {
    command = -1;
}

int DrawShapes::getCommand() const {
    return command;
}

void DrawShapes::drawRectangle(Image &img, Rectangle &r, int color) {

    if (color < 0 || color > 255) {
        cout << "The pixel grayscale will be resized to 1!" << endl;
        color = 1;
    }
    img.setPixels(r.getXTopLeft(), r.getYTopLeft(), r.getRectHeight(), r.getRectWidth(), color); /// here i draw the rectangle with
    /// the aid of Rectangle class and the function set pixel
    bool saved = img.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\DrawRectangle.pgm");
    cout << endl;
    if (saved)
        cout << "The rectangle has been drawn successfully!" << endl;
}

void DrawShapes::drawRectangle(Image &img, Point &tl, Point &br, int color) {
    if (color < 0 || color > 255) {
        cout << "The pixel grayscale will be resized to 1!" << endl;
        color = 1;
    }
    img.setPixels(tl.getX(), tl.getY(), br.getX(), br.getY(), color);
    bool saved = img.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\DrawRectangle.pgm");
    cout << endl;
    if (saved)
        cout << "The rectangle using the Point Class has been drawn successfully!" << endl;
}

void DrawShapes::drawLine(Image &img, Point &p1, Point &p2, int color) {
    if (color < 0 || color > 255) {
        cout << "The pixel grayscale will be resized to 1!" << endl;
        color = 1;
    }
    img.setLineOfPixels(p1, p2, 7, color);
    bool saved = img.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\DrawLines.pgm");
    cout << endl;
}

void DrawShapes::drawDots(Image &img, Point &p1, Point &p2, int color) {
    if (color < 0 || color > 255) {
        cout << "The pixel grayscale will be resized to 1!" << endl;
        color = 1;
    }
    img.setDots(p1, p2, 5, color);
    bool saved = img.save("C:\\Users\\Cosmin\\CLionProjects\\image_extra\\PGM_FILES\\DrawDots.pgm");
    cout << endl;
    if (saved)
        cout << "The dots have been drawn successfully!" << endl;
}
