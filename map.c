#include "map.h"


char** create_map(){
    char tile[ROW][COL] = {
                    {'0', '.', 'X', '.', 'x', '.', 'X', '.', 'X', '.', 'X', '.', 'X', 'X', '.', 'X', 'X', '.', '.', '.'},
                    {'.', '.', 'X', '.', '.', '.', 'X', '.', 'X', '.', 'X', '.', 'X', 'X', '.', 'X', 'X', '.', 'X', '.'},
                    {'.', '.', 'X', '.', 'X', '.', 'X', '.', 'X', '.', 'X', '.', 'X', 'X', '.', 'X', 'X', '.', 'X', '.'},
                    {'.', '.', 'X', '.', 'X', '.', 'X', '.', '.', '.', 'X', '.', 'X', 'X', '.', 'X', 'X', '.', 'X', '.'},
                    {'.', '.', 'X', '.', 'X', '.', 'X', '.', 'X', '.', 'X', '.', '.', '.', '.', 'X', 'X', '.', 'X', '.'},
                    {'.', '.', 'X', '.', 'X', '.', 'X', '.', 'X', '.', 'X', '.', 'X', 'X', '.', 'X', 'X', '.', 'X', '.'},
                    {'.', '.', 'X', '.', 'X', '.', 'X', '.', 'X', '.', 'X', '.', 'X', 'X', '.', 'X', 'X', '.', 'X', '.'},
                    {'.', '.', 'X', '.', 'X', '.', 'X', '.', 'X', '.', '.', '.', 'X', 'X', '.', 'X', 'X', '.', 'X', '.'},
                    {'.', '.', 'x', '.', 'X', '.', '.', '.', 'X', 'X', 'X', '.', 'X', 'X', '.', 'X', 'X', '.', 'X', '.'},
                    {'.', '.', '.', '.', 'X', '.', 'X', '.', 'X', 'X', 'X', '.', 'X', 'X', '.', '.', '.', '.', 'X', '1'} 
    };

    char** map = (char**)malloc((ROW+1) * sizeof(char*));
    if (map == NULL) return NULL;

    for (int i = 0; i < COL; i++){
        map[i] = (char*)malloc((COL+1)* sizeof(char));
        if (map[i] == NULL) return NULL;
    }

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            map[i][j] = tile[i][j];
        }
    }

    return map;
}

void load_map(char** map, SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    int sizeX = WINDOW_WIDTH/COL;
    int sizeY = WINDOW_HEIGHT/ROW;
    
    SDL_Rect rect;

    for (int row = 0; row < ROW; row++){
        for (int column = 0; column < COL; column++){
            char type = map[row][column];
            rect.x = sizeX*column;
            rect.y = sizeY*row;
            rect.w = sizeX;
            rect.h = sizeY;

            switch(type){
                case '.':
                    SDL_SetRenderDrawColor(renderer, 32, 32, 32, 0);
                    break;
                case 'X':
                    SDL_SetRenderDrawColor(renderer, 0, 104, 204, 0);
                    break;
                case '0':
                    SDL_SetRenderDrawColor(renderer, 255, 255, 102, 0);
                    break;
                case '1':
                    SDL_SetRenderDrawColor(renderer, 255, 51, 51, 0);
                    break;
                
            }
            SDL_RenderFillRect(renderer, &rect);
        }
    }
    SDL_RenderPresent(renderer);
}

void draw_position_map(char** map, SDL_Renderer* renderer, int posX, int posY){
    SDL_Delay(50);

    int lambdaY = WINDOW_WIDTH/COL;
    int lambdaX = WINDOW_HEIGHT/ROW;
    int sizeX = WINDOW_WIDTH/COL;
    int sizeY = WINDOW_HEIGHT/ROW;
    SDL_Rect rect;
    rect.x =  lambdaX * posX;
    rect.y = lambdaY * posY;
    rect.w = sizeX;
    rect.h =  sizeY;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
}

void draw_path(char** map, int* path, int num_steps, SDL_Renderer* renderer){
   
    printf("Optimal Path:\n");
    for (int i = num_steps - 1; i >= 0; i--) {
        int x = path[i] / COL;
        int y = path[i] % COL;
        draw_position_map(map, renderer, y, x);// 5 é o fator multiplicador da tela
        printf("(%d,%d)", x, y);        
        
        if (i > 0) {
            printf(" -> ");
        }
    }
    printf(" -> GOAL\n");
    
}