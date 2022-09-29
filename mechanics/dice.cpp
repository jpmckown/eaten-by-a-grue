#include "dice.h"

Dice::Dice(char sides) {
  _sides = sides;
}

Dice::~Dice() { }

char Dice::roll() {
  std::random_device r;
  std::default_random_engine e1(r());
  std::uniform_int_distribution<char> uniform_dist(0, _sides);
  return uniform_dist(e1);
}