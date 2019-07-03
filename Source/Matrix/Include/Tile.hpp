#ifndef LOX_TILE_HPP
#define LOX_TILE_HPP

#pragma once

#include <Include/Item.hpp>

class Tile
{

public:

    std::vector <item_ptr> items;    // array of items on this tile
    UChar type;                     // type of tile
    bool passable;                  // if this tile is passable by creatures
    bool opaque;                    // if this tile blocks vision
};


#endif //LOX_TILE_HPP
