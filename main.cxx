#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <random>

#include "SDL.h"

#include "dummys/alldummys.h"
#include "things/item.h"
#include "places/map.h"
#include "mechanics/combat.h"

Map* map = new Map();
bool isGameOver = false;

void gameOver() {
    std::cout << "You have died" << std::endl << "Game over" << std::endl;
}

void gameWon() {
    std::cout << "You have found the exit" << std::endl << "Game over" << std::endl;
}

void currentTile() {
    std::cout << "The current room is: " << map->getTileInfo(map->getMapCoords()) << std::endl;
}

void checkArea() {
    map->printArea();
}

void printMoveOptions() {
    char directions = map->getDirections();
    if((directions & Map::North) == Map::North) std::cout << "a) north" << std::endl;
    if((directions & Map::West) == Map::West) std::cout << "b) west" << std::endl;
    if((directions & Map::South) == Map::South) std::cout << "c) south" << std::endl;
    if((directions & Map::East) == Map::East) std::cout << "d) east" << std::endl;
}

bool handleInput(std::string input) {
    char avail = map->getDirections();

    if(input == "a" && (avail & Map::North) == Map::North) { 
        map->_currentLocation.x--;
        return true;
    }

    if(input == "b" && (avail & Map::West) == Map::West) { 
        map->_currentLocation.y--;
        return true;
    }

    if(input == "c" && (avail & Map::South) == Map::South) { 
        map->_currentLocation.x++;
        return true;
    }

    if(input == "d" && (avail & Map::East) == Map::East) { 
        map->_currentLocation.y++;
        return true;
    }

    return false;
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
        case 0: result = new Mage(); result->addHealth(10); break;
        case 1: result = new Rogue(); result->addHealth(10); break;
        case 2: result = new Warrior(); result->addHealth(10); break;
        case 3: result = new Richard(); result->addHealth(10); break;
    }

    return result;
}

int main(int c, char** args) {

    std::cout << "Entered" << std::endl;

    SDL_Window* pWindow = NULL;
    SDL_Renderer* pRenderer = NULL;
    SDL_Surface* pPrimarySurface = NULL;

    static const int WinWidth = 1024;
    static const int WinHeight = 728;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "ERROR: " << SDL_GetError() << std::endl;
        return -1;
    }
    std::cout << "Initialized" << std::endl;

    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        std::cout << "ERROR: " << SDL_GetError() << std::endl;
        return -1;
    }
    std::cout << "Hint set" << std::endl;

    if((pWindow = SDL_CreateWindow("My SDL Game",
    	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    	WinWidth, WinHeight, SDL_WINDOW_SHOWN)) == NULL) {
        std::cout << "ERROR: " << SDL_GetError() << std::endl;
        return -1;
    }

    std::cout << "Window created" << std::endl;

    pPrimarySurface = SDL_GetWindowSurface(pWindow);
    std::cout << "Got surface" << std::endl;

    if((pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
        std::cout << "ERROR: " << SDL_GetError() << std::endl;
        return -1;
    }
    std::cout << "Renderer created" << std::endl;

    SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xFF);
    std::cout << "Renderer color set" << std::endl;

    // success
    std::cout << "Success" << std::endl;
    
    if(pRenderer) {
		SDL_DestroyRenderer(pRenderer);
		pRenderer = NULL;
        std::cout << "Renderer destroyed" << std::endl;
	}

	if(pWindow) {
		SDL_DestroyWindow(pWindow);
		pWindow = NULL;
        std::cout << "Window destroyed" << std::endl;
	}

    SDL_Quit();
    std::cout << "Quitted" << std::endl;
   
    return 0;
}