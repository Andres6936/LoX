#include "Screen/Include/PlayScreen.hpp"

PlayScreen::PlayScreen( ) :
        character( "Player" )
{
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
    clear();

    /* LEVEL DRAWING */
    renderer.DrawMap( dungeon[ level ], character );

    /* STATUS DRAWING */
    renderer.DrawStats( character, level );

    /* print items on ground, if any */
    if ( dungeon[ level ].HasItem( character.Pos( )))
    {
        std::string msg = "Item here: " + dungeon[ level ].SeeItem( character.Pos( ))->Name( );
        renderer.Message( msg );
    }

    /* always move cursor back to player when finished drawing */
    move( character.Y( ), character.X( ));
}

void PlayScreen::Update( )
{
    /* KEY INPUT */
    switch ( renderer.GetKey( ))
    {
        /* QUIT GAME */
        case 'q':;
            break;

            /* MOVEMENT KEYS */
        case 'k':
        case '8':
            if ( dungeon[ level ].Map( )[ character.Y( ) - 1 ][ character.X( ) ].passable )
            { character.AddPos( 0, -1 ); }
            break;

        case 'j':
        case '2':
            if ( dungeon[ level ].Map( )[ character.Y( ) + 1 ][ character.X( ) ].passable )
            { character.AddPos( 0, 1 ); }
            break;

        case 'h':
        case '4':
            if ( dungeon[ level ].Map( )[ character.Y( ) ][ character.X( ) - 1 ].passable )
            { character.AddPos( -1, 0 ); }
            break;

        case 'l':
        case '6':
            if ( dungeon[ level ].Map( )[ character.Y( ) ][ character.X( ) + 1 ].passable )
            { character.AddPos( 1, 0 ); }
            break;

        case 'u':
        case '7':
            if ( dungeon[ level ].Map( )[ character.Y( ) - 1 ][ character.X( ) - 1 ].passable )
            { character.AddPos( -1, -1 ); }
            break;

        case 'i':
        case '9':
            if ( dungeon[ level ].Map( )[ character.Y( ) - 1 ][ character.X( ) + 1 ].passable )
            { character.AddPos( 1, -1 ); }
            break;

        case 'n':
        case '1':
            if ( dungeon[ level ].Map( )[ character.Y( ) + 1 ][ character.X( ) - 1 ].passable )
            { character.AddPos( -1, 1 ); }
            break;

        case 'm':
        case '3':
            if ( dungeon[ level ].Map( )[ character.Y( ) + 1 ][ character.X( ) + 1 ].passable )
            { character.AddPos( 1, 1 ); }
            break;

            /* LEVEL TRAVERSAL */
        case '>':
            if ( character.Pos( ) == dungeon[ level ].StairDown( ))
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
            if ( character.Pos( ) == dungeon[ level ].StairUp( ))
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
            if ( dungeon[ level ].HasItem( character.Pos( )))
            {
                inventory.push_back( dungeon[ level ].GetItem( character.Pos( )));
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

void PlayScreen::OnEntry( )
{
    Draw();
    Update();
}

void PlayScreen::OnExit( )
{

}

void PlayScreen::NextScreen( )
{

}
