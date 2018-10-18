#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "dummys/dummy.h"
#include "things/item.h"
#include "places/map.h"

Map* map = new Map();

void gameOver() {
    std::cout << "You were eaten by a grue" << std::endl << "Game over" << std::endl;
}

void currentTile() {
    std::cout << "The current room is: " << map->getTileInfo(map->getMapCoords(map->currentPosX, map->currentPosY)) << std::endl;
}

void checkArea() {
    std::cout << "To the north: " << map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY - 1))) << std::endl;
    std::cout << "To the west: " << map->getTileInfo(map->getMapCoords((map->currentPosX - 1), map->currentPosY)) << std::endl;
    std::cout << "To the east: " << map->getTileInfo(map->getMapCoords((map->currentPosX + 1), map->currentPosY)) << std::endl;
    std::cout << "To the south: " << map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY + 1))) << std::endl;
}

void printMoveOptions() {
    if (map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY - 1))) == "open") {
        std::cout << "a) north" << std::endl;
    }
    if (map->getTileInfo(map->getMapCoords((map->currentPosX + 1), map->currentPosY)) == "open") {
        std::cout << "b) east" << std::endl;
    }
    if (map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY + 1))) == "open") {
        std::cout << "c) south" << std::endl;
    }
    if (map->getTileInfo(map->getMapCoords((map->currentPosX - 1), map->currentPosY)) == "open") {
        std::cout << "d) west" << std::endl;
    }
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

    //Map* map = new Map();
    //std::cout << "map X: " << map->getMapCoords(0, 0) << " Y:" <<map->getMapCoords(0, 1) << std::endl;
    
    currentTile();
    checkArea();
    std::cout << "Choose your direction of travel:" << std::endl;
    printMoveOptions();
    std::cin >> input;

    if (input == "a") {
        map->currentPosY = map->currentPosY - 1;
    }
    if (input == "b") {
        map->currentPosX = map->currentPosX + 1;
    }
    if (input == "c") {
        map->currentPosY = map->currentPosY + 1;
    }
    if (input == "d") {
        map->currentPosX = map->currentPosX - 1;
    }

    std::cout << "The current room is: " << map->getTileInfo(map->getMapCoords(map->currentPosX, map->currentPosY)) << std::endl;

    if (dummy->isDead())
        gameOver();
    else
        std::cout << "Soon...." << std::endl;

    delete dummy;

    return 0;
}