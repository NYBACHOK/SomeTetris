//
// Created by ghuba on 28.02.2023.
//

#include <unordered_set>
#include "../Matrix.h"

void Matrix::delete_line(const unsigned int line) {

    for (int i = 0; i < _width; ++i) {

        this->matrix[line][i] = false; //delete element

        for (auto j = line; j < (_height - 1); ++j) { //and push it on top
            std::swap(this->matrix[j][i], this->matrix[j+1][i]);
        }
    }
}

bool Matrix::get_point(const int x,const int y) {
    return this->matrix[x][y];
}
