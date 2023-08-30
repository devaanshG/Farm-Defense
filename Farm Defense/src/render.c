//
//  render.c
//  Farm Defense
//
//  Created by Devaansh Gupta on 22/08/23.
//

#include <stdint.h>
#include <string.h>

#include "render.h"
#include "map.h"
#include "types.h"

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>


void renderMap(App_t* game){
    SDL_Surface* surf = IMG_Load("./assets.xcassets/map.imageset/td_map.png");  // Loads the PNG into an SDL_Surface, which stores image in regular memory
    SDL_Texture* text = SDL_CreateTextureFromSurface(game->renderer, surf);     // Converts the SDL_Surface to an SDL_Texture, which is now stored in graphics memory and can be use by the renderer
    
    SDL_FreeSurface(surf); // We no longer need the surface
    
    SDL_Rect rect = { // Rect to store x, y, w, h for the destination rect. The SDL_Texture will be projected onto the window using this destination rect.
        .x = 0,
        .y = 0,
        .w = 640,
        .h = 640,
    };
    
    SDL_RenderCopy(game->renderer, text, NULL, &rect); // Loading the texture onto the renderer back buffer, using the destination rect
    
    SDL_DestroyTexture(text);   // We also no longer need the texture, so we can destroy it
}

void renderMenu(App_t* game){
    
    // Render menu image
    {
        SDL_Surface* surf = IMG_Load("./assets.xcassets/menu.imageset/menu.png"); // Loads the PNG into an SDL_Surface, which stores image in regular memory
        SDL_Texture* texture = SDL_CreateTextureFromSurface(game->renderer, surf);   // Converts the SDL_Surface to an SDL_Texture, which is now stored in graphics memory and can be use by the renderer
        
        SDL_FreeSurface(surf); // We no longer need the surface
        
        SDL_Rect rect = { // Rect to store x, y, w, h for the destination rect. The SDL_Texture will be projected onto the window using this destination rect.
            .x = 0,
            .y = 640,
            .w = 640,
            .h = 320,
        };
        
        SDL_RenderCopy(game->renderer, texture, NULL, &rect); // Loading the texture onto the renderer back buffer, using the destination rect
        
        SDL_DestroyTexture(texture); // We also no longer need the texture, so we can destroy it
    }
    
    
    // Render wave text
    char* text;
    asprintf(&text, "Wave: ");
    SDL_Surface* textSurf = TTF_RenderText_Solid(game->font, text, (SDL_Colour){0, 0, 0, SDL_ALPHA_OPAQUE});
    
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(game->renderer, textSurf);
    
    SDL_Rect textRect = {
        .x = 545,
        .y = 133+640,
        .w = 0,
        .h = 0
    };
    
    TTF_SizeText(game->font, text, &textRect.w, &textRect.h);
    
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    
    SDL_RenderCopy(game->renderer, textTexture, NULL, &textRect);
    
    // Render wave number
    asprintf(&text, "%d", game->wave);
    textSurf = TTF_RenderText_Solid(game->font, text, (SDL_Colour){0, 0, 0});
    
    textTexture = SDL_CreateTextureFromSurface(game->renderer, textSurf);
    
    textRect = (SDL_Rect){
        .x = 545,
        .y = 153+640,
        .w = 0,
        .h = 0
    };
    
    TTF_SizeText(game->font, text, &textRect.w, &textRect.h);
    
    SDL_RenderCopy(game->renderer, textTexture, NULL, &textRect);
    
    // Render money text
    asprintf(&text, "Money: ");
    textSurf = TTF_RenderText_Solid(game->font, text, (SDL_Colour){0, 0, 0});
    
    textTexture = SDL_CreateTextureFromSurface(game->renderer, textSurf);
    
    textRect = (SDL_Rect){
        .x = 545,
        .y = 173+640,
        .w = 0,
        .h = 0
    };
    
    TTF_SizeText(game->font, text, &textRect.w, &textRect.h);
    
    SDL_RenderCopy(game->renderer, textTexture, NULL, &textRect);
    
    // Render money amount
    asprintf(&text, "$%d", game->money);
    textSurf = TTF_RenderText_Solid(game->font, text, (SDL_Colour){0, 0, 0});
    
    textTexture = SDL_CreateTextureFromSurface(game->renderer, textSurf);
    
    textRect = (SDL_Rect){
        .x = 545,
        .y = 193+640,
        .w = 0,
        .h = 0
    };
    
    TTF_SizeText(game->font, text, &textRect.w, &textRect.h);
    
    SDL_RenderCopy(game->renderer, textTexture, NULL, &textRect);
    
    // Render health text
    asprintf(&text, "Health: ");
    textSurf = TTF_RenderText_Solid(game->font, text, (SDL_Colour){0, 0, 0});
    
    textTexture = SDL_CreateTextureFromSurface(game->renderer, textSurf);
    
    textRect = (SDL_Rect){
        .x = 545,
        .y = 213+640,
        .w = 0,
        .h = 0
    };
    
    TTF_SizeText(game->font, text, &textRect.w, &textRect.h);
    
    SDL_RenderCopy(game->renderer, textTexture, NULL, &textRect);
    
    // Render health amount
    asprintf(&text, "%d", game->health);
    textSurf = TTF_RenderText_Solid(game->font, text, (SDL_Colour){0, 0, 0});
    
    textTexture = SDL_CreateTextureFromSurface(game->renderer, textSurf);
    
    textRect = (SDL_Rect){
        .x = 545,
        .y = 233+640,
        .w = 0,
        .h = 0
    };
    
    TTF_SizeText(game->font, text, &textRect.w, &textRect.h);
    
    SDL_RenderCopy(game->renderer, textTexture, NULL, &textRect);
    
    // Free memory
    free(text);
    SDL_FreeSurface(textSurf);
    SDL_DestroyTexture(textTexture);
}

void renderPlants(App_t* game) {
    LinkedList_t* plant_list = game->plant_list;
    
    if (plant_list->head != NULL) { // Check if the LinkedList even has any objects in it
        Node_t* current_node = plant_list->head; // Store the first node of the list, to be used as an iterator
        
        while (current_node != NULL) {
            Plant_t* plant = (Plant_t*)(current_node->data);
            
            SDL_RenderCopy(game->renderer, plant->text, NULL, &plant->rect);
            current_node = current_node->next;
        }
    }
}

void renderBullets(App_t* game) {
    LinkedList_t* plant_list = game->plant_list;
    
    if (plant_list->head != NULL) { // Check if the LinkedList even has any objects in it
        Node_t* current_node = plant_list->head; // Store the first node of the list, to be used as an iterator
        
        while (current_node != NULL) {
            Plant_t* plant = (Plant_t*)(current_node->data);
            
            if (plant->bullet_list->head != NULL) {
                LinkedList_t* bullet_list = plant->bullet_list;
                Node_t* curNode           = bullet_list->head;
                
                while (curNode != NULL) {
                    Bullet_t* bullet = (Bullet_t*)curNode->data;
                    
                    if (bullet != NULL) {
                        SDL_RenderCopy(game->renderer, bullet->text, NULL, &bullet->rect);
                    }
                    
                    curNode = curNode->next;
                }
            }
            
            current_node = current_node->next;
        }
    }
}

void renderEnemies(App_t* game) {
    Wave_t* cur_wave = (Wave_t*)game->cur_wave->data;
    
    LinkedList_t* enemy_list = cur_wave->robot_list;
    
    if (enemy_list->head != NULL) { // Check if the LinkedList even has any objects in it
        Node_t* current_node = enemy_list->head; // Store the first node of the list, to be used as an iterator
        
        while (current_node != NULL) {
            Enemy_t* enemy = (Enemy_t*)(current_node->data);
            
            SDL_RenderCopy(game->renderer, enemy->text, NULL, &enemy->rect);
            current_node = current_node->next;
        }
    }
}



void render(App_t* game) {
    renderMap(game);
    renderMenu(game);
    renderPlants(game);
    renderEnemies(game);
    renderBullets(game);
}

void drawMap(TileMap_t* tile_map, App_t* game) {
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            Tile_t tile = tile_map->map[i][j];
            
            SDL_Rect rect;

            rect.x = j * TILE_SIZE;
            rect.y = i * TILE_SIZE;
            rect.w = rect.h = TILE_SIZE;
            
            switch (tile.type) {
                case GRASS_DARK:
                    SDL_SetRenderDrawColor(game->renderer, 47, 200, 74, 255);
                    break;
                case GRASS_LIGHT:
                    SDL_SetRenderDrawColor(game->renderer, 117, 255, 98, 255);
                    break;
                case PATH_OUTLINE:
                    SDL_SetRenderDrawColor(game->renderer, 142, 147, 102, 255);
                    break;
                case PATH_FILL:
                    SDL_SetRenderDrawColor(game->renderer, 203, 211, 144, 255);
                    break;
                case PATH_DETAIL:
                    SDL_SetRenderDrawColor(game->renderer, 162, 170, 109, 255);
                    break;
                case GRASS_SHADOW_DARK:
                    SDL_SetRenderDrawColor(game->renderer, 60, 160, 78, 255);
                    break;
                case GRASS_SHADOW_LIGHT:
                    SDL_SetRenderDrawColor(game->renderer, 86, 188, 72, 255);
                    break;
                case CLIFF_DARK:
                    SDL_SetRenderDrawColor(game->renderer, 61, 52, 43, 255);
                    break;
                case CLIFF_LIGHT:
                    SDL_SetRenderDrawColor(game->renderer, 87, 75, 61, 255);
                    break;
                case FLOWER_DARK_BLUE:
                    SDL_SetRenderDrawColor(game->renderer, 25, 97, 127, 255);
                    break;
                case FLOWER_LIGHT_BLUE:
                    SDL_SetRenderDrawColor(game->renderer, 97, 225, 228, 255);
                    break;
                case FLOWER_WHITE:
                    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
                    break;
                case FLOWER_PINK:
                    SDL_SetRenderDrawColor(game->renderer, 217, 127, 127, 255);
                    break;
                case FLOWER_CENTER:
                    SDL_SetRenderDrawColor(game->renderer, 226, 194, 52, 255);
                    break;
                case FLOWER_STEM:
                    SDL_SetRenderDrawColor(game->renderer, 60, 224, 26, 255);
                    break;
                case POND_OUTLINE:
                    SDL_SetRenderDrawColor(game->renderer, 102, 78, 49, 255);
                    break;
                case POND_LIGHT:
                    SDL_SetRenderDrawColor(game->renderer, 97, 225, 228, 255);
                    break;
                case POND_DARK:
                    SDL_SetRenderDrawColor(game->renderer, 73, 195, 198, 255);
                    break;
                case LILY_DARK:
                    SDL_SetRenderDrawColor(game->renderer, 60, 160, 78, 255);
                    break;
                case LILY_LIGHT:
                    SDL_SetRenderDrawColor(game->renderer, 86, 188, 72, 255);
                    break;
                case ROCK_OUTLINE:
                    SDL_SetRenderDrawColor(game->renderer, 179, 179, 179, 255);
                    break;
                case ROCK_FILL:
                    SDL_SetRenderDrawColor(game->renderer, 190, 190, 190, 255);
                    break;
                default:
                    break;
            }
            
            SDL_RenderFillRect(game->renderer, &rect);
        }
    }
}
