#include "Screen/Include/MenuScreen.hpp"

MenuScreen::MenuScreen( ) = default;

MenuScreen &MenuScreen::GetInstance( )
{
    static MenuScreen instance;
    return instance;
}

void MenuScreen::Draw( )
{
    /* clear screen first */
    clear( );

    /* game title */
    std::string str = "Lair of Xyrallion";
    UChar x = ( COLS / 2 ) - ( floor( str.length( ) / 2 ));
    UChar y = ( LINES / 2 ) - (( MENU_EXIT_GAME + 3 ) / 2 );
    renderer.Write( str, x, ++y );

    /* new game option */
    str = "Start Game";
    x = ( COLS / 2 ) - ( str.length( ) / 2 );
    y += 2;
    if ( itemMenu == MENU_PLAY_GAME )
    { renderer.Write( str, x, y, COL_RED ); }
    else
    { renderer.Write( str, x, y ); }

    /* exit game option */
    str = "Quit";
    x = ( COLS / 2 ) - ( str.length( ) / 2 );
    if ( itemMenu == MENU_EXIT_GAME )
    { renderer.Write( str, x, ++y, COL_RED ); }
    else
    { renderer.Write( str, x, ++y ); }

    /* game version */
    str = "Development Version ";
    str += _LoX_VERSION;
    renderer.Write( str, 0, LINES - 1 );

    /* refresh window */
    refresh( );
}

void MenuScreen::Update( )
{
    switch ( renderer.GetKey( ))
    {
        // ---- Menu Traversal ----

        case KEY_UP:

            if ( itemMenu == MENU_PLAY_GAME )
            {
                // We do nothing.
            }
            else if ( itemMenu == MENU_EXIT_GAME )
            {
                itemMenu = MENU_PLAY_GAME;
            }

            break;

        case KEY_DOWN:

            if ( itemMenu == MENU_PLAY_GAME )
            {
                itemMenu = MENU_EXIT_GAME;
            }

            break;

        case KEY_ENTER:
        case '\n':

            if ( itemMenu == MENU_PLAY_GAME )
            {
                app.SetScreen( PlayScreen::GetInstance( ) );
            }
            else if ( itemMenu == MENU_EXIT_GAME )
            {
                app.OnExit();
            }

            break;

        default:

            break;
    }
}

void MenuScreen::OnEntry( )
{
    Draw( );
    Update( );
}

void MenuScreen::OnExit( )
{

}

void MenuScreen::NextScreen( )
{

}
