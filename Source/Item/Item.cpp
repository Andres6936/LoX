#include "Item/Include/Item.hpp"

#include "Include/ItemList.hpp"

UInt Item::GetWeight( ) const
{
    return weight;
}

std::string Item::GetName( ) const
{
    return name;
}

EItemCategories Item::GetCategory( ) const
{
    return category;
}

EItemTypes Item::GetType( ) const
{
    return type;
}

ItemPointer Item::Generate( )
{
    // Generate number random from 1 to 3.
    unsigned int cat = rand( ) % 3 + 1;

    Die die = { };
    ItemPointer item;

    if ( cat == 1 )
    {
        die.Set( 1, sizeof( armourTemplates ) / sizeof( armourTemplates[ 0 ] ), -1 );
        item = std::make_shared <Armour>( armourTemplates[ DieRoll::Roll( die ) ] );
    }
    else if ( cat == 2 )
    {
        die.Set( 1, sizeof( weaponTemplates ) / sizeof( weaponTemplates[ 0 ] ), -1 );
        item = std::make_shared <Weapon>( weaponTemplates[ DieRoll::Roll( die ) ] );
    }
    else if ( cat == 3 )
    {
        die.Set( 1, sizeof( rangedTemplates ) / sizeof( rangedTemplates[ 0 ] ), -1 );
        item = std::make_shared <Ranged>( rangedTemplates[ DieRoll::Roll( die ) ] );
    }
    else
    {
        item = std::make_shared <Item>( "Nothing", EItemCategories::NONE, ITEM_TYPE_NONE, 0 );
    }

    return item;
}
