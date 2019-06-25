#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <random>

#include "dummys/alldummys.h"
#include "things/item.h"
#include "places/map.h"
#include "mechanics/combat.h"

Map* map = new Map();

void gameOver() {
    std::cout << "You have died" << std::endl << "Game over" << std::endl;
}

void currentTile() {
    std::cout << "The current room is: " << map->getTileInfo(map->getMapCoords(map->currentPosX, map->currentPosY)) << std::endl;
}

void checkArea() {
    std::cout << "To the north: " << map->getTileInfo(map->getMapCoords((map->currentPosX - 1), map->currentPosY)) << std::endl;
    std::cout << "To the west: " << map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY + 1))) << std::endl;
    std::cout << "To the east: " << map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY - 1))) << std::endl;
    std::cout << "To the south: " << map->getTileInfo(map->getMapCoords((map->currentPosX + 1), map->currentPosY)) << std::endl;
}

void printMoveOptions() {
    if (map->getTileInfo(map->getMapCoords((map->currentPosX - 1), map->currentPosY)) != "wall") {
        std::cout << "a) north" << std::endl;
        map->moveNorth = true;
    }
    if (map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY + 1))) != "wall") {
        std::cout << "b) east" << std::endl;
        map->moveEast = true;
    }
    if (map->getTileInfo(map->getMapCoords((map->currentPosX + 1), map->currentPosY)) != "wall") {
        std::cout << "c) south" << std::endl;
        map->moveSouth = true;
    }
    if (map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY - 1))) != "wall") {
        std::cout << "d) west" << std::endl;
        map->moveWest = true;
    }
}

bool handleInput(std::string input) {
    bool validInput = false;

    if (input == "a" && map->moveNorth) {
        map->currentPosX -= 1;
        validInput = true;
    }
    if (input == "b" && map->moveEast) {
        map->currentPosY += 1;
        validInput = true;
    }
    if (input == "c" && map->moveSouth) {
        map->currentPosX += 1;
        validInput = true;
    }
    if (input == "d" && map->moveWest) {
        map->currentPosY -= 1;
        validInput = true;
    }

    map->moveNorth = false;
    map->moveEast = false;
    map->moveSouth = false;
    map->moveWest = false;

    return validInput;
}

PDummy spawn() {
    Dummy* hero = nullptr;
    std::string choice;
    std::cout << "Choose your hero type:" << std::endl;
    std::cout << "a) Warrior\nb) Mage\nc) Rogue\nd) Richard\n";
    std::cin >> choice;
    int val = (int)choice.at(0);
    switch(val) {
        case Dummy::Warrior:
            std::cout << "You have chosen Warrior" << std::endl;
            hero = new Warrior();
            break;
        case Dummy::Mage:
            std::cout << "You have chosen Mage" << std::endl;
            hero = new Mage();
            break;
        case Dummy::Rogue:
            std::cout << "You have chosen Rogue" << std::endl;
            hero = new Rogue();
            break;
        case Dummy::Richard:
            std::cout << "You have chosen Richard" << std::endl;
            hero = new Richard();
            break;
    }
    return hero;
}

PDummy randomFoe() {
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, 3);
    int random_variable = uniform_dist(e1);
    
    PDummy result = nullptr;
    switch(random_variable) {
        case 0: result = new Mage(); result->setHealth(10); break;
        case 1: result = new Rogue(); result->setHealth(10); break;
        case 2: result = new Warrior(); result->setHealth(10); break;
        case 3: result = new Richard(); result->setHealth(10); break;
    }

    return result;
}

int main(int c, char** args) {

    std::cout << "Greetings meatbag. Welcome to the darkest darkest dungeon." << std::endl;
    PDummy dummy = spawn();
    PDummy enemy = randomFoe();
    dummy->setHealth(10);
    std::string input("");
    
    while(!dummy->isDead()) {
        std::cout << "\x1B[2J\x1B[H";
        std::cout << "Player Health: " << dummy->getHealth() << std::endl;
        currentTile();
        //checkArea();
        std::cout << "Choose your direction of travel: " << std::endl;
        printMoveOptions();
        std::cout << "\n\nDungeon Map:" << std::endl;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {

                if (map->currentPosX == i && map->currentPosY == j) {
                    std::cout << "    X   "; // 3 spaces in front and 2 spaces in the back
                }else{
                    std::string tempInfo = map->getTileInfo(map->getMapCoords(i, j));
                    if (tempInfo == "spawn") {
                        std::cout << "  " << map->getTileInfo(map->getMapCoords(i, j)) << " "; // 2 spaces in the front 1 space in the back
                    } else {
                        std::cout << "  " << map->getTileInfo(map->getMapCoords(i, j)) << "  "; // 2 spaces on each side
                    }
                }
            }
            std::cout << "" << std::endl;
        }
        std::cout << "\nEnter choice of direction: ";
        std::cin >> input;
        
        if (handleInput(input)) {
            std::cout << "The current room is: " << map->getTileInfo(map->getMapCoords(map->currentPosX, map->currentPosY)) << std::endl;    
            dummy->removeHealth(1);
            if (dummy->isDead())
                gameOver();
            else
                std::cout << "Soon...." << std::endl;   
        }
    }
    Combat fight(dummy, enemy);
    fight.run();

    delete enemy;
    delete map;
    delete dummy;

    return 0;
}