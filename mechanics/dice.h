#pragma once
#include <random>

class Dice {
private:
  char _sides;

public:
  Dice(char sides = 0x6);
  ~Dice();

  char roll();
};