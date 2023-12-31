//
//  map.h
//  Farm Defense
//
//  Created by Devaansh Gupta on 22/08/23.
//

#ifndef map_h
#define map_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include <stdint.h>

typedef enum MAP_KEY {
    GRASS_DARK          = 0,  // Dark Green Grass
    GRASS_LIGHT         = 1,  // Light Green Grass
    PATH_OUTLINE        = 2,  // Dark Brown path outline
    PATH_FILL           = 3,  // Normal Brown path fill
    PATH_DETAIL         = 4,  // Slightly Dark Brown path highlight
    GRASS_SHADOW_DARK   = 5,  // Dark Green Grass shadow
    CLIFF_DARK          = 6,  // Cliff dark brown
    GRASS_SHADOW_LIGHT  = 7,  // Light Green Grass shadow
    CLIFF_LIGHT         = 8,  // Cliff light brown
    FLOWER_DARK_BLUE    = 9,  // Flower dark blue
    FLOWER_PINK         = 10, // Flower pink
    FLOWER_LIGHT_BLUE   = 12, // Flower light blue
    FLOWER_WHITE        = 13, // Flower white
    FLOWER_CENTER       = 14, // Flower center
    FLOWER_STEM         = 15, // Flower stem
    POND_OUTLINE        = 16, // Pond outline
    POND_LIGHT          = 17, // Pond light blue
    POND_DARK           = 18, // Pond dark blue
    LILY_DARK           = 19, // Lily pad dark
    LILY_LIGHT          = 20, // Lily pad light
    ROCK_OUTLINE        = 21, // Rock outline
    ROCK_FILL           = 22, // Rock fill
} MAP_KEY;

static const uint32_t map[64][64] = {
    {0, 0, 1, 1, 2, 3, 4, 3, 3, 3, 3, 3, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 5, 6, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 5, 6, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 2, 3, 4, 3, 3, 3, 3, 3, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 7, 6, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {1, 1, 0, 0, 2, 3, 4, 3, 3, 3, 3, 4, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 7, 6, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 2, 3, 4, 3, 3, 3, 3, 4, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 5, 6, 8, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 2, 3, 4, 3, 3, 3, 3, 4, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 5, 6, 8, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 7, 7, 6, 8, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {1, 1, 0, 0, 2, 3, 4, 3, 3, 3, 4, 4, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 6, 6, 8, 8, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 2, 3, 4, 3, 3, 3, 3, 4, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 7, 6, 6, 8, 8, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 2, 3, 3, 3, 3, 3, 3, 4, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 5, 5, 6, 6, 8, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 2, 3, 3, 3, 3, 3, 3, 4, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 7, 5, 6, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    {1, 1, 0, 0, 2, 3, 4, 3, 3, 3, 3, 3, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {0, 0, 1, 1, 2, 3, 4, 3, 3, 3, 3, 3, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 5, 5, 7, 7, 5, 5, 7, 7, 5, 5, 7, 7, 5, 5, 7, 7, 5, 5, 7, 7, 5, 5, 7, 7, 5, 5, 7, 7},
    {0, 0, 1, 1, 2, 3, 4, 3, 3, 3, 3, 3, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 5, 5, 7, 7, 5, 5, 7, 7, 5, 5, 7, 7, 5, 5, 7, 7, 5, 5, 7, 7, 5, 5, 7, 7, 5, 5, 7, 7},
    {1, 1, 0, 0, 2, 3, 4, 3, 3, 3, 3, 4, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {1, 1, 0, 0, 2, 3, 4, 3, 3, 3, 3, 4, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 2, 3, 4, 4, 3, 3, 3, 4, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 2, 3, 4, 4, 4, 3, 3, 4, 3, 2, 1, 1, 0, 0, 1, 9, 0, 0, 1, 10, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 2, 3, 4, 3, 4, 4, 4, 4, 3, 2, 0, 0, 1, 1, 9, 14, 9, 1, 10, 14, 10, 1, 13, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {1, 1, 0, 0, 2, 3, 4, 3, 3, 3, 3, 4, 3, 2, 0, 0, 1, 1, 0, 9, 1, 12, 0, 10, 1, 13, 14, 13, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 2, 3, 3, 3, 3, 3, 3, 4, 3, 2, 1, 1, 0, 0, 15, 15, 12, 14, 12, 15, 0, 0, 13, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 1, 0, 0, 1, 15, 0, 12, 1, 15, 0, 0, 15, 15, 0, 0, 1, 1, 0, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 2, 2, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 2, 3, 3, 3, 3, 3, 3, 3, 3, 2, 0, 0, 1, 1, 0, 0, 1, 15, 0, 0, 1, 1, 15, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 2, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {1, 1, 0, 0, 2, 3, 3, 3, 3, 3, 3, 3, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 3, 3, 3, 3, 4, 4, 4, 3, 2, 2, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 2, 3, 4, 3, 3, 3, 3, 4, 3, 2, 2, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 2, 3, 4, 3, 3, 3, 3, 3, 4, 3, 2, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 3, 3, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 3, 4, 3, 3, 2, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 2, 3, 4, 3, 3, 3, 3, 4, 4, 3, 2, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2, 3, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 3, 3, 3, 4, 3, 2, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {1, 1, 0, 0, 2, 3, 3, 4, 4, 4, 4, 4, 4, 3, 2, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 2, 3, 3, 3, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 4, 3, 3, 3, 3, 3, 3, 3, 2, 2, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 4, 3, 2, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 2, 3, 4, 3, 3, 4, 4, 3, 3, 3, 3, 3, 3, 3, 4, 3, 3, 3, 3, 3, 4, 3, 3, 2, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 2, 2, 3, 4, 3, 3, 3, 3, 3, 4, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 2, 3, 4, 3, 3, 3, 4, 4, 4, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 4, 3, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 1, 2, 3, 4, 3, 3, 3, 3, 3, 4, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 3, 4, 3, 3, 3, 3, 3, 4, 4, 3, 3, 3, 2, 4, 4, 3, 3, 3, 3, 3, 4, 4, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {1, 1, 0, 0, 1, 2, 3, 4, 3, 3, 3, 3, 3, 4, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 3, 3, 2, 2, 3, 3, 4, 4, 3, 3, 3, 3, 3, 4, 3, 2, 2, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 2, 3, 3, 4, 3, 3, 3, 3, 4, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 1, 2, 3, 3, 4, 3, 3, 3, 3, 3, 3, 4, 3, 2, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 0, 0, 2, 3, 4, 3, 3, 3, 3, 3, 3, 3, 2, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2, 3, 3, 3, 3, 3, 3, 3, 4, 3, 2, 0, 1, 1, 0, 2, 3, 3, 4, 3, 3, 3, 3, 4, 4, 3, 2, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 1, 1, 2, 3, 4, 3, 3, 3, 3, 3, 4, 3, 2, 1, 0, 0, 1, 1, 0, 0, 1, 2, 2, 3, 3, 3, 3, 3, 3, 4, 3, 2, 1, 1, 0, 0, 1, 1, 2, 3, 4, 4, 3, 3, 4, 4, 3, 4, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {1, 1, 0, 0, 1, 1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 3, 3, 2, 0, 0, 1, 1, 0, 0, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 3, 2, 1, 1, 0, 0, 1, 1, 2, 3, 3, 4, 4, 4, 3, 3, 3, 4, 2, 3, 2, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 2, 3, 4, 4, 4, 4, 3, 3, 4, 3, 3, 2, 2, 0, 0, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 3, 2, 1, 0, 0, 1, 1, 0, 0, 1, 2, 3, 3, 4, 3, 3, 3, 3, 4, 4, 3, 2, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 0, 0, 1, 2, 3, 3, 4, 3, 3, 3, 3, 4, 4, 3, 3, 3, 2, 2, 2, 2, 3, 3, 4, 4, 3, 3, 3, 4, 4, 3, 2, 1, 0, 0, 1, 1, 0, 0, 1, 2, 2, 3, 4, 3, 3, 3, 3, 3, 4, 3, 2, 1, 0, 0, 1, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 1, 1, 0, 2, 2, 3, 4, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3, 3, 4, 3, 4, 4, 4, 3, 4, 3, 3, 2, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2, 3, 4, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0},
    {1, 1, 0, 0, 1, 1, 0, 0, 2, 3, 4, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 4, 4, 4, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2, 3, 4, 3, 3, 3, 3, 3, 3, 4, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 3, 4, 3, 3, 3, 3, 3, 3, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 3, 3, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 2, 3, 4, 4, 3, 3, 3, 3, 4, 3, 3, 2, 0, 1, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 3, 3, 3, 3, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 3, 3, 2, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 2, 3, 2, 4, 3, 3, 3, 3, 4, 4, 3, 2, 0, 1, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 1, 1, 0, 0, 1, 2, 2, 3, 3, 4, 4, 3, 3, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 3, 3, 2, 2, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 4, 3, 3, 3, 3, 3, 4, 3, 2, 1, 0, 0, 1, 1, 0, 0},
    {1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 3, 2, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 3, 4, 4, 3, 3, 3, 3, 4, 3, 3, 2, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 2, 3, 3, 3, 4, 4, 3, 3, 3, 3, 4, 4, 3, 3, 3, 3, 2, 2, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 3, 2, 1, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2, 2, 2, 3, 3, 4, 4, 4, 4, 4, 3, 3, 2, 2, 2, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 2, 3, 4, 4, 3, 3, 3, 4, 4, 3, 2, 1, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2, 2, 3, 3, 3, 3, 3, 3, 3, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 2, 3, 3, 4, 3, 3, 3, 3, 4, 2, 3, 2, 0, 1, 1, 0, 0},
    {1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 2, 2, 3, 4, 3, 3, 3, 3, 4, 4, 3, 2, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 3, 4, 4, 3, 3, 3, 3, 4, 3, 2, 1, 0, 0, 1, 1},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 3, 4, 4, 3, 3, 3, 3, 4, 3, 2, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 16, 16, 16, 16, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 2, 3, 4, 3, 3, 3, 3, 4, 4, 3, 2, 1, 1, 0, 0},
    {1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 16, 16, 16, 17, 17, 16, 16, 16, 16, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 2, 3, 4, 4, 3, 3, 3, 4, 4, 3, 2, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 16, 16, 17, 17, 17, 17, 17, 17, 17, 16, 16, 16, 16, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 2, 3, 3, 4, 3, 3, 3, 3, 4, 3, 2, 0, 0, 1, 1},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 16, 16, 17, 17, 18, 18, 18, 18, 18, 17, 17, 17, 17, 16, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 9, 0, 0, 1, 10, 0, 0, 1, 1, 0, 0, 1, 1, 0, 2, 2, 3, 4, 3, 3, 3, 3, 4, 4, 3, 2, 0, 1, 1},
    {1, 1, 0, 0, 1, 21, 21, 21, 21, 16, 16, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 16, 16, 1, 0, 0, 1, 1, 0, 0, 1, 1, 9, 14, 9, 1, 10, 14, 10, 1, 13, 0, 1, 1, 0, 0, 1, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 3, 2, 1, 0, 0},
    {1, 1, 0, 0, 21, 22, 22, 22, 22, 21, 21, 17, 18, 18, 18, 18, 18, 20, 20, 20, 18, 18, 17, 17, 16, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 9, 1, 12, 0, 10, 1, 13, 14, 13, 1, 1, 0, 0, 1, 1, 2, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 2, 0, 0},
    {0, 0, 1, 21, 22, 22, 22, 22, 22, 22, 21, 17, 18, 18, 18, 18, 20, 20, 19, 19, 18, 18, 18, 17, 16, 0, 1, 1, 0, 0, 1, 1, 0, 0, 15, 15, 12, 14, 12, 15, 0, 0, 13, 1, 0, 0, 1, 1, 0, 0, 1, 2, 3, 4, 3, 3, 3, 3, 3, 4, 3, 2, 1, 1},
    {0, 0, 1, 21, 22, 22, 22, 22, 22, 22, 21, 18, 18, 18, 18, 18, 18, 20, 20, 20, 18, 18, 18, 17, 16, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 15, 0, 12, 1, 15, 0, 0, 15, 15, 0, 0, 1, 1, 0, 0, 1, 2, 3, 3, 4, 3, 3, 3, 3, 4, 3, 2, 1, 1},
    {1, 1, 0, 21, 22, 22, 22, 22, 22, 22, 21, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 16, 16, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 15, 0, 0, 1, 1, 15, 0, 1, 1, 0, 0, 1, 1, 0, 2, 2, 3, 4, 3, 3, 3, 3, 4, 3, 2, 0, 0},
        {1, 1, 0, 21, 21, 21, 22, 22, 22, 22, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 17, 16, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 15, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 2, 2, 3, 4, 3, 3, 3, 3, 4, 3, 2, 0, 0},
        {0, 0, 1, 1, 0, 16, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 16, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 3, 4, 3, 3, 3, 3, 4, 3, 2, 1, 1},
        {0, 0, 1, 1, 0, 16, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 16, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 3, 3, 3, 3, 3, 3, 4, 3, 2, 1, 1},
        {1, 1, 0, 0, 1, 16, 16, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 16, 16, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2, 2, 3, 3, 3, 3, 3, 4, 3, 3, 0, 0},
        {1, 1, 0, 0, 1, 1, 16, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 16, 16, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2, 2, 3, 3, 3, 3, 3, 4, 3, 2, 0, 0}
};
#endif /* map_h */
