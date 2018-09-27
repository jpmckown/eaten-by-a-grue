#pragma once
#include <cstring>
#include <vector>
#include "../things/item.h"

class Dummy {
  struct Stats {
    uint64_t health;
    uint64_t strength;
    uint64_t intelligence;
    uint64_t dexterity;
    uint64_t charisma;
  } _stats;
  std::vector<Item*> _inventory;

  public:
    Dummy();
    ~Dummy();
    bool isDead();
    void acquire(Item*);
    std::vector<Item*> inventory();
};