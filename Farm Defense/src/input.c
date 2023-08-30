//
//  input.c
//  Farm Defense
//
//  Created by Devaansh Gupta on 24/08/23.
//
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "input.h"
#include "list.h"

Node_t* checkMenu(App_t* game, SDL_Event* event, Menu_t* menu) {
    int mouseX, mouseY;
    
    SDL_GetMouseState(&mouseX, &mouseY);
    
    SDL_Point mousePoint;
    
    mousePoint.x = mouseX;
    mousePoint.y = mouseY;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            SDL_Rect rect = menu->grid[i][j].rect;
            if(SDL_PointInRect(&mousePoint, &rect) == SDL_TRUE) {
                printf("Clicked slot. i: %d, j: %d \n", i, j);
                
                Plant_t* plant = (Plant_t*)malloc(sizeof(Plant_t));
                
                plant->type = menu->grid[i][j].plant_type;
                
                plant->placed = false;
                
                SDL_Surface* plant_surf = NULL;
                
                switch (plant->type) {
                    case 0:
                        plant_surf = IMG_Load("./assets.xcassets/carrot.imageset/carrot.png");
                        plant->cost = 50;
                        plant->cooldown_time = 500;
                        break;
                    case 1:
                        plant_surf = IMG_Load("./assets.xcassets/tree.imageset/tree.png");
                        plant->cost = 70;
                        plant->cooldown_time = 1000;
                        break;
                    case 2:
                        plant_surf = IMG_Load("./assets.xcassets/mushroom.imageset/mushroom.png");
                        plant->cost = 100;
                        plant->cooldown_time = 200;
                        break;
                    default:
                        break;
                }
                
                plant->prev_shoot_time = 0;
                
                plant->text = SDL_CreateTextureFromSurface(game->renderer, plant_surf);
                
                plant->bullet_list = initList(sizeof(Bullet_t));
                
                SDL_FreeSurface(plant_surf);
                
                plant->rect = (SDL_Rect) {
                    .x = mouseX,
                    .y = mouseY,
                    .w = 6 * TILE_SIZE,
                    .h = 6 * TILE_SIZE,
                };
                
                Node_t* node = prepend(game->plant_list, plant);
                
                return node;
            }
        }
    }
    
    return NULL;
}

bool placeSprite(App_t* game, Node_t* plant_node) {
    Plant_t* plant = plant_node->data;
    
    int tile_row = (int)(plant->rect.y/TILE_SIZE); // X index of tile the drag and drop ended on. This is the column index
    int tile_col = (int)(plant->rect.x/TILE_SIZE); // Y index of tile the drag and drop ended on. This is the row index
    
    TileMap_t* tile_map = game->tile_map;
    
    if (tile_row > tile_map->rows - 1 - 2) {
        tile_row = tile_map->rows - 1 - 2;
    }
    
    if (tile_col > tile_map->cols - 1 - 2) {
        tile_col = tile_map->cols - 1 - 2;
    }
    
    for (int i = 0; i < 6; i++) { // Check a 6 by 6 area around this tile, to ensure this tile can be placed in this area
        for (int j = 0; j < 6; j++) {
            if (!(tile_map->map[tile_row + i][tile_col + j].placeable && !(tile_map->map[tile_row + i][tile_col + j].populated))) {
                printf("Cannot place here!\n");
                return false;
            }
        }
    }
    
    plant->rect.y = tile_map->map[tile_row][tile_col].rect.y;
    plant->rect.x = tile_map->map[tile_row][tile_col].rect.x;
    
    for (int i = 0; i < 6; i++) { // Check a 6 by 6 area around this tile, to ensure this tile can be placed in this area
        for (int j = 0; j < 6; j++) {
            tile_map->map[tile_row + i][tile_col + j].populated = true;
        }
    }
    
    plant->placed = true;
    
    game->money -= plant->cost;
    
    return true;    
}
