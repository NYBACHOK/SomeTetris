//
// Created by ghuba on 28.02.2023.
//

#ifndef SRC_SHAPE_H
#define SRC_SHAPE_H

#include <vector>

enum class Direction : char {
    Up = 'w',
    Down = 's',
    Left = 'a',
    Right = 'd'
};

enum class Rotation{
    Vertical,
    Horizontal
};

struct Point{
    int x, y;
};

class Shape {
protected:
    int x;
    int y;
    Rotation rotation;
    std::vector<Point> placement;
public:
    Shape() : x{ 0 }, y { 0 }, rotation { Rotation::Horizontal} { };
    virtual ~Shape() = 0;
    virtual void move(Direction direction) = 0;
};

#endif //SRC_SHAPE_H