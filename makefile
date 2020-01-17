#Define variables

CC = g++

CFLAGS = -c -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wconversion -Winline -std=c++17

all: The_spell clean

The_spell: Main.o Entity.o Player.o ResourceManager.o BigRect.o Animation.o getInput.o Camera.o SmartRect.o Tile.o CoreFunctions.o
	$(CC) -no-pie -s *.o* -o The_spell -ltgui -lsfml-graphics -lsfml-window -lsfml-system

Main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp

Entity.o: Entity/Entity.cpp
	$(CC) $(CFLAGS) Entity/Entity.cpp

Player.o: Player/Player.cpp
	$(CC) $(CFLAGS) Player/Player.cpp

ResourceManager.o: ResourceManager/ResourceManager.cpp
	$(CC) $(CFLAGS) ResourceManager/ResourceManager.cpp

BigRect.o: BigRect/BigRect.cpp
	$(CC) $(CFLAGS) BigRect/BigRect.cpp

Animation.o: Animation/Animation.cpp
	$(CC) $(CFLAGS) Animation/Animation.cpp

getInput.o: Player/EventHandler/EventHandler.cpp
	$(CC) $(CFLAGS) Player/EventHandler/EventHandler.cpp

Camera.o: Player/Camera/Camera.cpp
	$(CC) $(CFLAGS) Player/Camera/Camera.cpp

SmartRect.o: SmartRect/SmartRect.cpp
	$(CC) $(CFLAGS) SmartRect/SmartRect.cpp

Tile.o: Tile/Tile.cpp
	$(CC) $(CFLAGS) Tile/Tile.cpp

CoreFunctions.o: CentralStuff/CoreFunctions.cpp
	$(CC) $(CFLAGS) CentralStuff/CoreFunctions.cpp

clean:
	rm -rf *o
