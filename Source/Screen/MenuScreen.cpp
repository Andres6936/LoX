#include "Screen/Include/MenuScreen.hpp"

MenuScreen::MenuScreen( ) :
        _menupos( 0 )
{ }

void MenuScreen::Draw( )
{
    /* clear screen first */
    clear( );

    /* game title */
    std::string str = "Lair of Xyrallion";
    UChar x = ( COLS / 2 ) - ( floor( str.length( ) / 2 ));
    UChar y = ( LINES / 2 ) - (( MENU_MAIN_ITEM_QUIT + 3 ) / 2 );
    renderer.Write( str, x, ++y );

    /* new game option */
    str = "Start Game";
    x = ( COLS / 2 ) - ( str.length( ) / 2 );
    y += 2;
    if ( _menupos == MENU_MAIN_ITEM_NEW )
    { renderer.Write( str, x, y, COL_RED ); }
    else
    { renderer.Write( str, x, y ); }

    /* exit game option */
    str = "Quit";
    x = ( COLS / 2 ) - ( str.length( ) / 2 );
    if ( _menupos == MENU_MAIN_ITEM_QUIT )
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
        /* MENU TRAVERSAL */
        case KEY_UP:
        case 'k':
        case '8':
            if ( _menupos > 0 )
            { _menupos--; }
            break;

        case KEY_DOWN:
        case 'j':
        case '2':
            if ( _menupos < MENU_MAIN_ITEM_QUIT )
            { _menupos++; }
            break;

        case KEY_ENTER:
        case '\n':
            switch ( _menupos )
            {
                case MENU_MAIN_ITEM_NEW:
                    clear( );
                    _state = STATE_GAME;
                    break;

                case MENU_MAIN_ITEM_QUIT:
                    _state = STATE_EXIT;
                    break;
            }
            break;
    }
}

void MenuScreen::NextScreen( )
{

}
