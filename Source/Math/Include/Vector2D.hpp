#ifndef LOX_VECTOR2D_HPP
#define LOX_VECTOR2D_HPP

#pragma once

/**
 * Vector used to describe 2D positions and movements in the game.
 */
class Vector2D
{

public:

    // Fields

    int x;
    int y;

    // Constructs

    /**
     * Default construct
     */
    Vector2D( )
    {
        x = 0;
        y = 0;
    }

    /**
     * Initialize the Vector with the coordinates pass for parameters.
     * @param nX Coordiante in x.
     * @param nY Coordiante in y.
     */
    Vector2D( const int nX, const int nY )
    {
        x = nX;
        y = nY;
    }

    // Methods

    // Operators

    /**
     * Operator of equality for vectors.
     * @param vect Comparison vector.
     * @return True if x & y are the same, False in any other case.
     */
    bool operator==( const Vector2D &vect )
    {
        return x == vect.x && y == vect.y;
    }
};

#endif //LOX_VECTOR2D_HPP
