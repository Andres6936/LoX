#ifndef _LoX_MENU_MAIN
#define _LoX_MENU_MAIN

#pragma once

#include "Include/Common.hpp"
#include "Interface/ISreen.hpp"

/* enumeration of items on the main menu */
enum main_menu_items
{
    MENU_MAIN_ITEM_NEW = 0,
    MENU_MAIN_ITEM_QUIT
};

class MenuScreen : public IScreen
{
    UChar _menupos;

public:

    MenuScreen( );

    void Update( ) override;

    void Draw( ) override;

    void NextScreen() override;
};

#endif
