#include <Include/Application.hpp>
#include "Screen/Include/PlayScreen.hpp"

PlayScreen::PlayScreen( )
{
    level = 0;
    character.Pos( valkyria.StairUp( ));
}

PlayScreen::~PlayScreen( ) = default;

PlayScreen &PlayScreen::GetInstance( )
{
    static PlayScreen instance;
    return instance;
}

void PlayScreen::Draw( )
{
    clear( );

    /* LEVEL DRAWING */
    renderer.DrawMap( valkyria, character );

    /* STATUS DRAWING */
    renderer.DrawStats( character, level );

    /* print items on ground, if any */
    if ( valkyria.HasItem( character.GetCoordinate( )))
    {
        std::string msg = "Item here: " + valkyria.SeeItem( character.GetCoordinate( ))->Name( );
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
        case 'q':

            Application::GetInstance( ).OnExit( );

            break;

            /* MOVEMENT KEYS */
        case 'k':
        case '8':

            if ( valkyria.Map( )[ character.GetCoordinateY( ) - 1 ][ character.GetCoordinateX( ) ].passable )
            {
                character.WalkAt( NORTH );
            }

            break;

        case 'j':
        case '2':

            if ( valkyria.Map( )[ character.GetCoordinateY( ) + 1 ][ character.GetCoordinateX( ) ].passable )
            {
                character.WalkAt( SOUTH );
            }

            break;

        case 'h':
        case '4':

            if ( valkyria.Map( )[ character.GetCoordinateY( ) ][ character.GetCoordinateX( ) - 1 ].passable )
            {
                character.WalkAt( WEST );
            }

            break;

        case 'l':
        case '6':

            if ( valkyria.Map( )[ character.GetCoordinateY( ) ][ character.GetCoordinateX( ) + 1 ].passable )
            {
                character.WalkAt( EAST );
            }

            break;

        case 'u':
        case '7':

            if ( valkyria.Map( )[ character.GetCoordinateY( ) - 1 ][ character.GetCoordinateX( ) -
                    1 ].passable )
            {
                character.WalkAt( NORTH_WEST );
            }

            break;

        case 'i':
        case '9':

            if ( valkyria.Map( )[ character.GetCoordinateY( ) - 1 ][ character.GetCoordinateX( ) +
                    1 ].passable )
            {
                character.WalkAt( NORTH_EAST );
            }

            break;

        case 'n':
        case '1':

            if ( valkyria.Map( )[ character.GetCoordinateY( ) + 1 ][ character.GetCoordinateX( ) -
                    1 ].passable )
            {
                character.WalkAt( SOUTH_WEST );
            }

            break;

        case 'm':
        case '3':

            if ( valkyria.Map( )[ character.GetCoordinateY( ) + 1 ][ character.GetCoordinateX( ) +
                    1 ].passable )
            {
                character.WalkAt( SOUTH_EAST );
            }

            break;

            /* LEVEL TRAVERSAL */
//        case '>':
//            if ( character.GetCoordinate( ) == valkyria.StairDown( ))
//            {
//                if ( dungeon.size( ) == ++level )
//                {
//                    dungeon.push_back( Level ( LEVEL_WIDTH, LEVEL_HEIGHT ) );
//                }
//                character.Pos( valkyria.StairUp( ));
//            }
//            break;
//
//        case '<':
//            if ( character.GetCoordinate( ) == valkyria.StairUp( ))
//            {
//                if ( level == 0 )
//                { }
//                else
//                { level--; }
//                character.Pos( valkyria.StairDown( ));
//            }
//            break;

            /* ITEM MANAGEMENT */
        case ',':
            if ( valkyria.HasItem( character.GetCoordinate( )))
            {
                inventory.push_back( valkyria.GetItem( character.GetCoordinate( )));
                std::string msg = "Picked up " + inventory.back( )->Name( );
                renderer.Message( msg );
            }
            break;

            /* DEBUG KEYS */
//        case 'r':
//            for ( Level &level: dungeon )
//            { level.GenerateLevel( ); }
//            break;

        default:

            break;
    }
}

