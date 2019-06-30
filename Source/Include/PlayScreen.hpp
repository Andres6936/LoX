#ifndef _LoX_GAME
#define _LoX_GAME

#include "Interface/ISreen.hpp"
#include "Item.hpp"
#include "Level.hpp"
#include "Character.hpp"

class PlayScreen : public IScreen
{
    std::vector <Level> dungeon;        // array of dungeons
    UInt level;                        // current dungeon level
    Character character;                  // player character
    std::vector <item_ptr> inventory;   // player inventory (TODO: Move to character class)

public:
    PlayScreen( );

    ~PlayScreen( ) override;

    /* method called to update the game, overrides from base IScreen class */
    void Update( ) override;

    /* method called to draw the screen, overrides from base IScreen class */
    void Draw( ) override;
};

#endif
