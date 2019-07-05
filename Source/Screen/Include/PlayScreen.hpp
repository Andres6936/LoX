#ifndef _LoX_GAME
#define _LoX_GAME

#pragma once

#include "../Interface/ISreen.hpp"
#include <Include/Renderer.hpp>
#include "Include/Item.hpp"
#include "Matrix/Include/TheMatrix.hpp"
#include "Include/Character.hpp"

class PlayScreen : public IScreen
{
    Character character = Character( "Slash" );
    TheMatrix theMatrix = TheMatrix( LEVEL_WIDTH, LEVEL_HEIGHT );

    UInt level;                        // current dungeon level
    std::vector <ItemPointer> inventory;   // player inventory (TODO: Move to character class)

    Renderer &renderer = Renderer::GetInstance( );

public:

    PlayScreen( );

    ~PlayScreen( ) override;

    static PlayScreen &GetInstance( );

    void Update( ) override;

    void Draw( ) override;

};

#endif
