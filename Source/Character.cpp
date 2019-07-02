#include "Include/Character.hpp"

Character::Character( ) : Entity( )
{
    SetType( CREATURE_CHARACTER );

    name = "Comodin";
    sex = true;
    age = 69;
    race = RACE_HUMAN;
    aClass = CLASS_FIGHTER;
    alignment = TRUE_NEUTRAL;
}

Character::Character( std::string nName ) : Entity( )
{
    SetType( CREATURE_CHARACTER );

    name = nName;
    sex = true;
    age = 69;
    race = RACE_HUMAN;
    aClass = CLASS_FIGHTER;
    alignment = TRUE_NEUTRAL;
}

std::string Character::GetName( ) const
{
    return name;
}

bool Character::GetSex( ) const
{
    return sex;
}

UInt Character::GetAge( ) const
{
    return age;
}

UChar Character::GetRace( ) const
{
    return race;
}

UChar Character::GetClass( ) const
{
    return aClass;
}

UChar Character::GetAlignment( ) const
{
    return alignment;
}
