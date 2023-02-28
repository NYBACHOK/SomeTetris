//
// Created by ghuba on 28.02.2023.
//

#ifndef SRC_CUBE_H
#define SRC_CUBE_H


#include "Matrix.h"
#include "Shape.h"

class Cube : public Shape{
public:
    Cube() {
        placement = { Point{ 0, 0}, Point{ 0, 1}, Point{ 1, 0}, Point{ 1, 1}};
    };
    Matrix add_to_matrix(Matrix& matrix);
};


#endif //SRC_CUBE_H
