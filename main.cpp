#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

void gameOver() {
    std::cout << "You were eaten by a grue" << std::endl << "Game over" << std::endl;
}

int main(int c, char** args) {
   std::string pWeapon("");

    std::cout << "Hello. Welcome to the darkest darkest dungeon. Please choose your weapon:" << std::endl
    << "a) longsword" << std::endl << "b) dual daggers" << std::endl << "c) bow" << std::endl;
    std::string input("");
    std::cin >> input;

    if (input == "a") {
        pWeapon = "longsword";
        std::cout << "You have selected the " << pWeapon << "!" << std::endl;
    }else if(input == "b") {
        pWeapon = "dual daggers";
        std::cout << "You have selected the " << pWeapon << "!" << std::endl;
    }else if(input == "c") {
        pWeapon = "bow";
        std::cout << "You have selected the " << pWeapon << "!" << std::endl;
    }

    std::cout << "Choose your direction of travel:" << std::endl
    << "a) north" << std::endl << "b) east" << std::endl << "c) west" << std::endl << "d) south" << std::endl;
    std::cin >> input;

    gameOver();

    return 0;
}