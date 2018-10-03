#pragma once
#include <string>
#include <vector>

class Map {
  // 0 is a open space
  // 1 is a wall
  // 2 is a door
  // 3 is a item
  int _mapGrid[5][2] = { {0, 0}, {2, 0}, {0, 3}, {0, 1}, {0, 0} };
  
  public:
    Map();
    ~Map();
    int getMapCoords(int x, int y);
    std::string getTileInfo(int num);
};