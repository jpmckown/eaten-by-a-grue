#include "rogue.h"

Rogue::Rogue() {
 _class = DummyClasses::Rogue;
}

Rogue::~Rogue() {

}

void Rogue::attack() {
  std::cout << "Rogue attacks!" << std::endl << "ONE BUTTON MACRO AUTOWIN!" << std::endl;
}

void Rogue::action(void* action) {
  
}