#include "Include/Application.hpp"

Application &Application::GetInstance( )
{
    static Application instance;
    return instance;
}

void Application::OnExecute( )
{
    while ( running )
    {
        screen->Draw( );
        screen->Update( );
    }
}

void Application::OnExit( )
{
    running = false;
}

void Application::SetScreen( IScreen &nIScreen )
{
    screen = nullptr;
    screen = &nIScreen;
}
