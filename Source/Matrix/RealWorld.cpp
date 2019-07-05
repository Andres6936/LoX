#include "Matrix/Include/RealWorld.hpp"

RealWorld::RealWorld( ) : WIDTH( 80 ), HEIGHT( 25 )
{
    world = new Tile[WIDTH * HEIGHT]( );
}

RealWorld::RealWorld( const unsigned int nWIDTH, const unsigned int nHEIGHT ) :
        WIDTH( nWIDTH ), HEIGHT( nHEIGHT )
{
    world = new Tile[WIDTH * HEIGHT]( );
}

RealWorld::~RealWorld( )
{
    delete[] world;
}

unsigned int RealWorld::GetIndex( const unsigned int x, const unsigned int y ) const
{
    return x + WIDTH * y;
}

Tile &RealWorld::GetTileIndexAt( const unsigned int x, const unsigned int y )
{
    return world[ GetIndex( x, y ) ];
}

Tile RealWorld::GetRandomTile( ) const
{
    if ( rand( ) % 100 < FILL_PROBABILITY )
    {
        return Tile( TYPE_TILE_WALL, false, true );
    }
    else
    {
        return Tile( TYPE_TILE_FLOOR, true, false );
    }
}

void RealWorld::FillWorldWithRandomTiles( ) const
{
    for ( unsigned int i = 0; i < WIDTH * HEIGHT; i++ )
    {
        world[ i ] = GetRandomTile( );
    }
}

void RealWorld::FillWorldWithOuterWalls( ) const
{
    for ( unsigned int i = 0; i < WIDTH; i++ )
    {
        world[ GetIndex( i, 0 ) ] = Tile( TYPE_TILE_WALL, false, true );
        world[ GetIndex( i, HEIGHT - 1 ) ] = Tile( TYPE_TILE_WALL, false, true );
    }

    for ( unsigned int j = 0; j < HEIGHT; j++ )
    {
        world[ GetIndex( 0, j ) ] = Tile( TYPE_TILE_WALL, false, true );
        world[ GetIndex( WIDTH - 1, j ) ] = Tile( TYPE_TILE_WALL, false, true );
    }
}

void RealWorld::RunCellularAutomata( ) const
{
    for ( unsigned int x = 1; x < WIDTH - 1; x++ )
    {
        for ( unsigned int y = 1; y < HEIGHT - 1; y++ )
        {
            unsigned int adjCountR1 = 0;

            for ( int i = -1; i <= 1; i++ )
            {
                for ( int j = -1; j <= 1; j++ )
                {
                    if ( world[ GetIndex( x + j, y + i ) ].type != TYPE_TILE_FLOOR )
                    {
                        adjCountR1 += 1;
                    }
                }
            }

            unsigned int adjCountR2 = 0;

            for ( int i = y - 2; i <= y + 2; i++ )
            {
                for ( int j = x - 2; j <= x + 2; j++ )
                {
                    if (( i - y ) == 2 && ( j - x ) == 2 )
                    {
                        continue;
                    }

                    if ( i >= HEIGHT || j >= WIDTH )
                    {
                        continue;
                    }

                    if ( world[ GetIndex( j, i ) ].type != TYPE_TILE_FLOOR )
                    {
                        adjCountR2 += 1;
                    }
                }
            }

            // Select new tile for this position.
            if ( adjCountR1 >= R1_CUT_OFF || adjCountR2 <= R2_CUT_OFF )
            {
                world[ GetIndex( x, y ) ] = Tile( TYPE_TILE_WALL, false, true );
            }
            else
            {
                world[ GetIndex( x, y ) ] = Tile( TYPE_TILE_FLOOR, true, false );
            }
        }
    }
}
