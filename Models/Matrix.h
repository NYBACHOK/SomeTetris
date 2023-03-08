//
// Created by ghuba on 28.02.2023.
//

#ifndef SRC_MATRIX_H
#define SRC_MATRIX_H


class Matrix {
public:
    static const int width {5 };
    static const int height {10 };

    Matrix() = default;
    void delete_line(unsigned int line);
    int get_full_line();
    bool get_point(int x, int y);
    void set_point(int x, int y, bool value = true);
private:
    bool matrix[height][width] { };
};


#endif //SRC_MATRIX_H
