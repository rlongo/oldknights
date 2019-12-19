#pragma once

#include <cstdint>
#include <string>

constexpr size_t LEN_NAME = 12;

namespace oldknights {

/// Base element that that the combatant identifies with.
enum class Attribute : uint8_t {
    Fire = (1<<0),
    Water = (1<<1),
    Earth = (1<<2),
    Thunder = (1<<3),
    Ice = (1<<4),
    Mineral = (1<<5)
};

/// Base typing affinity. Used to determine factors such as
/// stat growth, effectiveness, etc
enum class Affinity : uint8_t {
    Light = (1<<0),
    Dark = (1<<1),
    Divine = (1<<2),
    Dragon = (1<<3)
};

/// Which side the combatant is on
enum class Alleigance : uint8_t {
    Hero = (1<<0),
    Bad = (1<<1),
    NPC = (1<<2)
};

/**
 * A combatant is a unit capable of participating in battle.
 * This class is used to track leveling, stats, equipment,
 * elements, and other similar stats.
 */
struct Combatant {
    Attribute attribute;
    Affinity affinity;
    Alleigance alleigance;

    char name[LEN_NAME];

    /// Current level of the combatant
    uint8_t current_level;

    /// Classic stats
    uint16_t max_hp, max_mp;

    /// Base physical attack stat
    uint16_t strength;
    /// Base physical defense stat
    uint16_t defense;

    /// Used to determine ordering
    uint8_t agility;
    /// Used to skew the RNG
    uint8_t luck;
};

/// Actual combatant instance class that can be used
/// to track data about the combatant in the fight.
struct CombatantInstance {
    Combatant stats;
    uint16_t hp, mp;
};

}
