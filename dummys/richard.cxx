#include "richard.h"

Richard::Richard() {
  _class = DummyClasses::Richard;
}

Richard::~Richard() {

}

void Richard::attack() {
  std::cout << "Richard attacks!" << std::endl << "JUDY CHOP!" << std::endl;
}

void Richard::action(void* action) {

}