#include "Screen/Include/PlayScreen.hpp"

PlayScreen::PlayScreen( )
{
    character = Character( "Slash" );
    Level tmp( LEVEL_WIDTH, LEVEL_HEIGHT );
    dungeon.push_back( tmp );
    level = 0;
    character.Pos( dungeon[ level ].StairUp( ));
}

PlayScreen::~PlayScreen( )
{
    dungeon.clear( );
}

PlayScreen &PlayScreen::GetInstance( )
{
    static PlayScreen instance;
    return instance;
}

void PlayScreen::Draw( )
{
    clear( );

    /* LEVEL DRAWING */
    renderer.DrawMap( dungeon[ level ], character );

    /* STATUS DRAWING */
    renderer.DrawStats( character, level );

    /* print items on ground, if any */
    if ( dungeon[ level ].HasItem( character.GetCoordinate( )))
    {
        std::string msg = "Item here: " + dungeon[ level ].SeeItem( character.GetCoordinate( ))->Name( );
        renderer.Message( msg );
    }

    /* always move cursor back to player when finished drawing */
    move( character.GetCoordinateY( ), character.GetCoordinateX( ));
}

void PlayScreen::Update( )
{
    switch ( renderer.GetKey( ))
    {
        /* QUIT GAME */
        case 'q':;
            break;

            /* MOVEMENT KEYS */
        case 'k':
        case '8':

            if ( dungeon[ level ].Map( )[ character.GetCoordinateY( ) - 1 ][ character.GetCoordinateX( ) ].passable )
            {
                character.WalkAt( NORTH );
            }

            break;

        case 'j':
        case '2':

            if ( dungeon[ level ].Map( )[ character.GetCoordinateY( ) + 1 ][ character.GetCoordinateX( ) ].passable )
            {
                character.WalkAt( SOUTH );
            }

            break;

        case 'h':
        case '4':

            if ( dungeon[ level ].Map( )[ character.GetCoordinateY( ) ][ character.GetCoordinateX( ) - 1 ].passable )
            {
                character.WalkAt( WEST );
            }

            break;

        case 'l':
        case '6':

            if ( dungeon[ level ].Map( )[ character.GetCoordinateY( ) ][ character.GetCoordinateX( ) + 1 ].passable )
            {
                character.WalkAt( EAST );
            }

            break;

        case 'u':
        case '7':

            if ( dungeon[ level ].Map( )[ character.GetCoordinateY( ) - 1 ][ character.GetCoordinateX( ) -
                                                                             1 ].passable )
            {
                character.WalkAt( NORTH_WEST );
            }

            break;

        case 'i':
        case '9':

            if ( dungeon[ level ].Map( )[ character.GetCoordinateY( ) - 1 ][ character.GetCoordinateX( ) +
                                                                             1 ].passable )
            {
                character.WalkAt( NORTH_EAST );
            }

            break;

        case 'n':
        case '1':

            if ( dungeon[ level ].Map( )[ character.GetCoordinateY( ) + 1 ][ character.GetCoordinateX( ) -
                                                                             1 ].passable )
            {
                character.WalkAt( SOUTH_WEST );
            }

            break;

        case 'm':
        case '3':

            if ( dungeon[ level ].Map( )[ character.GetCoordinateY( ) + 1 ][ character.GetCoordinateX( ) +
                                                                             1 ].passable )
            {
                character.WalkAt( SOUTH_EAST );
            }

            break;

            /* LEVEL TRAVERSAL */
        case '>':
            if ( character.GetCoordinate( ) == dungeon[ level ].StairDown( ))
            {
                if ( dungeon.size( ) == ++level )
                {
                    Level tmp( LEVEL_WIDTH, LEVEL_HEIGHT );
                    dungeon.push_back( tmp );
                }
                character.Pos( dungeon[ level ].StairUp( ));
            }
            break;

        case '<':
            if ( character.GetCoordinate( ) == dungeon[ level ].StairUp( ))
            {
                if ( level == 0 )
                { }
                else
                { level--; }
                character.Pos( dungeon[ level ].StairDown( ));
            }
            break;

            /* ITEM MANAGEMENT */
        case ',':
            if ( dungeon[ level ].HasItem( character.GetCoordinate( )))
            {
                inventory.push_back( dungeon[ level ].GetItem( character.GetCoordinate( )));
                std::string msg = "Picked up " + inventory.back( )->Name( );
                renderer.Message( msg );
            }
            break;

            /* DEBUG KEYS */
        case 'r':
            for ( Level &level: dungeon )
            { level.Generate( ); }
            break;

        default:

            break;
    }
}

