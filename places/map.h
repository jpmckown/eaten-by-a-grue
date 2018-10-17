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
  // [1][1][1][1][1]
  // [1][5][0][0][1]
  // [1][0][0][0][2]
  // [1][3][0][0][1]
  // [1][1][2][1][1]
  int _mapGrid[25][1] = {{1}, {1}, {1}, {1}, {1},
                         {1}, {5}, {0}, {0}, {1}, 
                         {1}, {0}, {0}, {0}, {2}, 
                         {1}, {3}, {0}, {0}, {1},                                                     
                         {1}, {1}, {2}, {1}, {1}};
  
  public:
    Map();
    ~Map();
    int getMapCoords(int x, int y);
    std::string getTileInfo(int num);
};