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
    Die die = { 1, ITEM_RANGED + 1, -1 };
    UInt cat = DieRoll::Roll( die );

    ItemPointer item;

    switch ( cat )
    {
        case ITEM_ARMOUR:
            die.Set( 1, sizeof( armourTemplates ) / sizeof( armourTemplates[ 0 ] ), -1 );
            item = std::make_shared <Armour>( armourTemplates[ DieRoll::Roll( die ) ] );
            break;

        case ITEM_WEAPON:
            die.Set( 1, sizeof( weaponTemplates ) / sizeof( weaponTemplates[ 0 ] ), -1 );
            item = std::make_shared <Weapon>( weaponTemplates[ DieRoll::Roll( die ) ] );
            break;

        case ITEM_RANGED:
            die.Set( 1, sizeof( rangedTemplates ) / sizeof( rangedTemplates[ 0 ] ), -1 );
            item = std::make_shared <Ranged>( rangedTemplates[ DieRoll::Roll( die ) ] );
            break;

        default:
            item = std::make_shared <Item>( "Nothing", ITEM_NONE, ITEM_TYPE_NONE, 0 );
    }

    return item;
}
