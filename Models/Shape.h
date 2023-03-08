//
// Created by ghuba on 28.02.2023.
//

#ifndef SRC_SHAPE_H
#define SRC_SHAPE_H

#include <vector>
#include "Matrix.h"

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
    Point() : x {0}, y {0} { }
};

class Shape {
private:
    Point _point;
    Rotation rotation;
    std::vector<Point> placement;

    bool check_space(Matrix& matrix);
    void move_coordinates(Direction direction);
    Matrix add_to_matrix(Matrix& matrix);
public:
    Shape() : _point(), rotation { Rotation::Horizontal} { };
    void move(Direction direction, Matrix& matrix);
};

#endif //SRC_SHAPE_H