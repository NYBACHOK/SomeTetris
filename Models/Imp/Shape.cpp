//
// Created by ghuba on 28.02.2023.
//
#include "../Shape.h"

void Shape::move_coordinates(Direction direction) {
    switch (direction) {
        case Direction::Down:
            this->_point.y++;
            break;
        case Direction::Left:
            this->_point.x--;
            break;
        case Direction::Right:
            this->_point.x++;
            break;
        default:
            static_assert("Impossible direction to movement");
    }
}

bool Shape::check_space(Matrix& matrix) {
    for(Point p: this->_placement)
        if(matrix.get_point(p.x, p.y))
            return false;

    return true;
}

Matrix Shape::add_to_matrix(Matrix& matrix) {
    if(!check_space(matrix))
        throw std::exception{};

    for(auto point : this->_placement)
        matrix.set_point(point.x, point.y);

    return matrix;
}

bool Shape::check_collision(Direction direction, Matrix &matrix) {

    int xKoef {0}, yKoef {0};

    switch (direction) {
        case Direction::Down:
            yKoef=1;
            break;
        case Direction::Left:
            xKoef = -2;
            break;
        case Direction::Right:
            xKoef = 1;
            break;
        default:
            static_assert("Impossible direction to movement");
    }

    for(Point& point: _placement){
        int x = this->_point.x+point.x+xKoef;
        int y = this->_point.y+point.y+yKoef;
        if (matrix.get_point(x, y))
            return true;
    }

    return false;
}

bool Shape::move(Matrix &matrix) {
    if(check_collision(Direction::Down,matrix))
        return false;

    move_coordinates(Direction::Down);

    return true;
}

bool Shape::move_horizontal(Matrix &matrix, bool isRight) {
    Direction direction = isRight ? Direction::Right : Direction::Left;
    if(check_collision(direction,matrix))
        return false;

    move_coordinates(direction);

    return true;
}


