#pragma once
#include <vector>
#include "../things/item.h"

class Attack {
    public:
    enum DamageTypes {
        Physical,
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
        std::vector<Item> _weapons;
        Stats _stats;
        DamageTypes _damage_type;
        DeliveryTypes _delivery_type;
};

typedef Attack* PAttack;