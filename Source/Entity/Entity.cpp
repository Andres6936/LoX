#include "Entity/Include/Entity.hpp"
#include "Include/Level.hpp"

Entity::Entity( )
{
    type = CREATURE_NONE;
    hp = 8;
    maxHp = 8;
    mp = 8;
    maxMp = 8;
    experience = 0;
    coordinate = { 0, 0 };

    strength = 8;
    dexterity = 8;
    speed = 8;
    endurance = 8;
    intelligence = 8;
    wisdom = 8;
    charisma = 8;

}

void Entity::WalkAt( EDirections direction )
{
    if ( direction == NORTH )
    {
        coordinate.y += -1;
    }
    else if ( direction == WEST )
    {
        coordinate.x += -1;
    }
    else if ( direction == NORTH_WEST )
    {
        coordinate.x += -1;
        coordinate.y += -1;
    }
    else if ( direction == SOUTH_WEST )
    {
        coordinate.x += -1;
        coordinate.y += 1;
    }
    else if ( direction == EAST )
    {
        coordinate.x += 1;
    }
    else if ( direction == NORTH_EAST )
    {
        coordinate.x += 1;
        coordinate.y += -1;
    }
    else if ( direction == SOUTH_EAST )
    {
        coordinate.x += 1;
        coordinate.y += 1;
    }
    else if ( direction == SOUTH )
    {
        coordinate.y += 1;
    }
}

EEntityTypes Entity::GetType( ) const
{
    return type;
}

UInt Entity::GetHp( ) const
{
    return hp;
}

UInt Entity::GetMaxHp( ) const
{
    return maxHp;
}

UInt Entity::GetMp( ) const
{
    return mp;
}

UInt Entity::GetMaxMp( ) const
{
    return maxMp;
}

UInt Entity::GetExperience( ) const
{
    return experience;
}

Vector2D Entity::GetCoordinate( ) const
{
    return coordinate;
}

UInt Entity::GetCoordinateX( ) const
{
    return coordinate.x;
}

UInt Entity::GetCoordinateY( ) const
{
    return coordinate.y;
}

std::vector <Vector2D> Entity::GetVision( ) const
{
    return vision;
}

void Entity::SetType( EEntityTypes nType )
{
    type = nType;
}

void
Entity::shadowcast( Level &level, UInt x, UInt y, UInt radius, UInt row, float start_slope, float end_slope, UInt xx,
                      UInt xy, UInt yx, UInt yy )
{
    if ( start_slope < end_slope )
    { return; }
    float next_start_slope = start_slope;

    for ( UInt i = row; i <= radius; i++ )
    {
        bool blocked = false;

        for ( int dx = -i, dy = -i; dx <= 0; dx++ )
        {
            float l_slope = ( dx - 0.5 ) / ( dy + 0.5 );
            float r_slope = ( dx + 0.5 ) / ( dy - 0.5 );

            if ( start_slope < r_slope )
            { continue; }
            else if ( end_slope > l_slope )
            { break; }

            int sax = dx * xx + dy * xy;
            int say = dx * yx + dy * yy;
            if (( sax < 0 && ( UInt ) std::abs( sax ) > x ) || ( say < 0 && ( UInt ) std::abs( say ) > y ))
            { continue; }

            UInt ax = x + sax;
            UInt ay = y + say;
            if ( ax >= level.W( ) || ay >= level.H( ))
            { continue; }

            UInt radius2 = radius * radius;
            if (( UInt )( dx * dx + dy * dy ) < radius2 )
            {
                Vector2D tmp = { ax, ay };
                vision.push_back( tmp );
            }

            if ( blocked )
            {
                if ( level.Map( )[ ay ][ ax ].opaque )
                {
                    next_start_slope = r_slope;
                    continue;
                }
                else
                {
                    blocked = false;
                    start_slope = next_start_slope;
                }
            }
            else if ( level.Map( )[ ay ][ ax ].opaque )
            {
                blocked = true;
                next_start_slope = r_slope;
                shadowcast( level, x, y, radius, i + 1, start_slope, l_slope, xx, xy, yx, yy );
            }
        }

        if ( blocked )
        { break; }
    }
}

const int octantMatrix[4][8] = {
        { 1, 0, 0,  -1, -1, 0,  0,  1 },
        { 0, 1, -1, 0,  0,  -1, 1,  0 },
        { 0, 1, 1,  0,  0,  -1, -1, 0 },
        { 1, 0, 0,  1,  -1, 0,  0,  -1 }
};

void Entity::FOV( Level &level )
{
    vision.clear( );
    for ( UInt i = 0; i < 8; i++ )
    {
        shadowcast( level, coordinate.x, coordinate.y, 10, 1, 1.0, 0.0, octantMatrix[ 0 ][ i ], octantMatrix[ 1 ][ i ],
                    octantMatrix[ 2 ][ i ], octantMatrix[ 3 ][ i ] );
    }
}
