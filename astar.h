#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "map.h"


int heuristic(int x1, int y1, int x2, int y2);
int hash(int x, int y);
bool is_valid(int x, int y);
void astar(char** map, int start_x, int start_y, int end_x, int end_y, int* totalCost, SDL_Renderer* renderer);
void position(char** map, char value, int* row, int* column);
