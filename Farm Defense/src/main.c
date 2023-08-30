//
//  main.c
//  Farm Defense
//
//  Created by Devaansh Gupta on 18/08/23.
//

// C Libs
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

// Custom libs
#include "map.h"
#include "types.h"
#include "setup.h"
#include "render.h"
#include "input.h"
#include "list.h"
#include "update.h"

// 3rd Party Libraries
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

int main(int argc, const char * argv[]) {
    // Call setup function that initialises 3rd party libraries, and creates window, renderer, etc.
    // Objects such as window, renderer are store in the 'game' struct, which is an App_t (see types.h)
    App_t* game = setup(WIN_SIZE);

    game->tile_map = loadMap(map, 64, 64); // Creates a tile map based on the 2D integer array specified in map.h
     
    Menu_t* menu = loadMenu();                  // Sets up the menu, with the grid system of Slot_t's, that individually store a particular plant that can be placed
    
    // Main game loop
    SDL_Event event;               // SDL_Event to store any incoming user input events
    bool running = true;           // boolean value for specifying whether the game is in a 'running' state
    bool dragging = false;         // boolean value that specifies whether an item is being drag and dropepd
    
    Node_t* drag_n_drop = NULL;   // Initialising the Plant_t* to a NULL value. Will be populated with a Plant_t later, if a user attempts to drag and drop a plant onto the map
    
    while (running) {      // The main game loop. Keeps running until bool running is set to false
        // Handle input events
        while (SDL_PollEvent(&event)) { // Updates SDL_Event event for information on all input events
            switch(event.type) { // checking the event type
                case SDL_QUIT:
                    // When user attempts to close the window
                    running = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    // Update drag and drop, in case of a left click
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        drag_n_drop = checkMenu(game, &event, menu);
                        if (drag_n_drop != NULL) {
                            dragging = true;
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    dragging = false;
                    
                    // If there is a plant was being drag and dropped from the store
                    if (drag_n_drop != NULL) {
                        if (!placeSprite(game, drag_n_drop)) {
                            deleteNode(drag_n_drop, game->plant_list);
                        }
                    }
                    
                    drag_n_drop = NULL;
                    break;
                default:
                    // Other input handling
                    break;
            }
        }
        
        // Update game
    
            // Update the drag and drop if the dragging state is set to true
        if (dragging) {
            updateDragNDrop((Plant_t*)drag_n_drop->data);
        }

            // Update robots (enemies) if there are any to update
        Wave_t* wave = (Wave_t*)game->cur_wave->data;
        if (wave->robot_list->head != NULL) {
            updateRobots(game, wave->robot_list);
        }
            // Update plants if there are any to update
        if (game->plant_list->head != NULL) {
            updatePlants(game);
            updateBullets(game);
        }
        
        if (game->wave_list->head != NULL) {
            updateWaves(game);
        }
        
        // Render
        SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
        SDL_RenderClear(game->renderer); // Clear the renderer
        
        render(game); // Loads all necessary items into the renderer's back buffer
        
        SDL_RenderPresent(game->renderer); // Swaps the renderers back buffer and front buffer. I.e. displays the things in the renderer's back buffer on the window
    }
    
    // Clean up
    SDL_DestroyWindow(game->window);
    SDL_DestroyRenderer(game->renderer);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    
    return 0;
}
