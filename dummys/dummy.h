#pragma once
#include <vector>
#include "../things/item.h"

class Dummy {
  struct Stats {
    uint64_t health = 0;
    uint64_t strength = 0;
    uint64_t intelligence = 0;
    uint64_t dexterity = 0;
    uint64_t charisma = 0;
  } _stats;
  std::vector<Item*> _inventory;

  public:
    Dummy();
    ~Dummy();
    bool isDead();
    void acquire(Item*);
    std::vector<Item*> inventory();
};