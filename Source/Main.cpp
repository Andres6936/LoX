#include <Include/Application.hpp>
#include "Include/Common.hpp"
#include "Screen/Interface/ISreen.hpp"
#include "Screen/Include/MenuScreen.hpp"
#include "Screen/Include/PlayScreen.hpp"

int main( int argc, char* argv[] )
{
    // Initialise Random Seed.
    srand( time( nullptr ));

    Application app = Application::GetInstance();
    app.SetScreen( MenuScreen::GetInstance() );
    app.OnExecute();
}
