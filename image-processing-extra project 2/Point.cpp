//
// Created by Cosmin on 28/03/2021.
//

#include "Point.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::~Point() {
    x = -1;
    y = -1;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}