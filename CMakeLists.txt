cmake_minimum_required(VERSION 3.10)
project(The-Spell)

find_package(SFML COMPONENTS graphics audio system window REQUIRED)
find_package(TGUI COMPONENTS tgui REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    add_compile_options(-g)
endif()

if(CMAKE_BUILD_TYPE MATCHES "Release")
    add_compile_options(-O3)
endif()

add_compile_options(-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy 
    -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations
    -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls 
    -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default 
    -Wundef -Wno-unused -Wconversion -std=c++2a
)

add_executable(The-Spell
    ./EngineLogic/Animation/Animation.cpp
    ./EngineLogic/CentralStuff/CoreFunctions.cpp
    ./EngineLogic/Enemy/IntelligentEnemy/IntelligentEnemy.cpp
    ./EngineLogic/Enemy/BasicEnemy/BasicEnemy.cpp
    ./EngineLogic/Enemy/Core/Enemy.cpp
    ./EngineLogic/Entity/Entity.cpp
    ./EngineLogic/LevelParser/LevelParser.cpp
    ./EngineLogic/Player/Camera/Camera.cpp
    ./EngineLogic/Player/EventHandler/EventHandler.cpp
    ./EngineLogic/Player/Player.cpp
    ./EngineLogic/ResourceManager/ResourceManager.cpp
    ./EngineLogic/SmartRect/SmartRect.cpp
    ./EngineLogic/TileMap/TileMap.cpp
    ./TileEditor/Core/Info/Info.cpp
    ./TileEditor/Core/Widgets/CanvasUpdater/CanvasUpdater.cpp
    ./TileEditor/Core/Widgets/Handlers/Handlers.cpp
    ./TileEditor/Session/Setup/Setup.cpp
    ./TileEditor/Session/EditorSession.cpp
    ./Main.cpp
)

target_link_libraries(The-Spell sfml-graphics sfml-audio sfml-window sfml-system tgui jsoncpp)
file(COPY Resources/ DESTINATION ${CMAKE_BINARY_DIR}/Resources)
file(COPY Tilesets/ DESTINATION ${CMAKE_BINARY_DIR}/Tilesets)
file(COPY Levels/ DESTINATION ${CMAKE_BINARY_DIR}/Levels)