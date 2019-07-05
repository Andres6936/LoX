#ifndef LOX_REALWORLD_HPP
#define LOX_REALWORLD_HPP

#pragma once

#include "Tile.hpp"

class RealWorld
{

private:

    // Constant Fields

    /**
     * Width of level.
     */
    const unsigned int WIDTH;

    /**
     * Height of level.
     */
    const unsigned int HEIGHT;

    /**
     * Probability of filling a tile with a wall.
     */
    const unsigned short FILL_PROBABILITY = 40;

    /**
     * Values used in generation algorithm.
     */
    const unsigned short R1_CUT_OFF = 5;

    /**
     * Values used in generation algorithm.
     */
    const unsigned short R2_CUT_OFF = 0;

    Tile *world;

public:

    // Constructs

    RealWorld( );

    RealWorld( unsigned int nWIDTH, unsigned int nHEIGHT );

    // Destructs

    virtual ~RealWorld( );

    // Methods

    unsigned int GetIndex( unsigned int x, unsigned int y ) const;

    Tile &GetTileIndexAt( unsigned int x, unsigned int y );

    Tile GetRandomTile( ) const;

    void FillWorldWithRandomTiles( ) const;

    void FillWorldWithOuterWalls( ) const;

    void RunCellularAutomata( ) const;

};


#endif //LOX_REALWORLD_HPP
