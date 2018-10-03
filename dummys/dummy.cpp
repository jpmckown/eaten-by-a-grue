#include "dummy.h"

Dummy::Dummy() {
}

Dummy::~Dummy() {
  for(auto item : _inventory) delete item;
}

bool Dummy::isDead() {
  return _stats.health == 0; // no < because its uint
}

std::vector<Item*> Dummy::inventory() {
  return std::vector<Item*>(_inventory); // copy.
}

void Dummy::acquire(Item* item) {
  _inventory.push_back(item);
}

Dummy::DummyClasses Dummy::dummy_class() {
  return _class;
}