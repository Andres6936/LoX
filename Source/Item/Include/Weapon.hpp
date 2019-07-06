#ifndef _LoX_WEAPON
#define _LoX_WEAPON

#pragma once

#include "Item/Include/Item.hpp"
#include "Include/DieRoll.hpp"

/* template used to describe weapon items */
struct WeaponTemplate
{
    EItemTypes type;
    UInt style;
    std::string name;
    UInt weight;
    Die dmg;
    UInt crit;
};

/* all available weapon styles */
enum WeaponStyles
{
    WEAPON_SLASHING,
    WEAPON_PIERCING,
    WEAPON_BLUDGEONING
};

class Weapon : public Item
{
    UInt _style;    // weapon style
    Die _dmg;       // hit die
    UInt _crit;     // critical multiplier

public:
    /* constructor takes a WeaponTemplate */
    Weapon( const WeaponTemplate &wt ) :
            Item( wt.name, ITEM_WEAPON, wt.type, wt.weight ),
            _style( wt.style ),
            _dmg( wt.dmg ),
            _crit( wt.crit )
    { }

    /* get methods for attributes */
    UInt Style( ) const
    { return _style; }

    Die Dmg( ) const
    { return _dmg; }

    UInt Crit( ) const
    { return _crit; }
};

#endif
