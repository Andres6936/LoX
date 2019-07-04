#include "Include/Renderer.hpp"

// TODO: make this constructor more robust
Renderer::Renderer( )
{
    // initialise curses
    initscr( );
    cbreak( );
    noecho( );
    keypad( stdscr, true );
    curs_set( 0 );

    // initialise colours if supported by this terminal
    if ( has_colors( ))
    {
        start_color( );
        init_pair( COL_WHITE, COLOR_WHITE, COLOR_BLACK );
        init_pair( COL_RED, COLOR_RED, COLOR_BLACK );
        init_pair( COL_GREEN, COLOR_GREEN, COLOR_BLACK );
        init_pair( COL_BLUE, COLOR_BLUE, COLOR_BLACK );
        init_pair( COL_CYAN, COLOR_CYAN, COLOR_BLACK );
        init_pair( COL_YELLOW, COLOR_YELLOW, COLOR_BLACK );
        init_pair( COL_MAGENTA, COLOR_MAGENTA, COLOR_BLACK );
    }

    /* initialise windows */
    win_map = newwin( LINES - 2, COLS - ( COLS / 4 ), 0, 0 );
    win_msg = newwin( 2, COLS, LINES - 2, 0 );
    win_stats = newwin( LINES - 2, COLS / 4, 0, COLS - ( COLS / 4 ));
    scrollok( win_msg, TRUE );
    refresh( );

    terminal_open( );
    terminal_set( "terminal: encoding=437" );
    terminal_set( "window: size=80x25, cellsize=auto, title=LoX" );
}

Renderer::~Renderer( )
{
    // close curses
    delwin( win_map );
    delwin( win_msg );
    delwin( win_stats );
    endwin( );

    terminal_close( );
}

Renderer &Renderer::GetInstance( )
{
    static Renderer instance;
    return instance;
}

void Renderer::DrawMap( TheMatrix &level, Character &player )
{
    player.FOV( level );
    ClearMap( );
    UpdateMap( level, player );
    DrawCreature( &player );
    wrefresh( win_map );
}

void Renderer::ClearMap( )
{
    UInt maxx, maxy;
    getmaxyx( win_map, maxy, maxx );
    for ( UInt y = 0; y < maxy; y++ )
    {
        for ( UInt x = 0; x < maxx; x++ )
        {
            mvwaddch( win_map, y, x, ' ' );
        }
    }
    refresh( );
}

void Renderer::UpdateMap( TheMatrix &level, Character player )
{
    /* calculate drawing offsets */
    UInt maxx, maxy;
    getmaxyx( win_map, maxy, maxx );
    int xoffset = player.GetCoordinateX( ) - ( maxx / 2 );
    int yoffset = player.GetCoordinateY( ) - ( maxy / 2 );

    /* draw all tiles visible to the player */
    for ( Vector2D &pos: player.GetVision( ))
    { DrawTile( level.Map( )[ pos.y ][ pos.x ], pos.x - xoffset, pos.y - yoffset ); }
}

void Renderer::DrawTile( Tile &tile, int x, int y )
{
    // -1 porque se añadio un nuevo elemento en la enumeración.
    symbol_map _tile = tile_symbols[ tile.type - 1 ];
    wattron( win_map, COLOR_PAIR( _tile.col ));
    mvwaddch( win_map, y, x, _tile.sym );
    wattroff( win_map, COLOR_PAIR( _tile.col ));

    terminal_put( x, y, _tile.sym );

    /* if there are items here, draw the top item of the stack */
    if ( !tile.items.empty( ))
    {
        symbol_map item = item_symbols[ tile.items[ 0 ]->Category( ) ];
        wattron( win_map, COLOR_PAIR( item.col ));
        mvwaddch( win_map, y, x, item.sym );
        wattron( win_map, COLOR_PAIR( item.col ));

        if ( item.type == ITEM_ARMOUR )
        {
            terminal_color( color_from_name( "red" ));
        }
        else if ( item.type == ITEM_WEAPON )
        {
            terminal_color( color_from_name( "cyan" ));
        }
        else if ( item.type == ITEM_RANGED )
        {
            terminal_color( color_from_name( "green" ));
        }

        terminal_put( x, y, item.sym );

        // Reset the foreground color.
        terminal_color( color_from_name( "white" ));
    }
}

void Renderer::DrawCreature( Entity *creature )
{
    /* calculate drawing offsets */
    UInt maxx, maxy;
    getmaxyx( win_map, maxy, maxx );
    int xoffset = creature->GetCoordinateX( ) - ( maxx / 2 );
    int yoffset = creature->GetCoordinateY( ) - ( maxy / 2 );

    /* if the object passed is a character, cast to character and display symbol based on race */
    if ( creature->GetType( ) == CREATURE_CHARACTER )
    {
        symbol_map _char = character_symbols[ dynamic_cast<Character *>(creature)->GetRace( ) ];
        wattron( win_map, COLOR_PAIR( _char.col ));
        mvwaddch( win_map, creature->GetCoordinateY( ) - yoffset, creature->GetCoordinateX( ) - xoffset, _char.sym );
        wattroff( win_map, COLOR_PAIR( _char.col ));

        terminal_put( creature->GetCoordinateX( ) - xoffset, creature->GetCoordinateY( ) - yoffset, _char.sym );
    }
    else
    {
        symbol_map _creature = creature_symbols[ creature->GetType( ) ];
        wattron( win_map, COLOR_PAIR( _creature.col ));
        mvwaddch( win_map, creature->GetCoordinateY( ) - yoffset, creature->GetCoordinateX( ) - xoffset,
                  _creature.sym );
        wattroff( win_map, COLOR_PAIR( _creature.col ));

        terminal_put( creature->GetCoordinateX( ) - xoffset, creature->GetCoordinateY( ) - yoffset, _creature.sym );
    }
}

int Renderer::GetKey( )
{
    return getch( );
}

void Renderer::Write( std::string msg, int x, int y, int colour, std::string nColor )
{
    attron( COLOR_PAIR( colour ));
    mvaddstr( y, x, msg.c_str( ));
    attroff( COLOR_PAIR( colour ));

    terminal_color( color_from_name( nColor.c_str( )));
    terminal_print( x + 1, y + 1, msg.c_str( ));
}

void Renderer::Message( std::string msg )
{
    scroll( win_msg );
    wattron( win_msg, COLOR_PAIR( COL_WHITE ));
    mvwprintw( win_msg, 1, 0, "%s", msg.c_str( ));
    wattroff( win_msg, COLOR_PAIR( COL_WHITE ));
    wrefresh( win_msg );
}

void Renderer::DrawStats( Character player, UChar level )
{
    /* clear window first */
    wclear( win_stats );

    /* nice border */
    box( win_stats, 0, 0 );

    /* display name */
    std::string str = player.GetName( );
    wattron( win_stats, COLOR_PAIR( COL_YELLOW ));
    mvwaddstr( win_stats, 1, 1, str.c_str( ));

    terminal_color( color_from_name( "yellow" ));
    terminal_print( 60, 1, str.c_str( ));

    // Reset the foreground color.
    terminal_color( color_from_name( "white" ));

    /* display race */
    switch ( player.GetRace( ))
    {
        case RACE_HUMAN:
            str = "Human";
            break;

        case RACE_ELF:
            str = "Elven";
            break;

        case RACE_DWARF:
            str = "Dwarven";
            break;

        case RACE_HALFLING:
            str = "Halfling";
            break;

        case RACE_GNOME:
            str = "Gnome";
            break;

        case RACE_HALF_ORC:
            str = "Half-Orc";
            break;
    }

    /* display class */
    switch ( player.GetClass( ))
    {
        case CLASS_BARBARIAN:
            str += " Barbarian";
            break;

        case CLASS_BARD:
            str += " Bard";
            break;

        case CLASS_CLERIC:
            str += " Cleric";
            break;

        case CLASS_DRUID:
            str += " Druid";
            break;

        case CLASS_FIGHTER:
            str += " Fighter";
            break;

        case CLASS_MONK:
            str += " Monk";
            break;

        case CLASS_PALADIN:
            str += " Paladin";
            break;

        case CLASS_RANGER:
            str += " Ranger";
            break;

        case CLASS_ROGUE:
            str += " Rogue";
            break;

        case CLASS_SORCEROR:
            str += " Sorceror";
            break;

        case CLASS_WIZARD:
            str += " Wizard";
            break;
    }

    mvwaddstr( win_stats, 2, 1, str.c_str( ));
    wattroff( win_stats, COLOR_PAIR( COL_YELLOW ));

    terminal_color( color_from_name( "yellow" ));
    terminal_print( 60, 2, str.c_str( ));

    // Reset the foreground color.
    terminal_color( color_from_name( "white" ));

    /* display hit points */
    str = "HP:";
    str += std::to_string( player.GetHp( ));
    str += "/";
    str += std::to_string( player.GetMaxHp( ));
    mvwaddstr( win_stats, 4, 1, str.c_str( ));

    terminal_print( 60, 4, str.c_str( ));

    /* display mana points */
    str = "MP:";
    str += std::to_string( player.GetMp( ));
    str += "/";
    str += std::to_string( player.GetMaxMp( ));
    mvwaddstr( win_stats, 5, 1, str.c_str( ));

    terminal_print( 60, 5, str.c_str( ));

    /* display experience */
    str = "XP:";
    str += std::to_string( player.GetExperience( ));
    mvwaddstr( win_stats, 6, 1, str.c_str( ));

    terminal_print( 60, 6, str.c_str( ));

    /* DEBUG INFO */
    /* display position */
    str = "X:";
    str += std::to_string( player.GetCoordinateX( ));
    str += " Y:";
    str += std::to_string( player.GetCoordinateY( ));
    str += " Z:";
    str += std::to_string( level + 1 );
    mvwaddstr( win_stats, LINES - 4, 1, str.c_str( ));

    terminal_print( 60, 20, str.c_str( ));

    /* draw window */
    wrefresh( win_stats );
}
