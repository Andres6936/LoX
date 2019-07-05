#include "Matrix/Include/TheMatrix.hpp"
#include "Include/Character.hpp"
#include "Include/DieRoll.hpp"

TheMatrix::TheMatrix( ) : WIDTH( 80 ), HEIGHT( 25 )
{
    fillProbability = 40;
    r1Cutoff = 5;
    r2Cutoff = 0;
    passes = 12;

    realWorld = new RealWorld( WIDTH, HEIGHT );

    // Generate level
    this->GenerateLevel( );
}

TheMatrix::TheMatrix( const int nWidth, const int nHeight ) : WIDTH( nWidth ), HEIGHT( nHeight )
{
    fillProbability = 40;
    r1Cutoff = 5;
    r2Cutoff = 0;
    passes = 12;

    realWorld = new RealWorld( WIDTH, HEIGHT );

    this->GenerateLevel( );
}

TheMatrix::~TheMatrix( )
{
    delete realWorld;
}

void TheMatrix::GenerateLevel( )
{
    // --------------------------------

    // First Version With Cellular Automata

    // Randomly fill starting level.
    //realWorld->FillWorldWithRandomTiles( );

    // Ensure the level has outer walls.
    //realWorld->FillWorldWithOuterWalls( );

    // Run cellular automata algorithm.
    //realWorld->RunCellularAutomata( );

    // End Version With Cellular Automata

    // --------------------------------

    // First Version With Drunkard Walk Algorithm

    realWorld->FillWorldWithTileTypeWall( );

    realWorld->RunDrunkardWalkAlgorithm( );

    // End Version With Drunkard Walk Algorithm

    // --------------------------------

    realWorld->PlaceStairs( );

    realWorld->PlaceItemsRandomAroundWorld( );
}

Tile &TheMatrix::GetTileAtIndex( const unsigned int x, const unsigned int y )
{
    realWorld->GetTileIndexAt( x, y );
}

Vector2D &TheMatrix::GetCoordinateStairDown( )
{
    return realWorld->GetCoordinateStairDown( );
}

Vector2D &TheMatrix::GetCoordinateStairUp( )
{
    return realWorld->GetCoordinateStairUp( );
}

bool TheMatrix::HasItemsTileWithPosition( Vector2D &coordinate ) const
{
    return realWorld->HasItemsTileAt( coordinate );
}

ItemPointer TheMatrix::SeeItemAt( Vector2D &coordinate ) const
{
    return realWorld->SeeItemAt( coordinate );
}

ItemPointer TheMatrix::GetItemAt( Vector2D &coordinate ) const
{
    return realWorld->GetItemAt( coordinate );
}

void TheMatrix::AddItemAt( Vector2D &coordinate, ItemPointer &item ) const
{
    realWorld->AddItemAt( coordinate, item );
}
