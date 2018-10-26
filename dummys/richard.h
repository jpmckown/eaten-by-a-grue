#pragma once
#include "dummy.h"
#include <iostream>
#include "../mechanics/attack.h"

class Richard : public Dummy {
public:
  Richard();
  ~Richard();
  using Dummy::acquire;
  using Dummy::inventory;
  using Dummy::isDead;
  using Dummy::dummy_class;
  Attack::Result attack(PAttack) override;
  Attack::Result defend(PAttack) override;
  void action(void*) override;
};