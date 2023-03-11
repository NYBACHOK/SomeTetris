//
// Created by ghuba on 08.03.2023.
//

#include <thread>
#include <chrono>
#include <iostream>
#include <random>
#include "../GameManager.h"

void GameManager::start_game() {
    start_drawing_matrix();
    process();
}

void GameManager::start_drawing_matrix() {

    drawing_thread = std::thread([this](){
        while (true){
            std::this_thread::sleep_for(std::chrono::milliseconds(REFRESH_RATE));

#if defined(WIN32) || defined(WIN64)
            system("cls");
#else
            system("clear");
#endif
            std::cout<< "-------------------------\n";

            Matrix matrix_with_shape = current_shape.add_to_matrix(this->_matrix);
            for (int i = 0; i < Matrix::height; ++i) {
                for (int j = 0; j < Matrix::width; ++j) {
                    if(matrix_with_shape.get_point(j, i)){
                        std::cout<<"X";
                    } else{
                        std::cout<<"O";
                    }
                }
                std::cout<<"\n";
            }
            std::cout<<"\n";

            if(current_shape.move(this->_matrix))
                continue;

            this->_matrix = matrix_with_shape;
            this->is_shape_exists = false;
        }
    });
    drawing_thread.detach();
}

void GameManager::process() {
    worker_thread = std::thread([this]() {
        char key_pressed;
        while (true){
            static std::random_device generator;
            static std::uniform_int_distribution<int> distribution(1,5);
            int dice_roll = distribution(generator);

            if(!is_shape_exists){
                current_shape = Shape(static_cast<ShapeType>(dice_roll));
                is_shape_exists = true;
            }

        }
    });
    worker_thread.detach();
}


