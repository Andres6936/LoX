#ifndef _LoX_CHARACTER
#define _LoX_CHARACTER

#include "Common.hpp"
#include "Entity/Include/Entity.hpp"

/* enumeration of all available races in the game */
enum Races
{
    RACE_HUMAN,
    RACE_ELF,
    RACE_DWARF,
    RACE_HALFLING,
    RACE_GNOME,
    RACE_HALF_ORC,
};

/* enumeration of all available classes in the game */
enum Classes
{
    CLASS_BARBARIAN,
    CLASS_BARD,
    CLASS_CLERIC,
    CLASS_DRUID,
    CLASS_FIGHTER,
    CLASS_MONK,
    CLASS_PALADIN,
    CLASS_RANGER,
    CLASS_ROGUE,
    CLASS_SORCEROR,
    CLASS_WIZARD
};

/* enumeration of all available alignments in the game */
enum Alignments
{
    LAWFUL_GOOD,
    LAWFUL_NEUTRAL,
    LAWFUL_EVIL,
    NEUTRAL_GOOD,
    TRUE_NEUTRAL,
    NEUTRAL_EVIL,
    CHAOTIC_GOOD,
    CHAOTIC_NEUTRAL,
    CHAOTIC_EVIL
};

class Character : public Entity
{
    std::string name;

    bool sex;

    UInt age;

    UChar race;
    UChar aClass;
    UChar alignment;

public:

    Character( );

    explicit Character( std::string nName );

    // Getter Methods

    std::string GetName( ) const;

    bool GetSex( ) const;

    UInt GetAge( ) const;

    UChar GetRace( ) const;

    UChar GetClass( ) const;

    UChar GetAlignment( ) const;
};

#endif
