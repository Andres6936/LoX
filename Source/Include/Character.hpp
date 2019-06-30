#ifndef _LoX_CHARACTER
#define _LoX_CHARACTER

#include "Common.hpp"
#include "Creature.hpp"

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

class Character : public Creature
{
    std::string _name;  // name
    UInt _age;          // age
    bool _sex;          // gender
    UChar _race;        // race
    UChar __class;      // class
    UChar _alignment;   // alignment

public:
    /*
     * Character constructor takes arguments to set the above attributes.
     * Only name is required, default values are provided for the others
     */
    explicit Character( std::string name, UInt age = 30, bool sex = true,
               UChar race = RACE_HUMAN, UChar _class = CLASS_FIGHTER,
               UChar alignment = TRUE_NEUTRAL );

    /* get methods for attributes */
    std::string Name( ) const
    { return _name; }

    UInt Age( ) const
    { return _age; }

    bool Sex( ) const
    { return _sex; }

    UChar Race( ) const
    { return _race; }

    UChar Class( ) const
    { return __class; }

    UChar Alignment( ) const
    { return _alignment; }
};

#endif
