#ifndef _LoX_CREATURE
#define _LoX_CREATURE

#pragma once

#include "Entity/Enum/EEntityTypes.hpp"
#include "Include/Common.hpp"
#include "Include/EDirections.hpp"

class TheMatrix;

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
    Vector2D coordinate;                  // coordinates of this creature on map
    std::vector <Vector2D> vision;     // array of coordinates that this creature can see

    UInt strength;
    UInt dexterity;
    UInt speed;
    UInt endurance;
    UInt intelligence;
    UInt wisdom;
    UInt charisma;

    /* this function fills vision with level coordinates visible to this creature */
    void
    shadowcast( TheMatrix &level, UInt x, UInt y, UInt radius, UInt row, float start_slope, float end_slope, UInt xx,
                UInt xy, UInt yx, UInt yy );

public:

    // Constructs

    Entity( );

    virtual ~Entity( ) = default;

    // Methods

    void WalkAt( EDirections direction );

    /* this method explicitally sets coordinate */
    void Pos( Vector2D pos )
    { coordinate = pos; }

    /* this method calculates the Field-Of-View for this creature */
    void FOV( TheMatrix &level );

    // Getter Methods

    EEntityTypes GetType( ) const;

    UInt GetHp( ) const;

    UInt GetMaxHp( ) const;

    UInt GetMp( ) const;

    UInt GetMaxMp( ) const;

    UInt GetExperience( ) const;

    Vector2D &GetCoordinate( );

    UInt GetCoordinateX( ) const;

    UInt GetCoordinateY( ) const;

    std::vector <Vector2D> GetVision( ) const;

    // Setter Methods

    void SetType( EEntityTypes nType );

};

#endif
