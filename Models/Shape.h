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
    HorizontalRight,
    HorizontalLeft,
    VerticalUp,
    VerticalDown
};

enum class ShapeType{
    Cube,
    Long,
    Triangle,
    Harpoon
};

struct Point{
    int x, y;
    Point(int _x, int _y) : x {_x}, y {_y} { };
    Point() : x {0}, y {0} { }
};

class Shape {
private:
    Point _point;
    Rotation _rotation;
    std::vector<Point> _placement;

    bool check_space(Matrix& matrix);
    bool check_collision(Direction direction, Matrix& matrix);
    void move_coordinates(Direction direction);
    Matrix add_to_matrix(Matrix& matrix);
public:
    explicit Shape(ShapeType type) : _point(), _rotation {Rotation::HorizontalRight} {
        switch (type) {

            case ShapeType::Cube:
                _placement = { Point{ 0, 0}, Point{ 0, 1}, Point{ 1, 0}, Point{ 1, 1}};
                break;
            case ShapeType::Long:
                _placement = { Point { 0, 0 }, Point { 1, 0 }, Point { 2, 0 }, Point { 4, 0 }};
                break;
            case ShapeType::Triangle:
                throw std::exception();
                break;
            case ShapeType::Harpoon:
                throw std::exception();
                break;
            default:
                _placement = { Point{ 0, 0}, Point{ 0, 1}, Point{ 1, 0}, Point{ 1, 1}};
                break;
        }
    };

    bool move(Matrix& matrix);
    bool move_horizontal(Matrix& matrix, bool isRight = true);
};

#endif //SRC_SHAPE_H