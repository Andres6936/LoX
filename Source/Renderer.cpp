#include "Include/Renderer.hpp"

// TODO: make this constructor more robust
Renderer::Renderer( )
{
    TerminalOpen( );
    TerminalSet( "terminal: encoding=437" );
    TerminalSet( "window: size=80x25, cellsize=auto, title=LoX" );
}

Renderer::~Renderer( )
{
    TerminalClose( );
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

    TerminalPut( x, y, _tile.sym );

    /* if there are items here, draw the top item of the stack */
    if ( tile.HasItems( ))
    {
        const ItemPointer item = tile.SeeLastItem( );

        if ( item->GetCategory( ) == EItemCategory::ARMOUR )
        {
            TerminalColor( ColorFromName( "red" ));
            TerminalPut( x, y, '[' );
        }
        else if ( item->GetCategory( ) == EItemCategory::WEAPON )
        {
            TerminalColor( ColorFromName( "cyan" ));
            TerminalPut( x, y, '(' );
        }
        else if ( item->GetCategory( ) == EItemCategory::RANGED )
        {
            TerminalColor( ColorFromName( "green" ));
            TerminalPut( x, y, '{' );
        }

        // Reset the foreground color.
        TerminalColor( ColorFromName( "white" ));
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

        TerminalPut( creature->GetCoordinateX( ) - xoffset, creature->GetCoordinateY( ) - yoffset, _char.sym );
    }
    else
    {
        symbol_map _creature = creature_symbols[ creature->GetType( ) ];

        TerminalPut( creature->GetCoordinateX( ) - xoffset, creature->GetCoordinateY( ) - yoffset, _creature.sym );
    }
}

int Renderer::GetKey( )
{
    return TerminalRead( );
}

void Renderer::Write( std::string msg, int x, int y, int colour, std::string nColor )
{
    TerminalColor( ColorFromName( nColor.c_str( )));
    TerminalPrint( x + 1, y + 1, msg.c_str( ));
}

void Renderer::Message( std::string msg )
{
    TerminalPrint( 0, 24, msg.c_str( ));
}

void Renderer::DrawStats( Character player, UChar level )
{
    /* display name */
    std::string str = player.GetName( );

    TerminalColor( ColorFromName( "yellow" ));
    TerminalPrint( 60, 1, str.c_str( ));

    // Reset the foreground color.
    TerminalColor( ColorFromName( "white" ));

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

    TerminalColor( ColorFromName( "yellow" ));
    TerminalPrint( 60, 2, str.c_str( ));

    // Reset the foreground color.
    TerminalColor( ColorFromName( "white" ));

    /* display hit points */
    str = "HP:";
    str += std::to_string( player.GetHp( ));
    str += "/";
    str += std::to_string( player.GetMaxHp( ));

    TerminalPrint( 60, 4, str.c_str( ));

    /* display mana points */
    str = "MP:";
    str += std::to_string( player.GetMp( ));
    str += "/";
    str += std::to_string( player.GetMaxMp( ));

    TerminalPrint( 60, 5, str.c_str( ));

    /* display experience */
    str = "XP:";
    str += std::to_string( player.GetExperience( ));

    TerminalPrint( 60, 6, str.c_str( ));

    /* DEBUG INFO */
    /* display position */
    str = "X:";
    str += std::to_string( player.GetCoordinateX( ));
    str += " Y:";
    str += std::to_string( player.GetCoordinateY( ));
    str += " Z:";
    str += std::to_string( level + 1 );

    TerminalPrint( 60, 20, str.c_str( ));
}
