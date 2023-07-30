#include "screen.h"


SDL_Window* createWindow(){

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Pathfinding", 
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
    WINDOW_WIDTH, WINDOW_HEIGHT, 
    SDL_WINDOW_OPENGL);
    if (window == NULL) return NULL;

    return window;
}

SDL_Renderer* createRenderer(SDL_Window* window){

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) return NULL;

    return renderer; 
}

void destroyAll(SDL_Window* window, SDL_Renderer* renderer){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

