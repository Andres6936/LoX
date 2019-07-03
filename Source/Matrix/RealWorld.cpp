#include "Matrix/Include/RealWorld.hpp"

RealWorld::RealWorld( ) : WIDTH( 80 ), HEIGHT( 24 )
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

unsigned int RealWorld::GetIndex( const unsigned int x, const unsigned int y )
{
    return x + WIDTH * y;
}
