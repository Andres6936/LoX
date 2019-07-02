#ifndef _LoX_CREATURE
#define _LoX_CREATURE

#pragma once

#include "Entity/Enum/EEntityTypes.hpp"
#include "Include/Common.hpp"

class Level;

class Entity
{
    /**
     * Type of this creature.
     */
    EEntityTypes type;

    UInt hp;                       // hit points
    UInt maxHp;                   // maximum hit points
    UInt mp;                       // mana points
    UInt maxMp;                   // maximum mana points
    UInt experience;                       // experience points
    Vector2D coordinate{ };                  // coordinates of this creature on map
    std::vector <Vector2D> vision;     // array of coordinates that this creature can see

    UInt strength;
    UInt dexterity;
    UInt speed;
    UInt endurance;
    UInt intelligence;
    UInt wisdom;
    UInt charisma;

    /* this function fills vision with level coordinates visible to this creature */
    void shadowcast( Level &level, UInt x, UInt y, UInt radius, UInt row, float start_slope, float end_slope, UInt xx,
                     UInt xy, UInt yx, UInt yy );

public:

    Entity( );

    virtual ~Entity( ) = default;

    /* this method adds a vector (in the form of two ints) to coordinate */
    void AddPos( int x, int y )
    {
        coordinate.x += x;
        coordinate.y += y;
    }

    /* this method explicitally sets coordinate */
    void Pos( Vector2D pos )
    { coordinate = pos; }

    /* this method calculates the Field-Of-View for this creature */
    void FOV( Level &level );

    // Getter Methods

    EEntityTypes GetType( ) const;

    UInt Hp( ) const
    { return hp; }

    UInt MaxHp( ) const
    { return maxHp; }

    UInt Mp( ) const
    { return mp; }

    UInt MaxMp( ) const
    { return maxMp; }

    UInt Xp( ) const
    { return experience; }

    Vector2D Pos( ) const
    { return coordinate; }

    UInt X( ) const
    { return coordinate.x; }

    UInt Y( ) const
    { return coordinate.y; }

    std::vector <Vector2D> Vis( ) const
    { return vision; }

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

    // Setter Methods

    void SetType( EEntityTypes nType );

    /* VIRTUAL METHODS */

    /*
     * This method is used in the Character class to determine race.
     * It has no use here, so simply returns 255.
     */
    virtual UChar Race( ) const
    { return 255; }
};

#endif
