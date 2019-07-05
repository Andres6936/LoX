#include "Screen/Include/MenuScreen.hpp"

MenuScreen::MenuScreen( ) = default;

MenuScreen &MenuScreen::GetInstance( )
{
    static MenuScreen instance;
    return instance;
}

void MenuScreen::Draw( )
{
    // Clear Screen.
    terminal_clear( );

    // Game Title
    std::string str = "Lair of Xyrallion";

    UChar x = ( 80 / 2 ) - ( floor( str.length( ) / 2 ));
    UChar y = ( 25 / 3 );

    renderer.Write( str, x, y );

    /* new game option */
    str = "Start Game";
    x = ( 80 / 2 ) - ( str.length( ) / 2 );
    y += 2;

    if ( itemMenu == MENU_PLAY_GAME )
    {
        renderer.Write( str, x, y, COL_RED, "red" );
    }
    else
    {
        renderer.Write( str, x, y );
    }

    /* exit game option */
    str = "Quit";
    x = ( 80 / 2 ) - ( str.length( ) / 2 );
    if ( itemMenu == MENU_EXIT_GAME )
    {
        renderer.Write( str, x, ++y, COL_RED, "red" );
    }
    else
    {
        renderer.Write( str, x, ++y );
    }

    str = "In memory of Princesa (My beloved pet)";
    x = ( 80 / 2 ) - ( str.length( ) / 2 );
    renderer.Write( str, x, 25 - 6 );

    str = "July 2, 2019";
    x = ( 80 / 2 ) - ( str.length( ) / 2 );
    renderer.Write( str, x, 25 - 5 );

    /* game version */
    str = "Development Version ";
    str += _LoX_VERSION;
    renderer.Write( str, 0, 25 - 2 );

    /* refresh window */
    terminal_refresh( );
}

void MenuScreen::Update( )
{
    switch ( renderer.GetKey( ))
    {
        // ---- Menu Traversal ----

        case TK_UP:

            if ( itemMenu == MENU_PLAY_GAME )
            {
                // We do nothing.
            }
            else if ( itemMenu == MENU_EXIT_GAME )
            {
                itemMenu = MENU_PLAY_GAME;
            }

            break;

        case TK_DOWN:

            if ( itemMenu == MENU_PLAY_GAME )
            {
                itemMenu = MENU_EXIT_GAME;
            }

            break;

        case TK_ENTER:

            if ( itemMenu == MENU_PLAY_GAME )
            {
                Application::GetInstance( ).SetScreen( PlayScreen::GetInstance( ));
            }
            else if ( itemMenu == MENU_EXIT_GAME )
            {
                Application::GetInstance( ).OnExit( );
            }

            break;

        default:

            break;
    }
}

