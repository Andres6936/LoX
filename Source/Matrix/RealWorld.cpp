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
