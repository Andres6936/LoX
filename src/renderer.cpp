#include "renderer.hpp"

// TODO: make this constructor more robust
Renderer::Renderer() {
    // allocate space for screen (std 80x24 terminal)
    _screen = new char* [24];
    for(int i = 0; i < 24; i++) {
        _screen[i] = new char [80];
    }

    // initialise curses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
}

Renderer::~Renderer() {
    // close curses
    endwin();

    // free memory used by screen
    for(int i = 0; i < 24; i++) {
        delete [] _screen[i];
    }
    delete [] _screen;
}

void Renderer::UpdateMap(Level& level) {
    for(int y = 0; y < level.H(); y++) {
        for(int x = 0; x < level.W(); x++) {
            if(level.Map()[y][x].visible) UpdateMap(level.Map()[y][x].type, x, y);
            else UpdateMap(255, x, y);
        }
    }
}

void Renderer::UpdateMap(char tile, int x, int y) {
    char symbol;

    switch(tile) {
        case MAP_FLOOR:
            symbol = '.';
            break;

        case MAP_WALL:
            symbol = '#';
            break;

        case MAP_STAIR_UP:
            symbol = '<';
            break;

        case MAP_STAIR_DOWN:
            symbol = '>';
            break;

        default:
            symbol = ' ';
            break;
    }

    mvaddch(y, x, symbol);
}

void Renderer::DrawCreature(Creature creature) {
    char symbol;
    
    switch(creature.Type()) {
        case CREATURE_CHARACTER:
        break;
    }
    
    mvaddch(creature.Pos().y, creature.Pos().x, symbol);
}

void Renderer::DrawCharacter(Character character) {
    char symbol;
    
    switch(character.Race()) {
        case RACE_HUMAN:
            symbol = '@';
            break;
    }
    
    mvaddch(character.Pos().y, character.Pos().x, symbol);
}

int Renderer::GetKey() {
    return getch();
}

void Renderer::Write(std::string msg, int x, int y) {
    mvaddstr(y, x, msg.c_str());
}

void Renderer::DisplayStats(Character player) {
    std::string line = player.Name();
    line += " the ";

    switch(player.Race()) {
        case RACE_HUMAN:
            line += "Human";
            break;
        
        case RACE_ELF:
            line += "Elven";
            break;
        
        case RACE_DWARF:
            line += "Dwarven";
            break;
        
        case RACE_HALFLING:
            line += "Halfling";
            break;
        
        case RACE_GNOME:
            line += "Gnome";
            break;
        
        case RACE_HALF_ORC:
            line += "Half-Orc";
            break;
        
        case RACE_DROMITE:
            line += "Dromite";
            break;
        
        case RACE_DUERGAR:
            line += "Duergar";
            break;
        
        case RACE_ELAN:
            line += "Elan";
            break;
        
        case RACE_HALF_GIANT:
            line += "Half-Giant";
            break;
        
        case RACE_MAENAD:
            line += "Maenad";
            break;
        
        case RACE_XEPH:
            line += "Xeph";
            break;
    }
    
    switch(player.Class()) {
        case CLASS_BARBARIAN:
            line += " Barbarian";
            break;
        
        case CLASS_BARD:
            line += " Bard";
            break;
        
        case CLASS_CLERIC:
            line += " Cleric";
            break;
        
        case CLASS_DRUID:
            line += " Druid";
            break;
        
        case CLASS_FIGHTER:
            line += " Fighter";
            break;
        
        case CLASS_MONK:
            line += " Monk";
            break;
        
        case CLASS_PALADIN:
            line += " Paladin";
            break;
        
        case CLASS_PSION:
            line += " Psion";
            break;
        
        case CLASS_PSYCHIC_WARRIOR:
            line += " Psychic Warrior";
            break;
        
        case CLASS_RANGER:
            line += " Ranger";
            break;
        
        case CLASS_ROGUE:
            line += " Rogue";
            break;
        
        case CLASS_SORCEROR:
            line += " Sorceror";
            break;
        
        case CLASS_SOULKNIFE:
            line += " Soulknife";
            break;
        
        case CLASS_WILDER:
            line += " Wilder";
            break;
        
        case CLASS_WIZARD:
            line += " Wizard";
            break;
    }
    
    line += " HP:";
    line += std::to_string(player.Hp());
    line += "/";
    line += std::to_string(player.MaxHp());
    line += " MP:";
    line += std::to_string(player.Mp());
    line += "/";
    line += std::to_string(player.MaxMp());
    line += " XP:";
    line += std::to_string(player.Xp());
    
    mvaddstr(22, 0, line.c_str());
}

void cast_light(Level& level, uint x, uint y, uint radius, uint row, float start_slope, float end_slope, uint xx, uint xy, uint yx, uint yy) {
    if(start_slope < end_slope) return;
    float next_start_slope = start_slope;

    for(uint i = row; i <= radius; i++) {
        bool blocked = false;

        for(int dx = -i, dy = -i; dx <= 0; dx++) {
            float l_slope = (dx - 0.5) / (dy + 0.5);
            float r_slope = (dx + 0.5) / (dy - 0.5);

            if(start_slope < r_slope) continue;
            else if(end_slope > l_slope) break;

            int sax = dx * xx + dy * xy;
            int say = dx * yx + dy * yy;
            if((sax < 0 && (uint)std::abs(sax) > x) || (say < 0 && (uint)std::abs(say) > y)) continue;

            uint ax = x + sax;
            uint ay = y + say;
            if(ax >= level.W() || ay >= level.H()) continue;

            uint radius2 = radius * radius;
            if((uint)(dx * dx + dy * dy) < radius2) level.SetVis(ax, ay, true);

            if(blocked) {
                if(level.Map()[ay][ax].opaque) {
                    next_start_slope = r_slope;
                    continue;
                }
                else {
                    blocked = false;
                    start_slope = next_start_slope;
                }
            }
            else if(level.Map()[ay][ax].opaque) {
                blocked = true;
                next_start_slope = r_slope;
                cast_light(level, x, y, radius, i+1, start_slope, l_slope, xx, xy, yx, yy);
            }
        }

        if(blocked) break;
    }
}

static int multipliers[4][8] = {
    { 1, 0, 0,-1,-1, 0, 0, 1},
    { 0, 1,-1, 0, 0,-1, 1, 0},
    { 0, 1, 1, 0, 0,-1,-1, 0},
    { 1, 0, 0, 1,-1, 0, 0,-1}
};

void Renderer::FOV(Level& level, uint x, uint y, uint radius) {
    for(uint i = 0; i < 8; i++) {
        cast_light(level, x, y, radius, 1, 1.0, 0.0, multipliers[0][i], multipliers[1][i], multipliers[2][i], multipliers[3][i]);
    }
}
