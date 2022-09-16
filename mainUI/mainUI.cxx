#include "mainUI.h"

MainUI::MainUI() {}

MainUI::~MainUI() {}

void MainUI::renderPlayerInfo(uint64_t playerHealth) {
    std::cout << "Soon....\n" << std::endl;
    std::cout << "Player Health: " << playerHealth << std::endl;
}

void MainUI::renderCurrentTile(std::string tileInfo) {
    std::cout << "The current room is: " << tileInfo << std::endl;
}

void MainUI::renderMapArea(std::string tileInfo1, std::string tileInfo2, std::string tileInfo3, std::string tileInfo4) {
    std::cout << "To the north: " << tileInfo1 << std::endl;
    std::cout << "To the west: " << tileInfo2 << std::endl;
    std::cout << "To the south: " << tileInfo3 << std::endl;
    std::cout << "To the east: " << tileInfo4 << std::endl;
}

void MainUI::renderWelcomeMsg() {
    std::cout << "Greetings meatbag. Welcome to the darkest darkest dungeon." << std::endl;
}

void MainUI::renderAwaitInputMsg() {
    std::cout << "Choose your direction of travel: " << std::endl;
}
