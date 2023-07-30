all:
	gcc -Wall -o main.exe main.c astar.c map.c screen.c -I "C:\MinGW\include\SDL2" -lmingw32 -lSDL2main -lSDL2