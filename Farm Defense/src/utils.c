//
//  utils.c
//  Farm Defense
//
//  Created by Devaansh Gupta on 28/08/23.
//

#include "utils.h"

#include <stdbool.h>

bool checkCollision(SDL_Rect rect1, SDL_Rect rect2) {
    if (rect1.x + rect1.w >= rect2.x && rect1.x <= rect2.x + rect2.w && rect1.y + rect1.h >= rect2.y && rect1.y <= rect2.y + rect2.h) {
        return true;
    } else {
        return false;
    }
}
