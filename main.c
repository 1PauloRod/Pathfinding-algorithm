#include <stdio.h>
#include <stdbool.h>
#include "screen.h"
#include "map.h"
#include "astar.h"


int main(int argc, char* argv[]){

    SDL_Window* window = createWindow();
    SDL_Renderer* renderer = createRenderer(window);

    SDL_Event event;
    bool isRunning = true;

    char** map = create_map();
    
    load_map(map, renderer);

    int start_x;
    int start_y;
    int end_x; 
    int end_y;
    int totalCost = 0;

    position(map, '0', &start_x, &start_y);
    position(map, '1', &end_x, &end_y);
    astar(map, start_x, start_y, end_x, end_y, &totalCost, renderer);

    while (isRunning){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                isRunning = false;
            }
        }
    }

    destroyAll(window, renderer);

    return 0;
}