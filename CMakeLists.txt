CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(LoX)

SET(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(Source)

ADD_EXECUTABLE(LoX
        Source/armour.hpp
        Source/character.cpp
        Source/character.hpp
        Source/common.hpp
        Source/creature.cpp
        Source/creature.hpp
        Source/dieroll.cpp
        Source/dieroll.hpp
        Source/game.cpp
        Source/game.hpp
        Source/item.cpp
        Source/item.hpp
        Source/itemlist.hpp
        Source/level.cpp
        Source/level.hpp
        Source/main.cpp
        Source/menu_main.cpp
        Source/menu_main.hpp
        Source/ranged.hpp
        Source/renderer.cpp
        Source/renderer.hpp
        Source/state.cpp
        Source/state.hpp
        Source/weapon.hpp)

TARGET_LINK_LIBRARIES(LoX ncurses)
