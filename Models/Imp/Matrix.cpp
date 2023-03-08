//
// Created by ghuba on 28.02.2023.
//

#include <unordered_set>
#include "../Matrix.h"

void Matrix::delete_line(const unsigned int line) {

    for (int i = 0; i < width; ++i) {

        this->matrix[line][i] = false; //delete element

        for (auto j = line; j < (height - 1); ++j) { //and push it on top
            std::swap(this->matrix[j][i], this->matrix[j+1][i]);
        }
    }
}

bool Matrix::get_point(const int x,const int y) {
    return this->matrix[x][y];
}

void Matrix::set_point(int x, int y, bool value) {
    this->matrix[x][y] = value;
}

int Matrix::get_full_line() {
    for (int i = 0; i < height; ++i) {
        bool result = this->matrix[i][0] && this->matrix[i][1] && this->matrix[i][2] && this->matrix[i][3] && this->matrix[i][4];
        if(result)
            return i;
    }
    return -1;
}
