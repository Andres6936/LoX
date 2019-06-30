#ifndef _LoX_COMMON
#define _LoX_COMMON

#pragma once

/* version string */
#define _LoX_VERSION "0.1.0.4"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <memory>
#include <string>
#include <random>
#include <vector>
#include <list>

typedef unsigned char UChar;

typedef unsigned int UInt;

/* this structure is used to describe 2D positions and movements in the game */
struct Vector2D
{
    UInt x;
    UInt y;

    /* overload for '==' operator to work correctly */
    bool operator==( const Vector2D &vect )
    {
        return x == vect.x && y == vect.y;
    }
};

#endif
