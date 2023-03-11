//
// Created by ghuba on 08.03.2023.
//

#ifndef SRC_GAMEMANAGER_H
#define SRC_GAMEMANAGER_H


#include "Matrix.h"
#include "Shape.h"
#include <thread>

class GameManager {
public:
    GameManager() : _matrix(), drawing_thread(), current_shape(ShapeType::Cube)  {}
    void start_game();
private:
    const int REFRESH_RATE { 350 * 2 };
    bool is_shape_exists = true;
    Shape current_shape;

    Matrix _matrix;
    std::thread drawing_thread;
    std::thread worker_thread;

    void start_drawing_matrix();
    void process();
};


#endif //SRC_GAMEMANAGER_H
