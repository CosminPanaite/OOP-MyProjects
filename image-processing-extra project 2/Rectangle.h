//
// Created by Cosmin on 28/03/2021.
//

#ifndef IMAGE_EXTRA_RECTANGLE_H
#define IMAGE_EXTRA_RECTANGLE_H


class Rectangle {
private:
    int x_top_left;
    int y_top_left;
    unsigned int rect_width;
    unsigned int rect_height;
public:
    Rectangle();

    Rectangle(int x_top_left, int y_top_left, unsigned int rect_width, unsigned int rect_height);

    ~Rectangle();

    int getXTopLeft() const;

    int getYTopLeft() const;

    unsigned int getRectHeight() const;

    unsigned int getRectWidth() const;


};


#endif //IMAGE_EXTRA_RECTANGLE_H
