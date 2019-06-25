#pragma once
#include <string>
#include <vector>

class Map {
  // 0 is a open space
  // 1 is a wall
  // 2 is a door
  // 3 is a item
  // 5 player spawn/start
  //
  // [1][1][1][1][1][1]
  // [1][5][0][0][0][1]
  // [1][0][0][0][0][2]
  // [1][3][0][0][0][1]
  // [1][1][2][1][1][1]
  const static uint64_t _mapHeight = 11;
  const static uint64_t _mapWidth = 6;
  int _mapGrid[_mapHeight][_mapWidth] = { {1, 1, 1, 1, 1, 1},
                          {1, 0, 0, 0, 0, 1}, 
                          {1, 0, 0, 0, 0, 2}, 
                          {1, 3, 0, 0, 0, 1},
                          {1, 0, 0, 0, 0, 1},
                          {1, 0, 0, 0, 0, 1},
                          {1, 0, 0, 0, 0, 1},
                          {1, 0, 0, 0, 0, 1},
                          {1, 0, 0, 0, 0, 1},
                          {1, 0, 0, 0, 0, 1},
                          {1, 1, 2, 1, 1, 1} };
  
  public:
    Map();
    ~Map();
    int getMapHeight();
    int getMapWidth();
    int getMapCoords(int x, int y);
    std::string getTileInfo(int num);
    void setTileInfo(int x, int y, int num);
    bool moveNorth = false;
    bool moveEast = false;
    bool moveSouth = false;
    bool moveWest = false;
    uint64_t currentPosX = 4;
    uint64_t currentPosY = 1;
};