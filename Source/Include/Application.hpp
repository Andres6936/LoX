#ifndef LOX_APPLICATION_HPP
#define LOX_APPLICATION_HPP

#pragma once

#include <Screen/Interface/ISreen.hpp>

class Application
{

private:

    bool running = true;

    IScreen *screen = nullptr;

    Application() = default;

public:

    static Application &GetInstance();

    void OnExecute();

    void OnExit();

    void SetScreen(IScreen &nIScreen);

};


#endif //LOX_APPLICATION_HPP
