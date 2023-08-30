//
//  render.h
//  Farm Defense
//
//  Created by Devaansh Gupta on 22/08/23.
//

#ifndef render_h
#define render_h

#include <stdio.h>
#include <stdint.h>

#include "types.h"

#include <SDL2/SDL.h>

void render(App_t* game);

void renderMap(App_t* game);
void renderMenu(App_t* game);
void renderPlants(App_t* game);
void renderEnemies(App_t* game);

void drawMap(TileMap_t* tile_map, App_t* game);

#endif /* render_h */
