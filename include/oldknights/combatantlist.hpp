#pragma once

#include <functional>
#include <vector>

#include "oldknights/combatant.hpp"

namespace oldknights {

/**
 * A list for storing a set of combatants with hand helper functions.
 */
class CombatantList {
    std::vector<CombatantInstance> _combatants;
public:
    CombatantList(std::vector<Combatant>const& combatants);
    ~CombatantList() = default;

    CombatantList(CombatantList const& other);
    CombatantList(CombatantList && other);

    CombatantList& operator=(CombatantList const& other);
    CombatantList& operator=(CombatantList && other);

    void for_each(std::function<void(CombatantInstance&)> op);
    void for_each(std::function<void(CombatantInstance const&)> op) const;

    [[nodiscard]] size_t get_count(Alleigance const alleigance,
            bool const must_be_alive=false) const;

    void sort_by_agility();
};
}
