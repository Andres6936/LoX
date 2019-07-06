CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(LoX)

SET(CMAKE_CXX_STANDARD 14)

# Find the librarys here
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/Library)

INCLUDE_DIRECTORIES(Source)

ADD_EXECUTABLE(LoX
        Source/Main.cpp
        Source/Screen/MenuScreen.cpp
        Source/Screen/PlayScreen.cpp
        Source/Matrix/TheMatrix.cpp
        Source/Matrix/RealWorld.cpp
        Source/Matrix/Tile.cpp
        Source/Application.cpp
        Source/Character.cpp
        Source/Entity/Entity.cpp
        Source/DieRoll.cpp
        Source/Item/Item.cpp
        Source/Renderer.cpp
        )

# Load and link the library BearLibTerminal
TARGET_LINK_LIBRARIES(LoX BearLibTerminal)
