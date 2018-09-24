#include "item.h"

Item::Item(std::string name) {
  _name.assign(name);
}

Item::~Item() {
  
}

std::string Item::name() {
  return std::string(_name); // copy; set using constructor.
}