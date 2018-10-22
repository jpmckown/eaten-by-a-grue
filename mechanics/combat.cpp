#include "combat.h"

Combat::Combat(PDummy blue, PDummy red) {
  this->blue = blue;
  this->red = red;
}

Combat::~Combat() {
  
}

void Combat::announce() {
  std::cout << blue->name() << " has engaged " << red->name() << "!" << std::endl;
}

void Combat::run() {
  announce();
  if(blue->dummy_class() == Dummy::Richard) {
    blue->attack();
    red->attack();
    victor = red;
    loser = blue;
  }
}