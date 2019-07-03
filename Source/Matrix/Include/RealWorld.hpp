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

    Tile *world;

public:

    // Constructs

    RealWorld( );

    RealWorld( unsigned int nWIDTH, unsigned int nHEIGHT );

    // Destructs

    virtual ~RealWorld( );

    // Methods

    unsigned int GetIndex( unsigned int x, unsigned int y );

};


#endif //LOX_REALWORLD_HPP
