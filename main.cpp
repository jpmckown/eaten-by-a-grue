#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "dummys/dummys.h"
#include "mechanics/mechanics.h"
#include "things/things.h"
#include "places/places.h"

Map* map = new Map();

void gameOver() {
    std::cout << "You have died" << std::endl << "Game over" << std::endl;
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
    if (map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY - 1))) == "open" ||
        map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY - 1))) == "spawn" ||
        map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY - 1))) == "item" ||
        map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY - 1))) == "door") {
        std::cout << "a) north" << std::endl;
    }
    if (map->getTileInfo(map->getMapCoords((map->currentPosX + 1), map->currentPosY)) == "open" ||
        map->getTileInfo(map->getMapCoords((map->currentPosX + 1), map->currentPosY)) == "spawn" ||
        map->getTileInfo(map->getMapCoords((map->currentPosX + 1), map->currentPosY)) == "item" ||
        map->getTileInfo(map->getMapCoords((map->currentPosX + 1), map->currentPosY)) == "door") {
        std::cout << "b) east" << std::endl;
    }
    if (map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY + 1))) == "open" ||
        map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY + 1))) == "spawn" ||
        map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY + 1))) == "item" ||
        map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY + 1))) == "door") {
        std::cout << "c) south" << std::endl;
    }
    if (map->getTileInfo(map->getMapCoords((map->currentPosX - 1), map->currentPosY)) == "open" ||
        map->getTileInfo(map->getMapCoords((map->currentPosX - 1), map->currentPosY)) == "spawn" ||
        map->getTileInfo(map->getMapCoords((map->currentPosX - 1), map->currentPosY)) == "item" ||
        map->getTileInfo(map->getMapCoords(map->currentPosX, (map->currentPosY + 1))) == "door") {
        std::cout << "d) west" << std::endl;
    }
}

void handleInput(std::string input) {
    if (input == "a") {
        map->currentPosX -= 1;
    }
    if (input == "b") {
        map->currentPosY += 1;
    }
    if (input == "c") {
        map->currentPosX += 1;
    }
    if (input == "d") {
        map->currentPosY -= 1;
    }
}

PDummy spawn() {
    PDummy hero = nullptr;
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
    PDummy result = nullptr;
    Dice die(3);
    char random_variable = die.roll();
    switch(random_variable) {
        case 0: result = new Mage(); break;
        case 1: result = new Rogue(); break;
        case 2: result = new Warrior(); break;
        case 3: result = new Richard(); break;
    }

    return result;
}

int main(int c, char** args) {

    std::cout << "Greetings meatbag. Welcome to the darkest darkest dungeon." << std::endl;
    PDummy dummy = spawn();
    PDummy enemy = randomFoe();
    dummy->setHealth(10);
    std::string input("");
    
    while(!dummy->isDead()){
        std::cout << "Current Health:" << dummy->getHealth() << std::endl;
        currentTile();
        checkArea();
        std::cout << "Choose your direction of travel:" << std::endl;
        printMoveOptions();
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {

                if (map->currentPosX == i && map->currentPosY == j) {
                    std::cout << " X ";
                }else{
                    std::cout << " " << map->getTileInfo(map->getMapCoords(i, j)) << " ";
                }
            }
            std::cout << "" << std::endl;
        }
        std::cin >> input;
        handleInput(input);

        std::cout << "The current room is: " << map->getTileInfo(map->getMapCoords(map->currentPosX, map->currentPosY)) << std::endl;    
        dummy->removeHealth(1);        
        if (dummy->isDead())
            gameOver();
        else
            std::cout << "Soon...." << std::endl;
    }
    Combat fight(dummy, enemy);
    fight.run();

    delete enemy;
    delete map;
    delete dummy;

    return 0;
}