#include "map.h"
#include <iostream>

Map::Map() : _currentLocation(4ULL, 1ULL) {

}

Map::~Map() {
  
}

Map::Tiles Map::getMapCoords() {
    return _mapGrid[_currentLocation.x][_currentLocation.y];
}

std::string Map::getTileInfo(Tiles tile) {
    switch (tile)
    {
        case Tiles::Open: return std::string("open");
        case Tiles::Wall: return std::string("wall");
        case Tiles::Door: return std::string("door");
        case Tiles::Item: return std::string("item");
        case Tiles::Spawn: return std::string("spawn");
    }
}

void Map::setTileInfo(Point pt, Tiles tile) {
    _mapGrid[pt.x][pt.y] = tile;
}

uint64_t Map::getMapHeight() {
    return _mapHeight;
}

uint64_t Map::getMapWidth() {
    return _mapWidth;
}

char Map::getDirections() {
    char dirs = 0x0;
    if(_mapGrid[_currentLocation.x-1][_currentLocation.y] != Map::Tiles::Wall) dirs |= Directions::North;
    if(_mapGrid[_currentLocation.x][_currentLocation.y-1] != Map::Tiles::Wall) dirs |= Directions::West;
    if(_mapGrid[_currentLocation.x+1][_currentLocation.y] != Map::Tiles::Wall) dirs |= Directions::South;
    if(_mapGrid[_currentLocation.x][_currentLocation.y+1] != Map::Tiles::Wall) dirs |= Directions::East;
    return dirs;
}

void Map::printArea() {
    std::cout << "To the north: " << this->getTileInfo(_mapGrid[_currentLocation.x-1][_currentLocation.y]) << std::endl;
    std::cout << "To the west: " << this->getTileInfo(_mapGrid[_currentLocation.x][_currentLocation.y-1]) << std::endl;
    std::cout << "To the south: " << this->getTileInfo(_mapGrid[_currentLocation.x+1][_currentLocation.y]) << std::endl;
    std::cout << "To the east: " << this->getTileInfo(_mapGrid[_currentLocation.x][_currentLocation.y+1]) << std::endl;
}

std::string Map::getMapInfo(Point pt) {
    return this->getTileInfo(_mapGrid[pt.x][pt.y]);
}