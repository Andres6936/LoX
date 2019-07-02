#ifndef _LoX_GAME
#define _LoX_GAME

#pragma once

#include "../Interface/ISreen.hpp"
#include <Include/Renderer.hpp>
#include "Include/Item.hpp"
#include "Include/Level.hpp"
#include "Include/Character.hpp"

class PlayScreen : public IScreen
{
    Character character;

    std::vector <Level> dungeon;        // array of dungeons
    UInt level;                        // current dungeon level
    std::vector <item_ptr> inventory;   // player inventory (TODO: Move to character class)

    Renderer &renderer = Renderer::GetInstance( );

public:

    PlayScreen( );

    ~PlayScreen( ) override;

    static PlayScreen &GetInstance( );

    void Update( ) override;

    void Draw( ) override;

};

#endif
