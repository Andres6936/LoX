CMAKE_MINIMUM_REQUIRED(VERSION 3.14 FATAL_ERROR)
PROJECT(LoX VERSION 0.0.1 LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 14)

INCLUDE(CMakeModules/CPM.cmake)

### Add dependencies via CPM
# Add BearLibTerminal like dependency
CPMADDPACKAGE(
        NAME BearLibTerminal
        GITHUB_REPOSITORY Andres6936/BearLibTerminal
        VERSION 2020.4
)

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
TARGET_LINK_LIBRARIES(LoX PRIVATE BearLibTerminal)
