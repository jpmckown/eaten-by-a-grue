#pragma once
#include "dummy.h"
#include <iostream>

class Rogue : public Dummy {
public:
  Rogue();
  ~Rogue();
  using Dummy::acquire;
  using Dummy::inventory;
  using Dummy::isDead;
  using Dummy::dummy_class;
  void action(void*) override;
};