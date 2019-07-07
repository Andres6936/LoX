#ifndef _LoX_ARMOUR
#define _LoX_ARMOUR

#pragma once

#include "Item/Include/Item.hpp"
#include "Item/Enum/EArmourSlot.hpp"

/* template used to describe armour items */
struct ArmourTemplate
{
    EItemTypes type;
    EArmourSlot slot;
    std::string name;
    UInt weight;
    UInt AC;
};

class Armour : public Item
{
    EArmourSlot slot; // what slot this armour is worn on
    UInt _AC;   // armour class

public:
    /* constructor takes an ArmourTemplate */
    explicit Armour( const ArmourTemplate &at ) :
            Item( at.name, EItemCategory::ARMOUR, at.type, at.weight ),
            slot( at.slot ),
            _AC( at.AC )
    { }

    // Getters Methods

    EArmourSlot GetSlot( ) const
    { return slot; }

    UInt AC( ) const
    { return _AC; }
};

#endif
