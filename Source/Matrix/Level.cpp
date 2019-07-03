#include "Matrix/Include/Level.hpp"
#include "Include/Character.hpp"
#include "Include/DieRoll.hpp"

Level::Level( ) : WIDTH( 80 ), HEIGHT( 24 )
{
    fillProbability = 40;
    r1Cutoff = 5;
    r2Cutoff = 0;
    passes = 12;

    // Allocate memory for map
    map = new Tile *[HEIGHT];

    for ( UInt i = 0; i < HEIGHT; i++ )
    {
        map[ i ] = new Tile[WIDTH];
    }

    // Generate level
    this->GenerateLevel( );
}

Level::Level( const int nWidth, const int nHeight ) : WIDTH( nWidth ), HEIGHT( nHeight )
{
    fillProbability = 40;
    r1Cutoff = 5;
    r2Cutoff = 0;
    passes = 12;

    // Allocate memory for map
    map = new Tile *[HEIGHT];

    for ( UInt i = 0; i < HEIGHT; i++ )
    {
        map[ i ] = new Tile[WIDTH];
    }

    this->GenerateLevel( );
}

Level::~Level( )
{
    for ( UInt i = 0; i < HEIGHT; i++ )
    {
        delete[] map[ i ];
    }

    delete[] map;
}

int Level::randpick( )
{
    if ( rand( ) % 100 < fillProbability )
    { return MAP_WALL; }
    return MAP_FLOOR;
}

void floodmap( Tile **&map, Tile **&flag, UInt x, UInt y )
{
    // do nothing if this cell is a wall
    if ( map[ y ][ x ].type == MAP_WALL )
    { return; }

    // do nothing if we have already flagged this cell
    if ( flag[ y ][ x ].type == MAP_FLOOR )
    { return; }

    // flag this cell as floor
    flag[ y ][ x ] = tiles[ MAP_FLOOR ];

    // call recursively in all directions
    floodmap( map, flag, x - 1, y );
    floodmap( map, flag, x + 1, y );
    floodmap( map, flag, x, y - 1 );
    floodmap( map, flag, x, y + 1 );
}

void Level::GenerateLevel( )
{

    // allocate memory for levels
    Tile **new_map = new Tile *[HEIGHT];
    Tile **flooded_map = new Tile *[HEIGHT];
    for ( UInt i = 0; i < HEIGHT; i++ )
    {
        new_map[ i ] = new Tile[WIDTH];
        flooded_map[ i ] = new Tile[WIDTH];
    }

    while ( 1 )
    {
        // randomly fill starting level
        for ( UInt y = 1; y < HEIGHT - 1; y++ )
        {
            for ( UInt x = 1; x < WIDTH; x++ )
            {
                map[ y ][ x ] = tiles[ randpick( ) ];
            }
        }

        // fill temp level with walls
        for ( UInt y = 0; y < HEIGHT; y++ )
        {
            for ( UInt x = 0; x < WIDTH; x++ )
            {
                new_map[ y ][ x ] = tiles[ MAP_WALL ];
            }
        }

        // ensure the level has outer walls
        for ( UInt y = 0; y < HEIGHT; y++ )
        {
            map[ y ][ 0 ] = map[ y ][ WIDTH - 1 ] = tiles[ MAP_WALL ];
        }
        for ( UInt x = 0; x < WIDTH; x++ )
        {
            map[ 0 ][ x ] = map[ HEIGHT - 1 ][ x ] = tiles[ MAP_WALL ];
        }

        // run cellular autonoma algorithm
        for ( UInt y = 1; y < HEIGHT - 1; y++ )
        {
            for ( UInt x = 1; x < WIDTH - 1; x++ )
            {
                int adjcount_r1 = 0,
                        adjcount_r2 = 0;

                for ( int i = -1; i <= 1; i++ )
                {
                    for ( int j = -1; j <= 1; j++ )
                    {
                        if ( map[ y + i ][ x + j ].type != MAP_FLOOR )
                        { adjcount_r1++; }
                    }
                }

                for ( UInt i = y - 2; i <= y + 2; i++ )
                {
                    for ( UInt j = x - 2; j <= x + 2; j++ )
                    {
                        if ( abs( i - y ) == 2 && abs( j - x ) == 2 )
                        { continue; }
                        if ( i >= HEIGHT || j >= WIDTH )
                        { continue; }
                        if ( map[ i ][ j ].type != MAP_FLOOR )
                        { adjcount_r2++; }
                    }
                }

                // select new tile for this position
                if ( adjcount_r1 >= r1Cutoff || adjcount_r2 <= r2Cutoff )
                {
                    new_map[ y ][ x ] = tiles[ MAP_WALL ];
                }
                else
                {
                    new_map[ y ][ x ] = tiles[ MAP_FLOOR ];
                }
            }
        }

        // flood map from random floor cell
        int rnd_x, rnd_y;
        while ( 1 )
        {
            rnd_x = rand( ) % WIDTH;
            rnd_y = rand( ) % HEIGHT;

            if ( new_map[ rnd_y ][ rnd_x ].type == MAP_FLOOR )
            { break; }
        }

        for ( UInt y = 0; y < HEIGHT; y++ )
        {
            for ( UInt x = 0; x < WIDTH; x++ )
            {
                flooded_map[ y ][ x ] = tiles[ MAP_WALL ];
            }
        }

        floodmap( new_map, flooded_map, rnd_x, rnd_y );

        // ensure that at least 1/2 of the map is floor
        UInt floorcount = 0;
        for ( UInt y = 0; y < HEIGHT; y++ )
        {
            for ( UInt x = 0; x < WIDTH; x++ )
            {
                if ( flooded_map[ y ][ x ].type == MAP_FLOOR )
                { floorcount++; }
            }
        }

        if ( floorcount > ( WIDTH * HEIGHT ) / 2 )
        { break; }
    }

    // place stairs
    int rnd_x, rnd_y;
    while ( 1 )
    {
        rnd_x = rand( ) % WIDTH;
        rnd_y = rand( ) % HEIGHT;

        if ( flooded_map[ rnd_y ][ rnd_x ].type == MAP_FLOOR )
        {
            flooded_map[ rnd_y ][ rnd_x ] = tiles[ MAP_STAIR_DOWN ];
            stairDown.x = rnd_x;
            stairDown.y = rnd_y;
            break;
        }
    }
    while ( 1 )
    {
        rnd_x = rand( ) % WIDTH;
        rnd_y = rand( ) % HEIGHT;

        if ( flooded_map[ rnd_y ][ rnd_x ].type == MAP_FLOOR )
        {
            flooded_map[ rnd_y ][ rnd_x ] = tiles[ MAP_STAIR_UP ];
            stairUp.x = rnd_x;
            stairUp.y = rnd_y;
            break;
        }
    }

    // replace map with new one
    for ( UInt y = 1; y < HEIGHT - 1; y++ )
    {
        for ( UInt x = 1; x < WIDTH - 1; x++ )
        {
            map[ y ][ x ] = flooded_map[ y ][ x ];
        }
    }

    // free memory used up by temporary maps
    for ( UInt i = 0; i < HEIGHT; i++ )
    {
        delete[] new_map[ i ];
        delete[] flooded_map[ i ];
    }
    delete[] new_map;
    delete[] flooded_map;

    // scatter items around level
    for ( UInt i = 0; i < HEIGHT / 2; i++ )
    {
        Die tmp = { 1, HEIGHT - 1, 0 };
        UInt y = DieRoll::Roll( tmp );
        tmp.Set( 1, WIDTH - 1, 0 );
        UInt x = DieRoll::Roll( tmp );

        if ( map[ y ][ x ].type == MAP_FLOOR )
        { map[ y ][ x ].items.push_back( Item::Generate( )); }
    }
}

bool Level::HasItem( Vector2D coordinate ) const
{
    return !map[ coordinate.y ][ coordinate.x ].items.empty( );
}

item_ptr Level::SeeItem( Vector2D coordinate ) const
{
    return map[ coordinate.y ][ coordinate.x ].items.back( );
}

item_ptr Level::GetItem( Vector2D coordinate )
{
    item_ptr tmp = map[ coordinate.y ][ coordinate.x ].items.back( );
    map[ coordinate.y ][ coordinate.x ].items.pop_back( );
    return tmp;
}

void Level::PutItem( Vector2D pos, item_ptr item )
{
    map[ pos.y ][ pos.x ].items.push_back( item );
}