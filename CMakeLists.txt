CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(LoX)

SET(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(Source)

ADD_EXECUTABLE(LoX
        Source/Character.cpp
        Source/Creature.cpp
        Source/DieRoll.cpp
        Source/PlayScreen.cpp
        Source/Item.cpp
        Source/Level.cpp
        Source/Main.cpp
        Source/MenuScreen.cpp
        Source/Renderer.cpp
        Source/Interface/ISreen.cpp
        )

TARGET_LINK_LIBRARIES(LoX ncurses)
