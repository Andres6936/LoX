#include "Include/Renderer.hpp"

// TODO: make this constructor more robust
Renderer::Renderer( )
{
    terminal_open( );
    terminal_set( "terminal: encoding=437" );
    terminal_set( "window: size=80x25, cellsize=auto, title=LoX" );
}

Renderer::~Renderer( )
{
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
}

void Renderer::ClearMap( )
{

}

void Renderer::UpdateMap( TheMatrix &level, Character player )
{
    /* calculate drawing offsets */
    // Terminal 80 x 25
    int xoffset = player.GetCoordinateX( ) - ( 80 / 2 );
    int yoffset = player.GetCoordinateY( ) - ( 25 / 2 );

    /* draw all tiles visible to the player */
    for ( Vector2D &pos: player.GetVision( ))
    { DrawTile( level.GetTileAtIndex( pos.x, pos.y ), pos.x - xoffset, pos.y - yoffset ); }
}

void Renderer::DrawTile( Tile &tile, int x, int y )
{
    // -1 porque se añadio un nuevo elemento en la enumeración.
    symbol_map _tile = tile_symbols[ tile.type - 1 ];

    terminal_put( x, y, _tile.sym );

    /* if there are items here, draw the top item of the stack */
    if ( !tile.items.empty( ))
    {
        symbol_map item = item_symbols[ tile.items[ 0 ]->GetCategory( ) ];

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
    // Terminal 80 x 25
    int xoffset = creature->GetCoordinateX( ) - ( 80 / 2 );
    int yoffset = creature->GetCoordinateY( ) - ( 25 / 2 );

    /* if the object passed is a character, cast to character and display symbol based on race */
    if ( creature->GetType( ) == CREATURE_CHARACTER )
    {
        symbol_map _char = character_symbols[ dynamic_cast<Character *>(creature)->GetRace( ) ];

        terminal_put( creature->GetCoordinateX( ) - xoffset, creature->GetCoordinateY( ) - yoffset, _char.sym );
    }
    else
    {
        symbol_map _creature = creature_symbols[ creature->GetType( ) ];

        terminal_put( creature->GetCoordinateX( ) - xoffset, creature->GetCoordinateY( ) - yoffset, _creature.sym );
    }
}

int Renderer::GetKey( )
{
    return terminal_read( );
}

void Renderer::Write( std::string msg, int x, int y, int colour, std::string nColor )
{
    terminal_color( color_from_name( nColor.c_str( )));
    terminal_print( x + 1, y + 1, msg.c_str( ));
}

void Renderer::Message( std::string msg )
{
    terminal_print( 0, 24, msg.c_str( ));
}

void Renderer::DrawStats( Character player, UChar level )
{
    /* display name */
    std::string str = player.GetName( );

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

    terminal_color( color_from_name( "yellow" ));
    terminal_print( 60, 2, str.c_str( ));

    // Reset the foreground color.
    terminal_color( color_from_name( "white" ));

    /* display hit points */
    str = "HP:";
    str += std::to_string( player.GetHp( ));
    str += "/";
    str += std::to_string( player.GetMaxHp( ));

    terminal_print( 60, 4, str.c_str( ));

    /* display mana points */
    str = "MP:";
    str += std::to_string( player.GetMp( ));
    str += "/";
    str += std::to_string( player.GetMaxMp( ));

    terminal_print( 60, 5, str.c_str( ));

    /* display experience */
    str = "XP:";
    str += std::to_string( player.GetExperience( ));

    terminal_print( 60, 6, str.c_str( ));

    /* DEBUG INFO */
    /* display position */
    str = "X:";
    str += std::to_string( player.GetCoordinateX( ));
    str += " Y:";
    str += std::to_string( player.GetCoordinateY( ));
    str += " Z:";
    str += std::to_string( level + 1 );

    terminal_print( 60, 20, str.c_str( ));
}
