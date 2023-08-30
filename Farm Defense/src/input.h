//
//  input.h
//  Farm Defense
//
//  Created by Devaansh Gupta on 24/08/23.
//

#ifndef input_h
#define input_h

#include <stdio.h>

#include "types.h"

#include <SDL2/SDL.h>

Node_t* checkMenu(App_t* game, SDL_Event* event, Menu_t* menu);

bool placeSprite(App_t* game, Node_t* plant_node);
 
#endif /* input_h */
