//
// Created by ghuba on 08.03.2023.
//

#ifndef SRC_GAMEMANAGER_H
#define SRC_GAMEMANAGER_H


#include "Matrix.h"
#include <thread>

class GameManager {
public:
    GameManager() : _matrix(), drawer()  {}
    void start_game();
private:
    Matrix _matrix;
    std::thread drawer;

    void start_drawing_matrix();
};


#endif //SRC_GAMEMANAGER_H
