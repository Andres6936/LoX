#ifndef _LoX_ITEM
#define _LoX_ITEM

#pragma once

#include "Include/Common.hpp"

class Item;

class Armour;

class Weapon;

class Ranged;

typedef std::shared_ptr <Item> ItemPointer;

/* enumeration of all item categories in the game */
enum ItemCategories
{
    ITEM_ARMOUR,
    ITEM_WEAPON,
    ITEM_RANGED
};

/* enumeration of all item types in the game */
enum ItemTypes
{
    ITEMTYPE_MUNDANE,
    ITEMTYPE_MAGIC,
    ITEMTYPE_EPIC,
    ITEMTYPE_ARTIFACT,
    ITEMTYPE_PSIONIC
};

class Item
{
    std::string _name;  // name of item
    UInt _category;     // item category
    UInt _type;         // item type
    UInt _weight;       // item weight

public:
    /* constructor takes all of the above attributes as parameters */
    Item( std::string name, UInt category, UInt type, UInt weight ) :
            _name( name ),
            _category( category ),
            _type( type ),
            _weight( weight )
    { }

    /* virtual destructor for Item objects */
    virtual ~Item( )
    { }

    /* get methods for attributes */
    std::string Name( ) const
    { return _name; }

    UInt Category( ) const
    { return _category; }

    UInt Type( ) const
    { return _type; }

    UInt Weight( ) const
    { return _weight; }

    /* this method generates an item and returns a shared pointer to it */
    static ItemPointer Generate( );
};

#endif
