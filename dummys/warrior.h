#pragma once
#include "dummy.h"
#include <iostream>

class Warrior : public Dummy {
public:
  Warrior();
  ~Warrior();
  using Dummy::acquire;
  using Dummy::inventory;
  using Dummy::isDead;
  using Dummy::dummy_class;
  void action(void*) override;
};