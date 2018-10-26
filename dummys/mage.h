#pragma once
#include "dummy.h"
#include <iostream>
#include "../mechanics/attack.h"

class Mage : public Dummy {
public:
  Mage();
  ~Mage();
  using Dummy::acquire;
  using Dummy::inventory;
  using Dummy::isDead;
  using Dummy::dummy_class;
  Attack::Result attack(PAttack) override;
  Attack::Result defend(PAttack) override;
  void action(void*) override;
};