#include "Matrix/Include/RealWorld.hpp"

// Constructs

RealWorld::RealWorld( ) : WIDTH( 80 ), HEIGHT( 25 )
{
    world = new Tile[WIDTH * HEIGHT]( );
}

RealWorld::RealWorld( const unsigned int nWIDTH, const unsigned int nHEIGHT ) :
        WIDTH( nWIDTH ), HEIGHT( nHEIGHT )
{
    world = new Tile[WIDTH * HEIGHT]( );
}

// Destructs

RealWorld::~RealWorld( )
{
    delete[] world;
}

// Methods Private

bool RealWorld::IsValidTileCoordinateAt( const Vector2D &coordinate ) const
{
    return !( coordinate.x < 0 || coordinate.x >= WIDTH ||
              coordinate.y < 0 || coordinate.y >= HEIGHT );

}

bool RealWorld::IsEdgeTileCoordinateAt( const Vector2D &coordinate ) const
{
    return coordinate.x == 0 || coordinate.x == WIDTH - 1 ||
           coordinate.y == 0 || coordinate.y == HEIGHT - 1;

}

Vector2D RealWorld::GetCoordinateOfRandomTileTypeFloor( ) const
{
    unsigned int coordinateX = 0;
    unsigned int coordinateY = 0;

    while ( true )
    {
        coordinateX = rand( ) % WIDTH;
        coordinateY = rand( ) % HEIGHT;

        if ( world[ GetIndex( coordinateX, coordinateY ) ].type == TYPE_TILE_FLOOR )
        {
            return Vector2D( coordinateX, coordinateY );
        }
    }
}

// Methods Public

bool RealWorld::HasItemsTileAt( Vector2D &coordinate ) const
{
    return !world[ GetIndex( coordinate ) ].items.empty( );
}

unsigned int RealWorld::GetIndex( const unsigned int x, const unsigned int y ) const
{
    return x + WIDTH * y;
}

unsigned int RealWorld::GetIndex( Vector2D &coordinate ) const
{
    return coordinate.x + WIDTH * coordinate.y;
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

Vector2D &RealWorld::GetCoordinateStairDown( )
{
    return coordinateStairDown;
}

Vector2D &RealWorld::GetCoordinateStairUp( )
{
    return coordinateStairUp;
}

ItemPointer RealWorld::GetItemAt( Vector2D &coordinate ) const
{
    ItemPointer item = SeeItemAt( coordinate );

    world[ GetIndex( coordinate ) ].items.pop_back( );

    return item;
}

ItemPointer RealWorld::SeeItemAt( Vector2D &coordinate ) const
{
    return world[ GetIndex( coordinate ) ].items.back( );
}

void RealWorld::AddItemAt( Vector2D &coordinate, ItemPointer &item ) const
{
    world[ GetIndex( coordinate ) ].items.push_back( item );
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

void RealWorld::FillWorldWithTileTypeWall( ) const
{
    for ( unsigned int i = 0; i < WIDTH * HEIGHT; i++ )
    {
        world[ i ] = Tile( TYPE_TILE_WALL, false, true );
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

void RealWorld::RunDrunkardWalkAlgorithm( ) const
{
    // Coordinate at Center of World
    Vector2D startCoordinate = Vector2D( WIDTH / 2, HEIGHT / 2 );

    world[ GetIndex( startCoordinate ) ] = Tile( TYPE_TILE_FLOOR, true, false );

    unsigned int currentFloorCount = 1;

    Vector2D currentCoordinate = Vector2D( startCoordinate );

    while ( currentFloorCount < MAX_FLOOR_COUNT )
    {
        // Generate a number random between 1 and 4
        unsigned int direction = rand( ) % 4 + 1;

        Vector2D newCoordinate;

        // Up
        if ( direction == 1 )
        {
            newCoordinate = Vector2D( currentCoordinate.x, currentCoordinate.y - 1 );
        }
            // Down
        else if ( direction == 2 )
        {
            newCoordinate = Vector2D( currentCoordinate.x, currentCoordinate.y + 1 );
        }
            // Left
        else if ( direction == 3 )
        {
            newCoordinate = Vector2D( currentCoordinate.x - 1, currentCoordinate.y );
        }
            // Right
        else if ( direction == 4 )
        {
            newCoordinate = Vector2D( currentCoordinate.x + 1, currentCoordinate.y );
        }

        if ( IsValidTileCoordinateAt( newCoordinate ) &&
             !IsEdgeTileCoordinateAt( newCoordinate ))
        {
            currentCoordinate = newCoordinate;
            world[ GetIndex( currentCoordinate ) ] = Tile( TYPE_TILE_FLOOR, true, false );
            currentFloorCount += 1;
        }
    }
}

void RealWorld::PlaceStairs( )
{
    // Stair Down
    Vector2D newStairDown = GetCoordinateOfRandomTileTypeFloor( );

    coordinateStairDown = Vector2D( newStairDown );

    world[ GetIndex( newStairDown ) ] = Tile( TYPE_TILE_STAIR_DOWN, true, false );

    // Stair Up
    Vector2D newStairUp = GetCoordinateOfRandomTileTypeFloor( );

    coordinateStairUp = Vector2D( newStairUp );

    world[ GetIndex( newStairUp ) ] = Tile( TYPE_TILE_STAIR_UP, true, false );
}

void RealWorld::PlaceItemsRandomAroundWorld( ) const
{
    for ( unsigned int i = 0; i < WIDTH / 2; i++ )
    {
        Vector2D newItem = GetCoordinateOfRandomTileTypeFloor( );

        world[ GetIndex( newItem ) ].items.push_back( Item::Generate( ));
    }
}
