#pragma once
#include "dummy.h"
#include <iostream>

class Mage : public Dummy {
public:
  Mage();
  ~Mage();
  using Dummy::acquire;
  using Dummy::inventory;
  using Dummy::isDead;
  using Dummy::dummy_class;
  void action(void*) override;
};