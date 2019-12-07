#Define variables

CC = g++

CFLAGS = -c -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wconversion -Winline -std=c++17

all: The_spell clean

The_spell: main.o Entity.o Player.o ResourceManager.o BigRect.o Animation.o getInput.o Camera.o
	$(CC) -no-pie -s *o -o The_spell -ltgui -lsfml-graphics -lsfml-window -lsfml-system

main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp

Entity.o: Entity/Entity.cpp
	$(CC) $(CFLAGS) Entity/Entity.cpp

Player.o: Player/Player.cpp
	$(CC) $(CFLAGS) Player/Player.cpp

ResourceManager.o:
	$(CC) $(CFLAGS) ResourceManager/ResourceManager.cpp

BigRect.o:
	$(CC) $(CFLAGS) BigRect/BigRect.cpp

Animation.o:
	$(CC) $(CFLAGS) Animation/Animation.cpp

getInput.o:
	$(CC) $(CFLAGS) Player/EventHandler/EventHandler.cpp

Camera.o:
	$(CC) $(CFLAGS) Player/Camera/Camera.cpp

clean:
	rm -rf *o
