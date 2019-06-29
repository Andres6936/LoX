#ifndef _LoX_GAME
#define _LoX_GAME

#include "state.hpp"
#include "item.hpp"
#include "level.hpp"
#include "character.hpp"

class Game : public State
{
    std::vector <Level> _dungeon;        // array of dungeons
    UInt _level;                        // current dungeon level
    Character _player;                  // player character
    std::vector <item_ptr> _inventory;   // player inventory (TODO: Move to character class)

public:
    Game( );

    ~Game( ) override;

    /* method called to update the game, overrides from base State class */
    void Update( ) override;

    /* method called to draw the screen, overrides from base State class */
    void Draw( ) override;
};

#endif
