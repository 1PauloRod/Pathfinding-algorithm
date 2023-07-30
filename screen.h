#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 500

SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* window);
void destroyAll(SDL_Window* window, SDL_Renderer* renderer);