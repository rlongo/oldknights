#include "oldknights/battleloop.hpp"
#include "oldknights/error.hpp"

#include <algorithm>
#include <cstdio>

using namespace oldknights;

BattleLoop::BattleLoop(std::vector<Combatant>const& combatants)
    : _combatants() {
 
    for (auto& c : combatants) {
        CombatantInstance instance = {
            .hp = c.max_hp,
            .mp = c.max_mp,
            .stats = c
        };
        _combatants.push_back(std::move(instance));
    }

    std::sort(_combatants.begin(), _combatants.end(),
            [](auto const& a, auto const& b) {
                return a.stats.agility > b.stats.agility;
                }
            );
   
    if (get_count(Alleigance::Hero, true) == 0
            || get_count(Alleigance::Bad, true) == 0) {
        
        throw GameError("GameLoop does not contain a list of combatants capable of fighting");
    }
}


size_t BattleLoop::get_count(Alleigance const alleigance,
        bool const must_be_alive) const {
    return std::count_if(_combatants.begin(), _combatants.end(),
            [alleigance, must_be_alive](auto const& c) {
                return c.stats.alleigance==alleigance && (!must_be_alive || c.hp>0);
            });
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
        for (auto& c: _combatants) {
            if (c.stats.alleigance != alleigance) continue;
            print_combatant(c);
            if (i++ % 2) printf("\n");
            else printf("  ");
        }
    };

    printf("Heroes\n");
    print_by_alleigance(Alleigance::Hero);

    if (get_count(Alleigance::NPC) > 0) {
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
