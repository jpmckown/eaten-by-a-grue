#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "dummys/richard.h"
#include "things/item.h"

void gameOver() {
    std::cout << "You were eaten by a grue" << std::endl << "Game over" << std::endl;
}

Dummy* spawn() {
    Dummy* hero = nullptr;
    std::string choice;
    std::cout << "Choose your hero type:" << std::endl;
    std::cout << "a) Warrior\nb) Mage\nc) Rogue\nd) Richard\n";
    std::cin >> choice;
    int val = (int)choice.at(0);
    switch(val) {
        case Dummy::Warrior:
        case Dummy::Mage:
        case Dummy::Rogue:
        case Dummy::Richard:
            std::cout << "You have chosen Richard" << std::endl;
            hero = new Richard();
    }
    return hero;
}

int main(int c, char** args) {

    std::cout << "Greetings meatbag. Welcome to the darkest darkest dungeon." << std::endl;
    Dummy* dummy = spawn();
    dummy->attack();

    if (dummy->isDead())
        gameOver();
    else
        std::cout << "Soon...." << std::endl;

    delete dummy;

    return 0;
}