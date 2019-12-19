#pragma once

#include <vector>

#include "oldknights/combatantlist.hpp"

namespace oldknights {

/**
 * Actual game loop that performs the "fighting" between various parties
 */
class BattleLoop {
private:
    CombatantList _combatants;

    [[nodiscard]] size_t get_count(Alleigance const alleigance,
            bool const must_be_alive=false) const;
   
    static void print_combatant(CombatantInstance const& c) noexcept;
    void print_stats_bar() const noexcept; 
     
public:
    BattleLoop(CombatantList const& combatants);
    BattleLoop(CombatantList&& combatants);

    /**
     * Runs the fight between combatants 
     */
    [[nodiscard]] bool fight();


};
}
