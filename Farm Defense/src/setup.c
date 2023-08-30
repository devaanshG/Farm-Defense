//
//  setup.c
//  Farm Defense
//
//  Created by Devaansh Gupta on 21/08/23

#include <SDL2_ttf/SDL_ttf.h>

#include "setup.h"
#include "types.h"
#include "map.h"
#include "list.h"

void loadWaves(App_t* game);

void createEnemy(App_t* game, Wave_t* wave) {
    Enemy_t* enemy = (Enemy_t*)malloc(sizeof(Enemy_t));
    
    enemy->type = 0;
    enemy->rect.x = 60;
    enemy->rect.y = 0;
    enemy->rect.w = enemy->rect.h = 6 * TILE_SIZE;
    
    enemy->health = 100;
    
    enemy->damage = 20;
    
    enemy->path_section = 0;
    
    enemy->update = false;
    
    SDL_Surface* enemySurf = IMG_Load("./assets.xcassets/robot.imageset/Robot.png");
    
    enemy->text = SDL_CreateTextureFromSurface(game->renderer, enemySurf);
    
    SDL_FreeSurface(enemySurf);
    
    prepend(wave->robot_list, enemy);
}

void loadWaves(App_t* game) {
    // Wave 0
    Wave_t* wave0 = (Wave_t*)malloc(sizeof(Wave_t));
    
    wave0->robot_list = initList(sizeof(Enemy_t));
    
    for (int i = 0; i < 1; i++) {
        createEnemy(game, wave0);
    }
    
    wave0->delay      = 0;
    
    wave0->health     = 100;
    
    wave0->speed      = 1;
    
    wave0->robot_num  = 0;
    wave0->num_robots = 1;
    
    wave0->start_time = SDL_GetTicks();
    
    append(game->wave_list, wave0);
    
    game->cur_wave = game->wave_list->head;
    
    // Wave 1
    Wave_t* wave1 = (Wave_t*)malloc(sizeof(Wave_t));
    
    wave1->robot_list = initList(sizeof(Enemy_t));

    for (int i = 0; i < 5; i++) {
        createEnemy(game, wave1);
    }
    
    wave1->delay      = 2000;

    wave1->health     = 100;

    wave1->speed      = 1;
    
    wave1->robot_num  = 0;
    wave1->num_robots  = 5;

    append(game->wave_list, wave1);
    
    // Wave 2
    
    Wave_t* wave2 = (Wave_t*)malloc(sizeof(Wave_t));
    
    wave2->robot_list = initList(sizeof(Enemy_t));

    wave2->num_robots = 8;
    
    for (int i = 0; i < wave2->num_robots; i++) {
        createEnemy(game, wave2);
    }
    
    wave2->delay      = 1000;

    wave2->health     = 100;

    wave2->speed      = 1;
    
    wave2->robot_num  = 0;
    

    append(game->wave_list, wave2);
    
    // Wave 3
    
    Wave_t* wave3 = (Wave_t*)malloc(sizeof(Wave_t));
    
    wave3->robot_list = initList(sizeof(Enemy_t));

    wave3->num_robots = 8;
    
    for (int i = 0; i < wave3->num_robots; i++) {
        createEnemy(game, wave2);
    }
    
    wave3->delay      = 1000;

    wave3->health     = 100;

    wave3->speed      = 1.25;
    
    wave3->robot_num  = 0;
    
    append(game->wave_list, wave2);
}

App_t* setup(int WIN_SIZE) {
    // Initialise SDL2, for multimedia operations
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        // Print error
        printf("Error initialising SDL2: %s", SDL_GetError());
    }
    
    // Initialise SDL2_image, for working with images of various formats
    if(IMG_Init(IMG_INIT_PNG) < 0) {
        // Print error
        printf("Error initialising SDL2_image: %s", IMG_GetError());
    }
    
    
    // Initialise SDL2_ttf, for rendering text
    if(TTF_Init() < 0) {
        // Print error
        printf("Error initialising SDL2_ttf: %s", TTF_GetError());
    }
    
    // Create objects such as window, renderer, for game management
    App_t* game = (App_t*)malloc(sizeof(App_t));
    
        // Create window object. Movable, but has fixed size.
        // SDL_RENDERER_PRESENTVSYNC flag tells SDL to maintains 60fps
    game->window = SDL_CreateWindow("Farm Defence", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 960, SDL_WINDOW_SHOWN);
    
        // Create renderer object, that allows us to render images onto the window.
        // Index of -1 shows window above all else
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    
    
    TTF_Font* font = TTF_OpenFont("./VT323-Regular.ttf", 20);
    
    if (font == NULL) {
        printf("Error loading font\n");
    }
    
    game->font = font;
    
    game->wave   = 0;
    game->money  = 100;
    game->health = 100;
    
    game->wave_list = initList(sizeof(Wave_t));
    
    loadWaves(game);
    
    game->plant_list = initList(sizeof(Plant_t));  // Initialising the list of Plant_t's the game has
    
    return game;
}

Menu_t* loadMenu(void) {
    Menu_t* menu = (Menu_t*)malloc(sizeof(Menu_t));
    
    menu->money = 0;
    menu->wave  = 0;
    
    int grid_top_left_x = 60;
    int grid_top_left_y = 40 + 640;
    int grid_size       = 100 + 2 * 10;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            Slot_t slot;
            slot.rect.x = grid_top_left_x + grid_size * j + 10;
            slot.rect.y = grid_top_left_y + grid_size * i + 10;
            slot.rect.w = slot.rect.h = 100;
            slot.plant_type = (i+1) * (j+1) - 1;
            
            menu->grid[i][j] = slot;
        }
    }
    
    return menu;
}

TileMap_t* loadMap(const uint32_t map[64][64], int width, int height) {
    TileMap_t* tile_map = (TileMap_t*)malloc(sizeof(TileMap_t));
    
    tile_map->cols = width;
    tile_map->rows = height;
    
    tile_map->map = (Tile_t**)malloc(sizeof(Tile_t*) * height);
    
    for (int i = 0; i < height; i++) {
        tile_map->map[i] = (Tile_t*)malloc(sizeof(Tile_t) * width);
        
        for (int j = 0; j < width; j++) {
            // Allocate memory for the Tile_t object that will store the data for this specific tile, that will populate the TileMap_t for our game.
            // This object stores more than just x and y position and what sort of tile it is. See 'types.h' for further clarification.
            Tile_t tile;
            
            // int representation of the specific tile we are looking at, based on the input 2D int array
            int input_tile = map[i][j];
            
            // SDL_Rect property of the Tile_t that stores x and y position in coordinates, as well as width and height of the tile
            SDL_Rect rect;

            rect.x = j * TILE_SIZE;
            rect.y = i * TILE_SIZE;
            rect.w = rect.h = TILE_SIZE;
            
            tile.rect  = rect;
            tile.idx_x = j;
            tile.idx_y = i;
            tile.type  = input_tile;
            
            
            // Based on the type of tile the input map gives us, create a Tile_t object
            switch (input_tile) {
                case GRASS_DARK:
                    tile.placeable = true;
                    tile.populated = false;
                    tile.col = (SDL_Color){47, 200, 74, 255};
                    break;
                case GRASS_LIGHT:
                    tile.placeable = true;
                    tile.populated = false;
                    tile.col = (SDL_Color){117, 255, 98, 255};
                    break;
                case PATH_OUTLINE:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){142, 147, 102, 255};
                    break;
                case PATH_FILL:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){203, 211, 144, 255};
                    break;
                case PATH_DETAIL:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){162, 170, 109, 255};
                    break;
                case GRASS_SHADOW_DARK:
                    tile.placeable = true;
                    tile.populated = false;
                    tile.col = (SDL_Color){60, 160, 78, 255};
                    break;
                case GRASS_SHADOW_LIGHT:
                    tile.placeable = true;
                    tile.populated = false;
                    tile.col = (SDL_Color){86, 188, 72, 255};
                    break;
                case CLIFF_DARK:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){61, 52, 43, 255};
                    break;
                case CLIFF_LIGHT:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){87, 75, 61, 255};
                    break;
                case FLOWER_DARK_BLUE:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){25, 97, 127, 255};
                    break;
                case FLOWER_LIGHT_BLUE:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){97, 225, 228, 255};
                    break;
                case FLOWER_WHITE:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){255, 255, 255, 255};
                    break;
                case FLOWER_PINK:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){217, 127, 127, 255};
                    break;
                case FLOWER_CENTER:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){226, 194, 52, 255};
                    break;
                case FLOWER_STEM:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){60, 224, 26, 255};
                    break;
                case POND_OUTLINE:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){102, 78, 49, 255};
                    break;
                case POND_LIGHT:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){97, 225, 228, 255};
                    break;
                case POND_DARK:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){73, 195, 198, 255};
                    break;
                case LILY_DARK:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){60, 160, 78, 255};
                    break;
                case LILY_LIGHT:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){86, 188, 72, 255};
                    break;
                case ROCK_OUTLINE:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){179, 179, 179, 255};
                    break;
                case ROCK_FILL:
                    tile.placeable = false;
                    tile.populated = false;
                    tile.col = (SDL_Color){190, 190, 190, 255};
                    break;
                default:
                    break;
            }
            
            tile_map->map[i][j] = tile;
        }
    }
    
    return tile_map;
}
