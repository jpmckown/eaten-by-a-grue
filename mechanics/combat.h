#pragma once
#include <iostream>
#include "../dummys/dummy.h"
class Combat {
  PDummy blue;
  PDummy red;

  void announce();

public:
  enum CombatState {
    SQUARED_OFF = 0x0,
    FIGHTING = 0x1,
    COMPLETE = 0x2
  };
  Combat(PDummy = nullptr, PDummy = nullptr);
  ~Combat();
  void run();
  PDummy victor = nullptr;
  PDummy loser = nullptr;
  CombatState state = CombatState::SQUARED_OFF;
};