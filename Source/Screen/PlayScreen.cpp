#include <Include/Application.hpp>
#include "Screen/Include/PlayScreen.hpp"

PlayScreen::PlayScreen( )
{
    level = 0;
    character.Pos( theMatrix.StairUp( ));
}

PlayScreen::~PlayScreen( ) = default;

PlayScreen &PlayScreen::GetInstance( )
{
    static PlayScreen instance;
    return instance;
}

void PlayScreen::Draw( )
{
    terminal_clear( );

    /* LEVEL DRAWING */
    renderer.DrawMap( theMatrix, character );

    /* STATUS DRAWING */
    renderer.DrawStats( character, level );

    /* print items on ground, if any */
    if ( theMatrix.HasItem( character.GetCoordinate( )))
    {
        std::string msg = "Item here: " + theMatrix.SeeItem( character.GetCoordinate( ))->Name( );
        renderer.Message( msg );
    }

    terminal_refresh( );
}

void PlayScreen::Update( )
{
    switch ( renderer.GetKey( ))
    {
        /* QUIT GAME */
        case TK_CLOSE:
        case TK_Q:

            Application::GetInstance( ).OnExit( );

            break;

            /* MOVEMENT KEYS */
        case TK_UP:
        case TK_KP_8:

            if ( theMatrix.Map( )[ character.GetCoordinateY( ) - 1 ][ character.GetCoordinateX( ) ].passable )
            {
                character.WalkAt( NORTH );
            }

            break;

        case TK_DOWN:
        case TK_KP_2:

            if ( theMatrix.Map( )[ character.GetCoordinateY( ) + 1 ][ character.GetCoordinateX( ) ].passable )
            {
                character.WalkAt( SOUTH );
            }

            break;

        case TK_LEFT:
        case TK_KP_4:

            if ( theMatrix.Map( )[ character.GetCoordinateY( ) ][ character.GetCoordinateX( ) - 1 ].passable )
            {
                character.WalkAt( WEST );
            }

            break;

        case TK_RIGHT:
        case TK_KP_6:

            if ( theMatrix.Map( )[ character.GetCoordinateY( ) ][ character.GetCoordinateX( ) + 1 ].passable )
            {
                character.WalkAt( EAST );
            }

            break;

        case TK_KP_7:

            if ( theMatrix.Map( )[ character.GetCoordinateY( ) - 1 ][ character.GetCoordinateX( ) -
                                                                      1 ].passable )
            {
                character.WalkAt( NORTH_WEST );
            }

            break;

        case TK_KP_9:

            if ( theMatrix.Map( )[ character.GetCoordinateY( ) - 1 ][ character.GetCoordinateX( ) +
                                                                      1 ].passable )
            {
                character.WalkAt( NORTH_EAST );
            }

            break;

        case TK_KP_1:

            if ( theMatrix.Map( )[ character.GetCoordinateY( ) + 1 ][ character.GetCoordinateX( ) -
                                                                      1 ].passable )
            {
                character.WalkAt( SOUTH_WEST );
            }

            break;

        case TK_KP_3:

            if ( theMatrix.Map( )[ character.GetCoordinateY( ) + 1 ][ character.GetCoordinateX( ) +
                                                                      1 ].passable )
            {
                character.WalkAt( SOUTH_EAST );
            }

            break;

            /* LEVEL TRAVERSAL */
//        case '>':
//            if ( character.GetCoordinate( ) == theMatrix.StairDown( ))
//            {
//                if ( dungeon.size( ) == ++level )
//                {
//                    dungeon.push_back( TheMatrix ( LEVEL_WIDTH, LEVEL_HEIGHT ) );
//                }
//                character.Pos( theMatrix.StairUp( ));
//            }
//            break;
//
//        case '<':
//            if ( character.GetCoordinate( ) == theMatrix.StairUp( ))
//            {
//                if ( level == 0 )
//                { }
//                else
//                { level--; }
//                character.Pos( theMatrix.StairDown( ));
//            }
//            break;

            /* ITEM MANAGEMENT */
        case TK_COMMA:
            if ( theMatrix.HasItem( character.GetCoordinate( )))
            {
                inventory.push_back( theMatrix.GetItem( character.GetCoordinate( )));
                std::string msg = "Picked up " + inventory.back( )->Name( );
                renderer.Message( msg );
            }
            break;

            /* DEBUG KEYS */
//        case 'r':
//            for ( TheMatrix &level: dungeon )
//            { level.GenerateLevel( ); }
//            break;

        default:

            break;
    }
}

