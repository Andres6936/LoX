#ifndef LOX_TILE_HPP
#define LOX_TILE_HPP

#pragma once

#include <Include/Item.hpp>
#include <Matrix/Enum/ETypeTiles.hpp>

class Tile
{

public:

    // Fields

    /**
     * Type of tile.
     */
    ETypeTiles type;

    /**
     * Is passable by entities.
     */
    bool passable;

    /**
     * This tile blocks vision.
     */
    bool opaque;

    /**
     * Items on this tile
     */
    std::vector <item_ptr> items;

    // Constructs

    Tile( );

    Tile( ETypeTiles nType, bool nPassable, bool nOpaque );

    // Destructs

    virtual ~Tile( );

    // Methods

};


#endif //LOX_TILE_HPP
