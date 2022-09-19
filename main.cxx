#include <iostream>
#include <string>
#include <random>
#include "SDL.h"

#include "dummys/dummys.h"
#include "things/item.h"
#include "places/map.h"
#include "mechanics/combat.h"



#include "mainUI/mainUI.h"

Map *map = new Map();
bool isGameOver = false;

MainUI *mainUI = new MainUI();

void gameOver() {
    std::cout << "You have died" << std::endl << "Game over" << std::endl;
}

void gameWon() {
    std::cout << "You have found the exit" << std::endl << "Game over" << std::endl;
}

void printMoveOptions() {
    char directions = map->getDirections();
    if ((directions & Map::North) == Map::North) std::cout << "a) north" << std::endl;
    if ((directions & Map::West) == Map::West) std::cout << "b) west" << std::endl;
    if ((directions & Map::South) == Map::South) std::cout << "c) south" << std::endl;
    if ((directions & Map::East) == Map::East) std::cout << "d) east" << std::endl;
}

bool handleInput(std::string input) {
    char avail = map->getDirections();

    if (input == "a" && (avail & Map::North) == Map::North) {
        map->_currentLocation.x--;
        return true;
    }

    if (input == "b" && (avail & Map::West) == Map::West) {
        map->_currentLocation.y--;
        return true;
    }

    if (input == "c" && (avail & Map::South) == Map::South) {
        map->_currentLocation.x++;
        return true;
    }

    if (input == "d" && (avail & Map::East) == Map::East) {
        map->_currentLocation.y++;
        return true;
    }

    return false;
}

PDummy spawn() {
    Dummy *hero = nullptr;
    std::string choice;
    std::cout << "Choose your hero type:" << std::endl;
    std::cout << "a) Warrior\nb) Mage\nc) Rogue\nd) Richard\n";
    std::cin >> choice;
    int val = (int) choice.at(0);
    switch (val) {
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
    switch (random_variable) {
        case 0:
            result = new Mage();
            result->addHealth(10);
            break;
        case 1:
            result = new Rogue();
            result->addHealth(10);
            break;
        case 2:
            result = new Warrior();
            result->addHealth(10);
            break;
        case 3:
            result = new Richard();
            result->addHealth(10);
            break;
    }

    return result;
}



int main(int c, char* args[]) {

    //The window we'll be rendering to
    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }else{
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }else{
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    mainUI->renderWelcomeMsg();

    // Create test dummy
    PDummy dummy = spawn();
    PDummy enemy = randomFoe();
    dummy->addHealth(10);
    std::string input("");

    while (!isGameOver) {
        mainUI->renderPlayerInfo(dummy->getHealth());
        mainUI->renderCurrentTile(map->getTileInfo(map->getMapCoords()));
        mainUI->renderMapArea(map->getTileInfo(map->getMapCoordsNorth()), map->getTileInfo(map->getMapCoordsWest()),
                              map->getTileInfo(map->getMapCoordsEast()), map->getTileInfo(map->getMapCoordsSouth()));

        mainUI->renderAwaitInputMsg();
        printMoveOptions();
        std::cout << "\n\nDungeon Map:" << std::endl;
        for (int i = 0; i < map->getMapHeight(); i++) {
            for (int j = 0; j < map->getMapWidth(); j++) {

                if (map->_currentLocation.x == i && map->_currentLocation.y == j) {
                    std::cout << "    X   "; // 3 spaces in front and 2 spaces in the back
                } else {
                    std::string tempInfo = map->getMapInfo(Map::Point(i, j));
                    if (tempInfo == "spawn") {
                        std::cout << "  " << map->getMapInfo(Map::Point(i, j))
                                  << " "; // 2 spaces in the front 1 space in the back
                    } else {
                        std::cout << "  " << map->getMapInfo(Map::Point(i, j)) << "  "; // 2 spaces on each side
                    }
                }
            }
            std::cout << "" << std::endl;
        }
        std::cout << "\nEnter choice of direction: ";
        std::cin >> input;

        if (handleInput(input)) {
            if (map->getTileInfo(map->getMapCoords()) == "door") {
                gameWon();
                isGameOver = true;
            }

            if (map->getTileInfo(map->getMapCoords()) == "item") {
                dummy->addHealth(5);
                map->setTileInfo(map->_currentLocation, Map::Tiles(0));
            }

            dummy->removeHealth(1);
            if (dummy->isDead()) {
                gameOver();
                isGameOver = true;
            }
        }
    }

    delete enemy;
    delete map;
    delete dummy;

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;

    return 0;
}