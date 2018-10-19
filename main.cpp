#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <random>

#include "dummys/alldummys.h"
#include "things/item.h"
#include "mechanics/combat.h"

void gameOver() {
    std::cout << "You have died" << std::endl << "Game over" << std::endl;
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

    Combat fight(dummy, enemy);
    
    fight.run();

    if (dummy->isDead())
        gameOver();
    else
        std::cout << "Soon...." << std::endl;

    delete dummy;

    return 0;
}