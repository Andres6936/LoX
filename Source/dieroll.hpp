#ifndef _LoX_DIEROLL
#define _LoX_DIEROLL

#pragma once

#include "common.hpp"

/*
 * The Die structure is used to simulate dnd style dice rolls.
 * The structure is comprised of a number, representing the number of dice to roll;
 * a value, representing the number of sides on the dice;
 * and a modifier, which is added to the result.
 *
 * The modifier may be a positive or a negative value.
 */
struct Die
{
    UInt num;
    UInt val;
    int mod;

    void Set( UInt num, UInt val, int mod )
    {
        this->num = num;
        this->val = val;
        this->mod = mod;
    }
};

/*
 * DieRoll is a static class used to simulate dnd style dice rolls using the Die structure.
 */
class DieRoll
{
    static std::random_device seed_gen;
    static unsigned seed;
    static std::mt19937 mersenne_gen;

public:
    /*
     * This function takes a Die object and returns an integer value based on the roll.
     * Negative values (potentially caused by the modifier) will return zero.
     */
    static UInt Roll( Die die = { 1, 20, 0 } );
};

#endif
