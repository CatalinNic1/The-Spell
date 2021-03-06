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
    -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations
    -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow 
    -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default 
    -Wundef -Wno-unused -Wconversion -std=c++17
)

add_executable(The-Spell
    ./Animation/Animation.cpp
    ./CentralStuff/CoreFunctions.cpp
    ./Enemy/IntelligentEnemy/IntelligentEnemy.cpp
    ./Enemy/BasicEnemy/BasicEnemy.cpp
    ./Enemy/Core/Enemy.cpp
    ./Entity/Entity.cpp
    ./LevelParser/LevelParser.cpp
    ./Player/Camera/Camera.cpp
    ./Player/EventHandler/EventHandler.cpp
    ./Player/Player.cpp
    ./ResourceManager/ResourceManager.cpp
    ./SmartRect/SmartRect.cpp
    ./TileMap/TileMap.cpp
    ./Main.cpp
)

target_link_libraries(The-Spell sfml-graphics sfml-audio sfml-window sfml-system tgui jsoncpp)
file(COPY Resources/ DESTINATION ${CMAKE_BINARY_DIR}/Resources)
file(COPY Tilesets/ DESTINATION ${CMAKE_BINARY_DIR}/Tilesets)
file(COPY Levels/ DESTINATION ${CMAKE_BINARY_DIR}/Levels)