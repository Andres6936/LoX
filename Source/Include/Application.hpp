#ifndef LOX_APPLICATION_HPP
#define LOX_APPLICATION_HPP

#pragma once

#include <Screen/Interface/ISreen.hpp>

class Application
{

private:

    bool running = true;

    IScreen *screen = nullptr;

    Application( ) = default;

public:

    // Constructs

    Application( Application const & ) = delete; // Copy construct
    Application( Application && ) = delete; // Move construct

    static Application &GetInstance( );

    void OnExecute( );

    void OnExit( );

    void SetScreen( IScreen &nIScreen );

    // Operator

    Application &operator=( Application const & ) = delete; // Copy assign
    Application &operator=( Application && ) = delete; // Move assign

};


#endif //LOX_APPLICATION_HPP
