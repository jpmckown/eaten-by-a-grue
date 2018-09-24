#pragma once
#include <string>
class Item {
  std::string _name;

  public:
    Item(std::string);
    ~Item();
    std::string name();
};