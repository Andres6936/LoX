#ifndef _LoX_MENU_MAIN
#define _LoX_MENU_MAIN

#pragma once

#include "common.hpp"
#include "ISreen.hpp"

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

    /* method used to update the main menu, overrides from base IScreen class */
    void Update( ) override;

    /* method used to draw the menu, overrides from base IScreen class */
    void Draw( ) override;
};

#endif
