#pragma once

#include <iostream>
#include <cstdint>

class MainUI {
public:
  MainUI();
  ~MainUI();

  void renderWelcomeMsg();
  void renderPlayerInfo(uint64_t playerHealths);
  void renderCurrentTile(std::string tileInfo);
  void renderMapArea(std::string tileInfo1, std::string tileInfo2, std::string tileInfo3, std::string tileInfo4);
  void renderAwaitInputMsg();
};