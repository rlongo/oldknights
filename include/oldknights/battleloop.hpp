#pragma once

#include <vector>

#include "oldknights/combatant.hpp"

namespace oldknights {

/**
 * Actual game loop that performs the "fighting" between various parties
 */
class BattleLoop {
private:
    std::vector<CombatantInstance> _combatants;

    [[nodiscard]] size_t get_count(Alleigance const alleigance,
            bool const must_be_alive=false) const;
   
    static void print_combatant(CombatantInstance const& c) noexcept;
    void print_stats_bar() const noexcept; 
     
public:
    BattleLoop(std::vector<Combatant>const& combatants);

    /**
     * Runs the fight between combatants 
     */
    [[nodiscard]] bool fight();


};
}
