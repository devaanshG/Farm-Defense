//
//  setup.h
//  Farm Defense
//
//  Created by Devaansh Gupta on 21/08/23.
//

#ifndef setup_h
#define setup_h

#include <stdio.h>
#include <stdint.h>

#include "types.h"


// Set up the window and renderer. Initialise SDL2.
App_t* setup(int WIN_SIZE);


// Create a tilemap based on an input array of integers. Refer to map.h to understand what the integer representation of the map looks like.
TileMap_t* loadMap(const uint32_t map[64][64], int width, int height) ;


Menu_t* loadMenu(void);

void createEnemy(App_t* game, Wave_t* wave);

#endif /* setup_h */
