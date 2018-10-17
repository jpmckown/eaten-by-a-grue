#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "dummys/dummy.h"
#include "things/item.h"
#include "places/map.h"

void gameOver() {
    std::cout << "You were eaten by a grue" << std::endl << "Game over" << std::endl;
}

int main(int c, char** args) {
    std::string weapon("");

    Dummy* dummy = new Dummy();

    std::cout << "Hello. Welcome to the darkest darkest dungeon. Please choose your weapon:" << std::endl
    << "a) longsword" << std::endl << "b) dual daggers" << std::endl << "c) bow" << std::endl;
    std::string input("");
    std::cin >> input;

    if (input == "a") {
        weapon = "longsword";
        std::cout << "You have selected the " << weapon << "!" << std::endl;
    }else if(input == "b") {
        weapon = "dual daggers";
        std::cout << "You have selected the " << weapon << "!" << std::endl;
    }else if(input == "c") {
        weapon = "bow";
        std::cout << "You have selected the " << weapon << "!" << std::endl;
    }
    Item* pWeapon = new Item(weapon);
    dummy->acquire(pWeapon);

    Map* map = new Map();
    //std::cout << "map X: " << map->getMapCoords(0, 0) << " Y:" <<map->getMapCoords(0, 1) << std::endl;
    std::cout << "The current room is: " << map->getTileInfo(map->getMapCoords(1, 5)) << std::endl;

    std::cout << "Choose your direction of travel:" << std::endl
    << "a) north" << std::endl << "b) east" << std::endl << "c) west" << std::endl << "d) south" << std::endl;
    std::cin >> input;

    if (dummy->isDead())
        gameOver();
    else
        std::cout << "Soon...." << std::endl;

    delete dummy;

    return 0;
}