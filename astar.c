#include "astar.h"

int heuristic(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int hash(int x, int y){
    return x * COL + y;
}

bool is_valid(int x, int y){
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

void astar(char** map, int start_x, int start_y, int end_x, int end_y, int* totalCost, SDL_Renderer* renderer){
    
    int costs[ROW * COL];
    memset(costs, -1, sizeof(costs)); 
    costs[hash(start_x, start_y)] = 0; 

    int parents[ROW * COL];
    memset(parents, -1, sizeof(parents));
  
    int open_set[ROW * COL];
    memset(open_set, -1, sizeof(open_set)); 
    int num_open = 0;

    bool closed_set[ROW * COL] = {false};

    open_set[num_open++] = hash(start_x, start_y);

    while (num_open > 0) {

        int current = open_set[0];
        int min_f = costs[current] + heuristic(current / COL, current % COL, end_x, end_y);
        for (int i = 1; i < num_open; i++) {
            int cell = open_set[i];
            int f = costs[cell] + heuristic(cell / COL, cell % COL, end_x, end_y);
            if (f < min_f) {
                current = cell;
                min_f = f;
            }
        }
  
        if (current == hash(end_x, end_y)) {
            int path[ROW * COL];
            int num_steps = 0;
            int current_step = current;
            while (current_step != hash(start_x, start_y)) {
                path[num_steps++] = current_step;
                current_step = parents[current_step];
            }
            path[num_steps++] = hash(start_x, start_y);
            draw_path(map, path, num_steps, renderer);
           
            *totalCost += costs[hash(end_x, end_y)];
            printf("\nCost: %d\n", costs[hash(end_x, end_y)]);   
            
            return;
    }

    for (int i = 0; i < num_open; i++) {
        if (open_set[i] == current) {
            open_set[i] = open_set[--num_open];
            break;
        }
    }

    closed_set[current] = true;

    int x = current / COL;
    int y = current % COL;
    int neighbors[4][2] = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
    for (int i = 0; i < 4; i++) {
        int neighbor_x = neighbors[i][0];
        int neighbor_y = neighbors[i][1];
        if (!is_valid(neighbor_x, neighbor_y) || closed_set[hash(neighbor_x, neighbor_y)]) {
            continue;
        }
        int cost;
        char type = map[neighbor_x][neighbor_y];
        switch (type) {
            case '.': 
                cost = 1; 
                break;
            case 'X': 
                cost = 10000; 
                break;   
            case '0': 
                cost = 0; 
                break; 
            case '1': 
                cost = 0; 
                break;        
        }
        int neighbor = hash(neighbor_x, neighbor_y);
        int tentative_cost = costs[current] + cost;
        if (costs[neighbor] == -1 || tentative_cost < costs[neighbor]) {
            costs[neighbor] = tentative_cost;
            parents[neighbor] = current;
            if (!closed_set[neighbor]) {
                open_set[num_open++] = neighbor;
            }
        }
    }
}

printf("No path found.\n");

}

void position(char** map, char value, int* row, int* column){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            if (map[i][j] == value){
                *row = i;
                *column = j;
                return ;
            }
        }
    }
}