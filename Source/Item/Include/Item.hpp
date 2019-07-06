#ifndef _LoX_ITEM
#define _LoX_ITEM

#pragma once

#include "Include/Common.hpp"
#include "Item/Enum/EItemTypes.hpp"
#include "Item/Enum/EItemCategories.hpp"

class Item;

typedef std::shared_ptr <Item> ItemPointer;

class Item
{

private:

    std::string name;
    EItemCategories category;
    EItemTypes type;
    UInt weight;

public:

    Item( std::string name, EItemCategories category, EItemTypes type, UInt weight ) :
            name( name ),
            category( category ),
            type( type ),
            weight( weight )
    { }

    virtual ~Item( ) = default;

    UInt GetWeight( ) const;

    std::string GetName( ) const;

    EItemCategories GetCategory( ) const;

    EItemTypes GetType( ) const;

    /* this method generates an item and returns a shared pointer to it */
    static ItemPointer Generate( );
};

#endif