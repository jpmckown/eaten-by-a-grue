#include "mage.h"

Mage::Mage() {
  _class = DummyClasses::Mage;
}

Mage::~Mage() {

}

void Mage::attack() {
  std::cout << "Mage attacks!" << std::endl << "SCREAMING COCK!" << std::endl;
}

void Mage::action(void* action) {

}