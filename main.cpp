
#include <vector>
#include <iostream>
#include <list>
#include "Models/GameManager.h"


int main() {
    GameManager manager { };

    manager.start_game();
    while (true){}
    return 0;
}