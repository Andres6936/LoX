#ifndef _LoX_MENU_MAIN
#define _LoX_MENU_MAIN

#pragma once

#include "../Interface/ISreen.hpp"
#include <Include/Application.hpp>
#include <Include/Renderer.hpp>
#include "PlayScreen.hpp"

/* enumeration of items on the main menu */
enum EItemMenu
{
    MENU_PLAY_GAME,
    MENU_EXIT_GAME
};

class MenuScreen : public IScreen
{

private:

    EItemMenu itemMenu = MENU_PLAY_GAME;

    Application app = Application::GetInstance();
    Renderer renderer = Renderer::GetInstance();

public:

    MenuScreen( );

    static MenuScreen &GetInstance();

    void Update( ) override;

    void Draw( ) override;

    void OnEntry() override;

    void OnExit() override;

    void NextScreen() override;
};

#endif
