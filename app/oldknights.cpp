#include <cstdio>

#include "oldknights/battleloop.hpp"

using namespace oldknights;

int main(void) {
    Combatant p1 = {
        .name = "hero1",
        .attribute = Attribute::Fire,
        .affinity = Affinity::Light,
        .alleigance = Alleigance::Hero,
        .current_level = 47,
        .max_hp = 150,
        .max_mp = 10,
        .agility = 12
    };

    Combatant p2 = {
        .name = "wizard1",
        .attribute = Attribute::Fire,
        .affinity = Affinity::Light,
        .alleigance = Alleigance::Hero,
        .current_level = 51,
        .max_hp = 80,
        .max_mp = 120,
        .agility = 10
    };

    Combatant p3 = {
        .name = "ninja1",
        .attribute = Attribute::Fire,
        .affinity = Affinity::Light,
        .alleigance = Alleigance::Hero,
        .current_level = 37,
        .max_hp = 70,
        .max_mp = 20,
        .agility = 30
    };


    Combatant e1 = {
        .name = "enemy1",
        .attribute = Attribute::Fire,
        .affinity = Affinity::Light,
        .alleigance = Alleigance::Bad,
        .current_level = 52,
        .max_hp = 250,
        .max_mp = 90,
        .agility = 3
    };

    CombatantList combatants({e1, p1, p2, p3});
    BattleLoop loop(std::move(combatants));
    return loop.fight() ? 0 : -1;
}
