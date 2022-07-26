#include "warrior.h"

Warrior::Warrior() {
  _class = DummyClasses::Warrior;
}

Warrior::~Warrior() {

}

void Warrior::attack() {
  std::cout << "Warrior attacks!" << std::endl << "I'M THE BEST.... ARRRRROOOUUUND *crane kick*!" << std::endl;
}

void Warrior::action(void* action) {

}