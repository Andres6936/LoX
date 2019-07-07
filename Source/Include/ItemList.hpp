#ifndef _LoX_ITEMLIST
#define _LoX_ITEMLIST

#pragma once

#include "Include/Common.hpp"
#include "Item/Include/Armour.hpp"
#include "Item/Include/Weapon.hpp"
#include "Item/Include/Ranged.hpp"

/* lookup table of all armour in the game */
const ArmourTemplate armourTemplates[] = {
        /* ARMOUR_HELMET */
        { ITEM_TYPE_MUNDANE, EArmourSlot::HELMET, "Leather Helmet",    5,  1 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::HELMET, "Hide Helmet",       10, 2 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::HELMET, "Steel Helmet",      20, 4 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::HELMET, "Dwarven Helmet",    25, 6 },
        { ITEM_TYPE_MAGIC,   EArmourSlot::HELMET, "Elven Helmet",      10, 6 },
        { ITEM_TYPE_EPIC,    EArmourSlot::HELMET, "Draconian Helmet",  45, 8 },

        /* ARMOUR_TORSO */
        { ITEM_TYPE_MUNDANE, EArmourSlot::TORSO,  "Leather Armour",    15, 2 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::TORSO,  "Hide Armour",       25, 3 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::TORSO,  "Steel Armour",      50, 7 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::TORSO,  "Dwarven Armour",    55, 8 },
        { ITEM_TYPE_MAGIC,   EArmourSlot::TORSO,  "Elven Armour",      25, 8 },
        { ITEM_TYPE_EPIC,    EArmourSlot::TORSO,  "Draconian Armour",  75, 10 },

        /* ARMOUR_LEGS */
        { ITEM_TYPE_MUNDANE, EArmourSlot::LEGS,   "Leather Greaves",   10, 1 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::LEGS,   "Hide Greaves",      15, 2 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::LEGS,   "Steel Greaves",     25, 5 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::LEGS,   "Dwarven Greaves",   35, 6 },
        { ITEM_TYPE_MAGIC,   EArmourSlot::LEGS,   "Elven Greaves",     15, 6 },
        { ITEM_TYPE_EPIC,    EArmourSlot::LEGS,   "Draconian Greaves", 55, 8 },

        /* ARMOUR_HANDS */
        { ITEM_TYPE_MUNDANE, EArmourSlot::HANDS,  "Leather Gloves",    2,  1 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::HANDS,  "Hide Gloves",       5,  2 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::HANDS,  "Steel Gloves",      10, 3 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::HANDS,  "Dwarven Gloves",    20, 4 },
        { ITEM_TYPE_MAGIC,   EArmourSlot::HANDS,  "Elven Gloves",      5,  4 },
        { ITEM_TYPE_EPIC,    EArmourSlot::HANDS,  "Draconian Gloves",  40, 6 },

        /* ARMOUR_FEET */
        { ITEM_TYPE_MUNDANE, EArmourSlot::FEET,   "Leather Boots",     2,  1 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::FEET,   "Hide Boots",        5,  2 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::FEET,   "Steel Boots",       10, 3 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::FEET,   "Dwarven Boots",     20, 4 },
        { ITEM_TYPE_MAGIC,   EArmourSlot::FEET,   "Elven Boots",       5,  4 },
        { ITEM_TYPE_EPIC,    EArmourSlot::FEET,   "Draconian Boots",   40, 6 },

        /* ARMOUR_SHIELD */
        { ITEM_TYPE_MUNDANE, EArmourSlot::SHIELD, "Leather Shield",    12, 2 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::SHIELD, "Hide Shield",       17, 3 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::SHIELD, "Steel Shield",      27, 7 },
        { ITEM_TYPE_MUNDANE, EArmourSlot::SHIELD, "Dwarven Shield",    37, 8 },
        { ITEM_TYPE_MAGIC,   EArmourSlot::SHIELD, "Elven Shield",      17, 3 },
        { ITEM_TYPE_EPIC,    EArmourSlot::SHIELD, "Draconian Shield",  57, 10 },
};

/* lookup table of all weapons in the game */
const WeaponTemplate weaponTemplates[] = {
        /* WEAPON_SLASHING */
        { ITEM_TYPE_MUNDANE, WEAPON_SLASHING,    "Iron Dagger",         1, { 1, 4, 0 },  2 },
        { ITEM_TYPE_MUNDANE, WEAPON_SLASHING,    "Iron Sword",          2, { 1, 6, 0 },  2 },
        { ITEM_TYPE_MUNDANE, WEAPON_SLASHING,    "Iron Waraxe",         3, { 1, 6, 0 },  3 },
        { ITEM_TYPE_MUNDANE, WEAPON_SLASHING,    "Steel Dagger",        2, { 1, 4, 2 },  2 },
        { ITEM_TYPE_MUNDANE, WEAPON_SLASHING,    "Steel Sword",         3, { 1, 6, 2 },  2 },
        { ITEM_TYPE_MUNDANE, WEAPON_SLASHING,    "Steel Waraxe",        4, { 1, 6, 2 },  3 },
        { ITEM_TYPE_MAGIC,   WEAPON_SLASHING,    "Silver Dagger",       2, { 1, 4, 3 },  2 },
        { ITEM_TYPE_MAGIC,   WEAPON_SLASHING,    "Silver Sword",        3, { 1, 6, 3 },  2 },
        { ITEM_TYPE_MAGIC,   WEAPON_SLASHING,    "Silver Waraxe",       4, { 1, 6, 3 },  3 },
        { ITEM_TYPE_MAGIC,   WEAPON_SLASHING,    "Elven Dagger",        1, { 1, 4, 6 },  2 },
        { ITEM_TYPE_MAGIC,   WEAPON_SLASHING,    "Elven Sword",         2, { 1, 6, 6 },  2 },
        { ITEM_TYPE_MAGIC,   WEAPON_SLASHING,    "Elven Waraxe",        3, { 1, 6, 6 },  3 },
        { ITEM_TYPE_EPIC,    WEAPON_SLASHING,    "Draconian Dagger",    4, { 1, 4, 10 }, 3 },
        { ITEM_TYPE_EPIC,    WEAPON_SLASHING,    "Draconian Sword",     5, { 1, 6, 10 }, 3 },
        { ITEM_TYPE_EPIC,    WEAPON_SLASHING,    "Draconian Waraxe",    6, { 1, 6, 10 }, 4 },

        /* WEAPON_PIERCING */
        { ITEM_TYPE_MUNDANE, WEAPON_PIERCING,    "Iron Spear",          3, { 1, 8, 0 },  3 },
        { ITEM_TYPE_MUNDANE, WEAPON_PIERCING,    "Iron Pick",           6, { 1, 6, 0 },  4 },
        { ITEM_TYPE_MUNDANE, WEAPON_PIERCING,    "Iron Rapier",         2, { 1, 6, 0 },  2 },
        { ITEM_TYPE_MUNDANE, WEAPON_PIERCING,    "Steel Spear",         4, { 1, 8, 2 },  3 },
        { ITEM_TYPE_MUNDANE, WEAPON_PIERCING,    "Steel Pick",          7, { 1, 6, 2 },  4 },
        { ITEM_TYPE_MUNDANE, WEAPON_PIERCING,    "Steel Rapier",        3, { 1, 6, 2 },  2 },
        { ITEM_TYPE_MAGIC,   WEAPON_PIERCING,    "Silver Spear",        4, { 1, 8, 3 },  3 },
        { ITEM_TYPE_MAGIC,   WEAPON_PIERCING,    "Silver Pick",         7, { 1, 6, 3 },  4 },
        { ITEM_TYPE_MAGIC,   WEAPON_PIERCING,    "Silver Rapier",       3, { 1, 6, 3 },  2 },
        { ITEM_TYPE_MAGIC,   WEAPON_PIERCING,    "Elven Spear",         3, { 1, 8, 6 },  3 },
        { ITEM_TYPE_MAGIC,   WEAPON_PIERCING,    "Elven Pick",          6, { 1, 6, 6 },  4 },
        { ITEM_TYPE_MAGIC,   WEAPON_PIERCING,    "Elven Rapier",        2, { 1, 6, 6 },  2 },
        { ITEM_TYPE_EPIC,    WEAPON_PIERCING,    "Draconian Spear",     6, { 1, 8, 10 }, 4 },
        { ITEM_TYPE_EPIC,    WEAPON_PIERCING,    "Draconian Pick",      9, { 1, 6, 10 }, 5 },
        { ITEM_TYPE_EPIC,    WEAPON_PIERCING,    "Draconian Rapier",    5, { 1, 6, 10 }, 3 },

        /* WEAPON_BLUDGEONING */
        { ITEM_TYPE_MUNDANE, WEAPON_BLUDGEONING, "Iron Club",           3, { 1, 6, 0 },  2 },
        { ITEM_TYPE_MUNDANE, WEAPON_BLUDGEONING, "Iron Mace",           6, { 1, 8, 0 },  2 },
        { ITEM_TYPE_MUNDANE, WEAPON_BLUDGEONING, "Iron Warhammer",      5, { 1, 8, 0 },  3 },
        { ITEM_TYPE_MUNDANE, WEAPON_BLUDGEONING, "Steel Club",          4, { 1, 6, 2 },  2 },
        { ITEM_TYPE_MUNDANE, WEAPON_BLUDGEONING, "Steel Mace",          7, { 1, 8, 2 },  2 },
        { ITEM_TYPE_MUNDANE, WEAPON_BLUDGEONING, "Steel Warhammer",     6, { 1, 8, 2 },  3 },
        { ITEM_TYPE_MAGIC,   WEAPON_BLUDGEONING, "Silver Club",         4, { 1, 6, 3 },  2 },
        { ITEM_TYPE_MAGIC,   WEAPON_BLUDGEONING, "Silver Mace",         7, { 1, 8, 3 },  2 },
        { ITEM_TYPE_MAGIC,   WEAPON_BLUDGEONING, "Silver Warhammer",    6, { 1, 8, 3 },  3 },
        { ITEM_TYPE_MAGIC,   WEAPON_BLUDGEONING, "Elven Club",          3, { 1, 6, 6 },  2 },
        { ITEM_TYPE_MAGIC,   WEAPON_BLUDGEONING, "Elven Mace",          6, { 1, 8, 6 },  2 },
        { ITEM_TYPE_MAGIC,   WEAPON_BLUDGEONING, "Elven Warhammer",     5, { 1, 8, 6 },  3 },
        { ITEM_TYPE_EPIC,    WEAPON_BLUDGEONING, "Draconian Club",      6, { 1, 6, 10 }, 3 },
        { ITEM_TYPE_EPIC,    WEAPON_BLUDGEONING, "Draconian Mace",      9, { 1, 8, 10 }, 3 },
        { ITEM_TYPE_EPIC,    WEAPON_BLUDGEONING, "Draconian Warhammer", 8, { 1, 8, 10 }, 4 },
};

/* lookup table of all ranged weapons in the game */
const RangedTemplate rangedTemplates[] = {
        { ITEM_TYPE_MUNDANE, "Crossbow",           4, { 1, 8, 0 }, 2, 8 },
        { ITEM_TYPE_MUNDANE, "Shortbow",           2, { 1, 6, 0 }, 3, 6 },
        { ITEM_TYPE_MUNDANE, "Longbow",            3, { 1, 8, 0 }, 3, 10 },
        { ITEM_TYPE_MAGIC,   "Elven Crossbow",     3, { 1, 8, 3 }, 2, 8 },
        { ITEM_TYPE_MAGIC,   "Elven Shortbow",     1, { 1, 6, 3 }, 3, 6 },
        { ITEM_TYPE_MAGIC,   "Elven Longbow",      2, { 1, 8, 3 }, 3, 10 },
        { ITEM_TYPE_EPIC,    "Draconian Crossbow", 6, { 1, 8, 8 }, 3, 8 },
        { ITEM_TYPE_EPIC,    "Draconian Shortbow", 4, { 1, 6, 8 }, 4, 6 },
        { ITEM_TYPE_EPIC,    "Draconian Longbow",  5, { 1, 8, 8 }, 4, 10 },
};

#endif
