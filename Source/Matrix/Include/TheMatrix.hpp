#ifndef _LoX_LEVEL
#define _LoX_LEVEL

#pragma once

#include "Include/Common.hpp"
#include "Include/Item.hpp"
#include <Entity/Include/Entity.hpp>
#include "Matrix/Enum/EMapTiles.hpp"
#include "Tile.hpp"

#include <ctime>
#include <vector>

#define LEVEL_WIDTH 64
#define LEVEL_HEIGHT 64

/* lookup table for all map tiles in the game */
const Tile tiles[] = {
        {{ }, MAP_FLOOR,      true,  false },
        {{ }, MAP_WALL,       false, true },
        {{ }, MAP_STAIR_UP,   true,  false },
        {{ }, MAP_STAIR_DOWN, true,  false }
};

class TheMatrix
{
    Tile **map;                        // 2D array of tiles that form a level
    Vector2D stairDown; // coordinates of stairs up and down
    Vector2D stairUp; // coordinates of stairs up and down
    std::vector <Entity> vectorEntities;   // array of creatures on this level

    /* these attributes are used when generating levels only */
    int fillProbability;              // probability of filling a tile with a wall
    int r1Cutoff; // cutoff values used in generation algorithm
    int r2Cutoff; // cutoff values used in generation algorithm
    int passes;                // number of algorithm passes made when generating

    /* this method is used by the Generate method to randomly choose a tile type */
    int randpick( );

public:

    // Constant Fields

    /**
     * Width of level.
     */
    const unsigned int WIDTH;

    /**
     * Height of level.
     */
    const unsigned int HEIGHT;

    // Constructs

    TheMatrix( );

    TheMatrix( int nWidth, int nHeight );

    // Destructs

    ~TheMatrix( );

    // Methods

    /**
     * Generate a new map for this level.
     */
    void GenerateLevel( );

    /**
     * Allow objects easier access to items on a level.
     * @param coordinate Coordinate.
     * @return True if there is an Item in the position, False in any other case.
     */
    bool HasItem( Vector2D coordinate ) const;

    item_ptr SeeItem( Vector2D coordinate ) const;

    item_ptr GetItem( Vector2D coordinate );

    void PutItem( Vector2D pos, item_ptr item );

    /* get methods for attributes */
    Tile **Map( ) const
    { return map; }

    Vector2D StairDown( ) const
    { return stairDown; }

    Vector2D StairUp( ) const
    { return stairUp; }

};

#endif
