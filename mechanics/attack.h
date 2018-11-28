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
        uint64_t delta;
    };

    struct Stats {
        uint64_t strength;
        uint64_t intelligence;
        uint64_t dexterity;
    };

    private:
};

typedef Attack* PAttack;