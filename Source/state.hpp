#ifndef _LoX_STATE
#define _LoX_STATE

#include "common.hpp"

#include "renderer.hpp"

/* enumeration of all possible game states */
enum EStates
{
    STATE_MAIN_MENU = 0,
    STATE_GAME,

    STATE_EXIT
};

class State
{

protected:

    static UChar _state;    // current state of the machine
    static Renderer _ren;   // renderer used for I/O

public:

    State( ) = default;

    virtual ~State( ) = default;

    /* virtual method that is called to update states */
    virtual void Update( ) = 0;

    /* virtual method that is called to draw states */
    virtual void Draw( ) = 0;

    /* get method for _state */
    UChar _State( ) const
    { return _state; }
};

#endif
