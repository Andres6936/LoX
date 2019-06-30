#include "common.hpp"
#include "Include/ISreen.hpp"
#include "Include/MenuScreen.hpp"
#include "Include/PlayScreen.hpp"

int main( int argc, char* argv[] )
{
    /* initialise random seed */
    srand( time( NULL ));

    /* initialise state machine */
    IScreen *states[STATE_EXIT];

    MenuScreen menu;
    PlayScreen lox;

    states[ 0 ] = &menu;
    states[ 1 ] = &lox;

    /* game loop */
    while ( states[ 0 ]->GetState( ) != STATE_EXIT )
    {
        states[ states[ 0 ]->GetState( ) ]->Draw( );
        states[ states[ 0 ]->GetState( ) ]->Update( );
    }
}
