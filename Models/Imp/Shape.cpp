//
// Created by ghuba on 28.02.2023.
//
#include "../Shape.h"

void Shape::move_coordinates(Direction direction) {
    switch (direction) {
        case Direction::Down:
            this->y++;
            break;
        case Direction::Left:
            this->x--;
            break;
        case Direction::Right:
            this->x++;
            break;
        default:
            break;
    }
}

bool Shape::check_space(Matrix& matrix) {
    for(Point p: this->placement)
        if(matrix.get_point(p.x, p.y))
            return false;

    return true;
}

Matrix Shape::add_to_matrix(Matrix& matrix) {
    if(!check_space(matrix))
        throw std::exception{};

    for(auto point : this->placement)
        matrix.set_point(point.x, point.y);

    return matrix;
}

void Shape::move(Direction direction, Matrix &matrix) {

}
