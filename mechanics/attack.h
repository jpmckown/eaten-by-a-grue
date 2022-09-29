#pragma once
#include <vector>

class Attack {
    public:
    enum DamageTypes {
        Slash,
        Blunt,
        Pierce,
        Fire,
        Arcane
    };
    enum DeliveryTypes {
        Melee,
        Ranged
    };

    struct Result {
        bool success;
        unsigned long long delta;
    };

    struct Stats {
        unsigned long long strength;
        unsigned long long intelligence;
        unsigned long long dexterity;
    };

    private:
};

typedef Attack* PAttack;