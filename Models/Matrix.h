//
// Created by ghuba on 28.02.2023.
//

#ifndef SRC_MATRIX_H
#define SRC_MATRIX_H


class Matrix {
public:
    Matrix() = default;
    void delete_line(unsigned int line);
    bool get_point(int x, int y);
private:
    static const int _width { 5 };
    static const int _height { 10 };
    bool matrix[_height][_width] { };
};


#endif //SRC_MATRIX_H
