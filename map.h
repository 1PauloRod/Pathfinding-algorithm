#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "screen.h"

#define COL 20
#define ROW 10

char** create_map();
void load_map(char** map, SDL_Renderer* renderer);
void draw_path(char** map, int* path, int num_steps, SDL_Renderer* renderer);
void draw_position_map(char** map, SDL_Renderer* renderer, int posX, int posY);
