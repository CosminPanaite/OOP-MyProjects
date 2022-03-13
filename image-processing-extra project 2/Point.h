//
//

#ifndef IMAGE_EXTRA_POINT_H
#define IMAGE_EXTRA_POINT_H


class Point {
private:
    int x, y;
public:
    Point();

    Point(int x, int y);

    ~Point();

    int getX() const;

    int getY() const;
};


#endif //IMAGE_EXTRA_POINT_H
