#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

int main(int c, char** args) {
    std::cout << "Hello. Welcome to the darkest darkest dungeon. Please choose your weapon:" << std::endl
    << "a) longsword" << std::endl << "b) dual daggers" << std::endl << "c) bow" << std::endl;
    std::string input("");
    std::cin >> input;
    std::cout << "You were eaten by a grue" << std::endl << "Game over" << std::endl;
    return 0;
}