//
//  update.h
//  Farm Defense
//
//  Created by Devaansh Gupta on 25/08/23.
//

#ifndef update_h
#define update_h

#include <stdio.h>

#include "types.h"

void updateDragNDrop(Plant_t* plant);

void updateRobots(App_t* game, LinkedList_t* robot_list);

void updatePlants(App_t* game);

void updateBullets(App_t* game);

void updateWaves(App_t* game);

#endif /* update_h */
