#ifndef _LoX_RANGED
#define _LoX_RANGED

#include "item.hpp"

/* template used to describe ranged items */
struct RangedTemplate
{
    UInt type;
    std::string name;
    UInt weight;
    Die dmg;
    UInt crit;
    UInt range;
};

class Ranged : public Item
{
    Die _dmg;       // damage die
    UInt _crit;     // critical multiplier
    UInt _range;    // range

public:
    /* constructor takes a RangedTemplate */
    Ranged( const RangedTemplate &rt ) :
            Item( rt.name, ITEM_RANGED, rt.type, rt.weight ),
            _dmg( rt.dmg ),
            _crit( rt.crit ),
            _range( rt.range )
    { }

    /* get methods for attributes */
    Die Dmg( ) const
    { return _dmg; }

    UInt Crit( ) const
    { return _crit; }

    UInt Range( ) const
    { return _range; }
};

#endif
