#include "character.hpp"

Character::Character( std::string name, UInt age, bool sex,
                      UChar race, UChar _class, UChar alignment )
        : Creature( CREATURE_CHARACTER )
{
    _name = name;
    _age = age;
    _sex = sex;
    _race = race;
    __class = _class;
    _alignment = alignment;

    // generate starting stats
}
