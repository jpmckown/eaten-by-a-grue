#pragma once
#include <vector>
#include <string>
#include "../things/item.h"

class Dummy {
  public:
    enum DummyClasses {
      Warrior = 0x61,
      Mage = 0x62,
      Rogue = 0x63,
      Richard = 0x64
    };
    Dummy();
    virtual ~Dummy();
    bool isDead();
    void acquire(Item*);
    std::vector<Item*> inventory();
    DummyClasses dummy_class();
    std::string name();
    virtual void attack() = 0;
    virtual void action(void* action) = 0;
    void addHealth(uint64_t value);
    uint64_t getHealth();
    void removeHealth(int value);
protected: 
  DummyClasses _class;
private:
  struct Stats {
    uint64_t health = 0;
    uint64_t strength = 0;
    uint64_t intelligence = 0;
    uint64_t dexterity = 0;
    uint64_t charisma = 0;
  } _stats;

  std::vector<Item*> _inventory;
};
typedef Dummy* PDummy;