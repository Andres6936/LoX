#ifndef _LoX_STATE
#define _LoX_STATE

#pragma once

#include "Include/Common.hpp"
#include "Include/Renderer.hpp"

/* enumeration of all possible game states */
enum EStates
{
    STATE_MAIN_MENU = 0,
    STATE_GAME,

    STATE_EXIT
};

class IScreen
{

protected:

    static UChar _state;    // current state of the machine
    static Renderer renderer;   // renderer used for I/O

public:

    IScreen( ) = default;

    virtual ~IScreen( ) = default;

    virtual void Update( ) = 0;

    virtual void Draw( ) = 0;

    virtual void NextScreen() = 0;

    UChar GetState( ) const
    { return _state; }
};

#endif
