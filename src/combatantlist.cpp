#include "oldknights/combatantlist.hpp"
#include "oldknights/error.hpp"

#include <algorithm>
#include <cstdio>

using namespace oldknights;

CombatantList::CombatantList(std::vector<Combatant>const& combatants)
    : _combatants() {
    for (auto const& c : combatants) {
        _combatants.emplace_back(CombatantInstance{
            .hp = c.max_hp,
            .mp = c.max_mp,
            .stats = c
        });
    }
}

CombatantList::CombatantList(CombatantList const& other)
    : _combatants(other._combatants) {
}
CombatantList::CombatantList(CombatantList && other)
    : _combatants(std::move(other._combatants)) {
}

CombatantList& CombatantList::operator=(CombatantList const& other) {
    _combatants = other._combatants;
    return *this;
}
CombatantList& CombatantList::operator=(CombatantList && other) {
    _combatants = std::move(other._combatants);
    return *this;
}

void CombatantList::for_each(std::function<void(CombatantInstance&)> op) {
    std::for_each(_combatants.begin(), _combatants.end(), op);
}

void CombatantList::for_each(std::function<void(CombatantInstance const&)> op) const {
    std::for_each(_combatants.cbegin(), _combatants.cend(), op);
}

size_t CombatantList::get_count(Alleigance const alleigance,
        bool const must_be_alive) const {
    return std::count_if(_combatants.begin(), _combatants.end(),
            [alleigance, must_be_alive](auto const& c) {
                return c.stats.alleigance==alleigance && (!must_be_alive || c.hp>0);
            });
}

void CombatantList::sort_by_agility() {
    std::sort(_combatants.begin(), _combatants.end(),
        [](auto const& a, auto const& b) {
            return a.stats.agility > b.stats.agility;
        }
    );
}


