#include "map.h"

Map::Map() {

}

Map::~Map() {
  
}

int Map::getMapCoords(int x, int y) {
    return _mapGrid[x][y];
}

std::string Map::getTileInfo(int num) {
    // 0 is a open space
    // 1 is a wall
    // 2 is a door
    // 3 is a item
    std::string info;
    switch (num)
    {
        case 0:
            info = "open";
            break;
        case 1:
            info = "wall";
            break;    
        case 2:
            info = "door";
            break;
        case 3:
            info = "item";
            break;       
        default:
            break;
    }

    return info;
}




// void Map::acquire(Item* item) {
//   _inventory.push_back(item);
// }