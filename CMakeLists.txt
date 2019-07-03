CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(LoX)

SET(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(Source)

ADD_EXECUTABLE(LoX
        Source/Main.cpp
        Source/Screen/MenuScreen.cpp
        Source/Screen/PlayScreen.cpp
        Source/Matrix/TheMatrix.cpp
        Source/Matrix/Tile.cpp
        Source/Application.cpp
        Source/Character.cpp
        Source/Entity/Entity.cpp
        Source/DieRoll.cpp
        Source/Item.cpp
        Source/Renderer.cpp
        )

TARGET_LINK_LIBRARIES(LoX ncurses)
