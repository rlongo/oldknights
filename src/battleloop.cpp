#include "oldknights/battleloop.hpp"
#include "oldknights/error.hpp"

#include <algorithm>
#include <cstdio>

using namespace oldknights;

BattleLoop::BattleLoop(CombatantList const& combatants)
    : _combatants(combatants) {
    
    _combatants.sort_by_agility();
    if (_combatants.get_count(Alleigance::Hero, true) == 0
            || _combatants.get_count(Alleigance::Bad, true) == 0) {
        throw GameError("GameLoop does not contain a list of combatants capable of fighting");
    }
}

BattleLoop::BattleLoop(CombatantList && combatants)
    : _combatants(std::move(combatants)) {
    
    _combatants.sort_by_agility();
    if (_combatants.get_count(Alleigance::Hero, true) == 0
            || _combatants.get_count(Alleigance::Bad, true) == 0) {
        throw GameError("GameLoop does not contain a list of combatants capable of fighting");
    }
}

void BattleLoop::print_combatant(CombatantInstance const& c) noexcept {
    printf("%12s Lv. %3d HP: %4d/%4d MP:%4d/%4d",
            c.stats.name,
            c.stats.current_level,
            c.hp, c.stats.max_hp,
            c.mp, c.stats.max_mp
          );
}

void BattleLoop::print_stats_bar() const noexcept {
    auto print_by_alleigance = [this](Alleigance const alleigance) {
        auto i = 0;
        _combatants.for_each(
            [this, &i, alleigance](auto& c){
                if (c.stats.alleigance == alleigance) {
                    print_combatant(c);
                    printf((i++ % 2) ? "\n" : "  ");
                }
        });
    };

    printf("Heroes\n");
    print_by_alleigance(Alleigance::Hero);

    if (_combatants.get_count(Alleigance::NPC) > 0) {
        printf("\nNPC\n");
        print_by_alleigance(Alleigance::NPC);
    }
 
    printf("\nEnemies\n");
    print_by_alleigance(Alleigance::Bad);
}

bool BattleLoop::fight() {
    print_stats_bar();
    return true;
}
