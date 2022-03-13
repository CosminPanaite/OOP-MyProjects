//
//

#ifndef IMAGE_EXTRA_DRAWSHAPES_H
#define IMAGE_EXTRA_DRAWSHAPES_H

#include "Image.h"
#include "Point.h"
#include "Rectangle.h"

class DrawShapes {
private:
    int command;
public:
    DrawShapes();

    DrawShapes(int command);

    ~DrawShapes();

    int getCommand() const;

    void drawDots(Image &img, Point &p1, Point &p2, int color);

    void drawLine(Image &img, Point &p1, Point &p2, int color);

    void drawRectangle(Image &img, Rectangle &r, int color);

    void drawRectangle(Image &img, Point &tl, Point &br, int color);
};


#endif //IMAGE_EXTRA_DRAWSHAPES_H
