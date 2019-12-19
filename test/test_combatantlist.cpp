#include "gtest/gtest.h"

#include "oldknights/combatantlist.hpp"

oldknights::CombatantList get_test_list() {
    oldknights::Combatant p1 = {
        .name = "hero1",
        .attribute = oldknights::Attribute::Fire,
        .affinity = oldknights::Affinity::Light,
        .alleigance = oldknights::Alleigance::Hero,
        .current_level = 47,
        .max_hp = 150,
        .max_mp = 10,
        .agility = 12
    };

    oldknights::Combatant p2 = {
        .name = "wizard1",
        .attribute = oldknights::Attribute::Fire,
        .affinity = oldknights::Affinity::Light,
        .alleigance = oldknights::Alleigance::Hero,
        .current_level = 51,
        .max_hp = 80,
        .max_mp = 120,
        .agility = 8
    };

    oldknights::Combatant p3 = {
        .name = "ninja1",
        .attribute = oldknights::Attribute::Fire,
        .affinity = oldknights::Affinity::Light,
        .alleigance = oldknights::Alleigance::Hero,
        .current_level = 37,
        .max_hp = 70,
        .max_mp = 20,
        .agility = 30
    };

    oldknights::Combatant e1 = {
        .name = "enemy1",
        .attribute = oldknights::Attribute::Fire,
        .affinity = oldknights::Affinity::Light,
        .alleigance = oldknights::Alleigance::Bad,
        .current_level = 52,
        .max_hp = 250,
        .max_mp = 90,
        .agility = 11
    };

    oldknights::Combatant n1 = {
        .name = "npc1",
        .attribute = oldknights::Attribute::Fire,
        .affinity = oldknights::Affinity::Light,
        .alleigance = oldknights::Alleigance::NPC,
        .current_level = 52,
        .max_hp = 250,
        .max_mp = 90,
        .agility = 1
    };

    return oldknights::CombatantList({p1,p2,p3,e1,n1});
}

TEST(CombatantList, size) {
    auto list = get_test_list(); 
    ASSERT_EQ(5, list.size());
}

TEST(CombatantList, indexing) {
    auto list = get_test_list(); 
    ASSERT_STREQ("hero1",   list[0].stats.name);
    ASSERT_STREQ("wizard1", list[1].stats.name);
    ASSERT_STREQ("ninja1",  list[2].stats.name);
    ASSERT_STREQ("enemy1",  list[3].stats.name);
    ASSERT_STREQ("npc1",    list[4].stats.name);
}

TEST(CombatantList, sort_by_agility) {
    auto list = get_test_list();
    list.sort_by_agility();
    ASSERT_STREQ("ninja1",  list[0].stats.name);
    ASSERT_STREQ("hero1",   list[1].stats.name);
    ASSERT_STREQ("enemy1",  list[2].stats.name);
    ASSERT_STREQ("wizard1", list[3].stats.name);
    ASSERT_STREQ("npc1",    list[4].stats.name);
}

TEST(CombatantList, get_count) {
    auto list = get_test_list();

    list[1].hp = 0;
    list[2].hp = 1;
    list[4].hp = 0;

    ASSERT_EQ(3, list.get_count(oldknights::Alleigance::Hero));
    ASSERT_EQ(2, list.get_count(oldknights::Alleigance::Hero, true));
    
    ASSERT_EQ(1, list.get_count(oldknights::Alleigance::Bad));
    ASSERT_EQ(1, list.get_count(oldknights::Alleigance::Bad, true));
   
    ASSERT_EQ(1, list.get_count(oldknights::Alleigance::NPC));
    ASSERT_EQ(0, list.get_count(oldknights::Alleigance::NPC, true));
}

