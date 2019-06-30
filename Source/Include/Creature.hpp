#ifndef _LoX_CREATURE
#define _LoX_CREATURE

#pragma once

#include "Include/Common.hpp"

class Level;

/* enumeration of all available creature types in the game */
enum CreatureTypes
{
    CREATURE_CHARACTER,
    CREATURE_BUGBEAR,
    CREATURE_CENTAUR,
    CREATURE_DRAGON,
    CREATURE_DROW_ELF,
    CREATURE_GARGOYLE,
    CREATURE_GIANT,
    CREATURE_GNOLL,
    CREATURE_GOBLIN,
    CREATURE_HOBGOBLIN,
    CREATURE_KOBOLD,
    CREATURE_LIZARD,
    CREATURE_MINOTAUR,
    CREATURE_OGRE,
    CREATURE_OGRE_MAGE,
    CREATURE_ORC,
    CREATURE_RAKSHASA,
    CREATURE_RODENT,
    CREATURE_SATYR,
    CREATURE_TROGLODYTE,
    CREATURE_TROLL,
    CREATURE_UNBODIED
};

class Creature
{
    UChar _type;                    // type of this creature
    UInt _hp;                       // hit points
    UInt _max_hp;                   // maximum hit points
    UInt _mp;                       // mana points
    UInt _max_mp;                   // maximum mana points
    UInt _xp;                       // experience points
    Vector2D _pos;                  // coordinates of this creature on map
    std::vector <Vector2D> _vis;     // array of coordinates that this creature can see

    UInt strength;
    UInt dexterity;
    UInt speed;
    UInt endurance;
    UInt intelligence;
    UInt wisdom;
    UInt charisma;

    /* this function fills _vis with level coordinates visible to this creature */
    void shadowcast( Level &level, UInt x, UInt y, UInt radius, UInt row, float start_slope, float end_slope, UInt xx,
                     UInt xy, UInt yx, UInt yy );

public:
    /* Creature constructor takes an argument to set the creature type */
    explicit Creature( UChar type );

    /* virtual destructor for Creature class */
    virtual ~Creature( ) = default;

    /* this method adds a vector (in the form of two ints) to _pos */
    void AddPos( int x, int y )
    {
        _pos.x += x;
        _pos.y += y;
    }

    /* this method explicitally sets _pos */
    void Pos( Vector2D pos )
    { _pos = pos; }

    /* this method calculates the Field-Of-View for this creature */
    void FOV( Level &level );

    /* get methods for attributes */
    UChar Type( ) const
    { return _type; }

    UInt Hp( ) const
    { return _hp; }

    UInt MaxHp( ) const
    { return _max_hp; }

    UInt Mp( ) const
    { return _mp; }

    UInt MaxMp( ) const
    { return _max_mp; }

    UInt Xp( ) const
    { return _xp; }

    Vector2D Pos( ) const
    { return _pos; }

    UInt X( ) const
    { return _pos.x; }

    UInt Y( ) const
    { return _pos.y; }

    std::vector <Vector2D> Vis( ) const
    { return _vis; }

    UInt Str( ) const
    { return strength; }

    UInt Dex( ) const
    { return dexterity; }

    UInt Spd( ) const
    { return speed; }

    UInt End( ) const
    { return endurance; }

    UInt Int( ) const
    { return intelligence; }

    UInt Wis( ) const
    { return wisdom; }

    UInt Cha( ) const
    { return charisma; }

    /* VIRTUAL METHODS */

    /*
     * This method is used in the Character class to determine race.
     * It has no use here, so simply returns 255.
     */
    virtual UChar Race( ) const
    { return 255; }
};

#endif
