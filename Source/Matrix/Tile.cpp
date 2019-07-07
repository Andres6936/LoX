#include "Matrix/Include/Tile.hpp"

Tile::Tile( )
{
    type = TYPE_TILE_NONE;
    passable = false;
    opaque = false;
}

Tile::Tile( const ETypeTiles nType, const bool nPassable, const bool nOpaque )
{
    type = nType;
    passable = nPassable;
    opaque = nOpaque;
}

Tile::~Tile( ) = default;

bool Tile::HasItems( ) const
{
    return !items.empty( );
}

ItemPointer Tile::SeeLastItem( ) const
{
    return items.back( );
}
