#ifndef _LoX_ITEM
#define _LoX_ITEM

#pragma once

#include "Include/Common.hpp"
#include "Item/Enum/EItemTypes.hpp"
#include "Item/Enum/EItemCategory.hpp"

class Item;

typedef std::shared_ptr <Item> ItemPointer;

class Item
{

private:

    // Fields

    UInt weight;
    std::string name;

    EItemCategory category;
    EItemTypes type;

public:

    // Constructs

    Item( std::string name, EItemCategory category, EItemTypes type, UInt weight ) :
            name( name ),
            category( category ),
            type( type ),
            weight( weight )
    { }

    // Destructs

    virtual ~Item( ) = default;

    // Methods

    UInt GetWeight( ) const;

    std::string GetName( ) const;

    EItemCategory GetCategory( ) const;

    EItemTypes GetType( ) const;

    /* this method generates an item and returns a shared pointer to it */
    static ItemPointer Generate( );
};

#endif
