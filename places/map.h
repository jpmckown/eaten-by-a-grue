#pragma once
#include <string>
#include <vector>

class Map {  
  public:
    // 0 is a open space
    // 1 is a wall
    // 2 is a door
    // 3 is a item
    // 5 is player spawn
    enum Tiles: char {
      Open = 0x00,
      Wall = 0x01,
      Door = 0x02,
      Item = 0x03,
      Spawn = 0x05
    };

    enum Directions: char {
      North = 0x01,
      South = 0x02,
      West = 0x04,
      East = 0x08
    };

    struct Point {
      uint64_t x;
      uint64_t y;
      Point(uint64_t x, uint64_t y) : x(x), y(y) { }
    };

    Map();
    ~Map();
    uint64_t getMapHeight();
    uint64_t getMapWidth();
    Tiles getMapCoords();
    std::string getMapInfo(Point);
    std::string getTileInfo(Tiles);
    char getDirections();
    void setTileInfo(Point, Tiles);
    Point _currentLocation;
    Tiles getMapCoordsNorth();
    Tiles getMapCoordsWest();
    Tiles getMapCoordsSouth();
    Tiles getMapCoordsEast();
private:
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
  Tiles _mapGrid[_mapHeight][_mapWidth] = { {Tiles(Tiles(1)), Tiles(1), Tiles(1), Tiles(1), Tiles(1), Tiles(1)},
                          {Tiles(1), Tiles(0), Tiles(0), Tiles(0), Tiles(0), Tiles(1)}, 
                          {Tiles(1), Tiles(0), Tiles(0), Tiles(0), Tiles(0), Tiles(2)}, 
                          {Tiles(1), Tiles(3), Tiles(0), Tiles(0), Tiles(0), Tiles(1)},
                          {Tiles(1), Tiles(0), Tiles(0), Tiles(0), Tiles(0), Tiles(1)},
                          {Tiles(1), Tiles(0), Tiles(0), Tiles(0), Tiles(0), Tiles(1)},
                          {Tiles(1), Tiles(0), Tiles(0), Tiles(0), Tiles(0), Tiles(1)},
                          {Tiles(1), Tiles(0), Tiles(0), Tiles(0), Tiles(0), Tiles(1)},
                          {Tiles(1), Tiles(0), Tiles(0), Tiles(0), Tiles(0), Tiles(1)},
                          {Tiles(1), Tiles(0), Tiles(0), Tiles(0), Tiles(0), Tiles(1)},
                          {Tiles(1), Tiles(1), Tiles(2), Tiles(1), Tiles(1), Tiles(1)} };
};