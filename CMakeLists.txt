CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(LoX)

SET(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(Source)

ADD_EXECUTABLE(LoX
        Source/character.cpp
        Source/creature.cpp
        Source/dieroll.cpp
        Source/PlayScreen.cpp
        Source/item.cpp
        Source/level.cpp
        Source/main.cpp
        Source/MenuScreen.cpp
        Source/renderer.cpp
        Source/ISreen.cpp
        )

TARGET_LINK_LIBRARIES(LoX ncurses)
