//
//

#include "Rectangle.h"

Rectangle::Rectangle() {
    x_top_left = 0;
    y_top_left = 0;
    rect_width = 0;
    rect_width = 0;

}

Rectangle::Rectangle(int x_top_left, int y_top_left, unsigned int rect_width, unsigned int rect_height) {
    this->x_top_left = x_top_left;
    this->y_top_left = y_top_left;
    this->rect_width = rect_width;
    this->rect_height = rect_height;
}

Rectangle::~Rectangle() {
    x_top_left = -1;
    y_top_left = -1;
    rect_width = -1;
    rect_width = -1;

}

int Rectangle::getXTopLeft() const {
    return x_top_left;
}

int Rectangle::getYTopLeft() const {
    return y_top_left;
}

unsigned int Rectangle::getRectWidth() const {
    return rect_width;
}

unsigned int Rectangle::getRectHeight() const {
    return rect_height;
}