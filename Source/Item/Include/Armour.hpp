#ifndef _LoX_ARMOUR
#define _LoX_ARMOUR

#pragma once

#include "Item/Include/Item.hpp"

/* template used to describe armour items */
struct ArmourTemplate
{
    EItemTypes type;
    UInt limb;
    std::string name;
    UInt weight;
    UInt AC;
};

/* limbs armour can be for */
enum ArmourLimbs
{
    ARMOUR_HELMET,
    ARMOUR_TORSO,
    ARMOUR_LEGS,
    ARMOUR_FEET,
    ARMOUR_HANDS,
    ARMOUR_SHIELD
};

class Armour : public Item
{
    UInt _limb; // what limb this armour is worn on
    UInt _AC;   // armour class

public:
    /* constructor takes an ArmourTemplate */
    Armour( const ArmourTemplate &at ) :
            Item( at.name, EItemCategory::ARMOUR, at.type, at.weight ),
            _limb( at.limb ),
            _AC( at.AC )
    { }

    /* get methods for attributes */
    UInt Limb( ) const
    { return _limb; }

    UInt AC( ) const
    { return _AC; }
};

#endif
