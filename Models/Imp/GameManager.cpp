//
// Created by ghuba on 08.03.2023.
//

#include <thread>
#include <chrono>
#include <iostream>
#include "../GameManager.h"

void GameManager::start_game() {
    start_drawing_matrix();
}

void GameManager::start_drawing_matrix() {

    drawer = std::thread([this](){
        while (true){
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout<< "-------------------------\n";
            for (int i = 0; i < Matrix::height; ++i) {
                for (int j = 0; j < Matrix::width; ++j) {
                    if(this->_matrix.get_point(j, i))
                        std::cout<<"X";
                    else
                        std::cout<<"O";
                }
                std::cout<<"\n";
            }
            std::cout<<std::endl;
        }
    });
    drawer.detach();
}