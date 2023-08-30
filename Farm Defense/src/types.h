//
//  types.h
//  Farm Defense
//
//  Created by Devaansh Gupta on 21/08/23.
//

#ifndef types_h
#define types_h

#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

static const int WIN_SIZE = 640;                // The size in pixels of the window. The window is a square so we don't need separate w and h
static const int TILE_SIZE = WIN_SIZE / 64;     // The size in pixels of an individual tile. Allows for easy scaling based on how many tiles (64) are in each direction. Tiles are also square, so we don't need separate w and h

typedef struct Node {
    void* data;             // A pointer to the data stored in this node. a void* is used so that this node could store any data type
    struct Node* next;      // Pointer to the next node in the list. Allows for traversal through the list
} Node_t;

typedef struct LinkedList {
    Node_t* head;           // Pointer to the first Node_t in the linked list (head)
    size_t data_size;       // Size, in bytes, of the data type this linked list will store. E.g. a list of ints will have data_size of 4 bytes
} LinkedList_t;

typedef struct Tile {
    int type;       // Type of tile. Refer to MAP_KEY in map.h
    SDL_Rect rect;  // SDL_Rect for drawing on screen, storing width, height, x, y
    SDL_Color col;
    int idx_x;      // X index of the tile. Not to be confused with the x coordinate
    int idx_y;      // Y index of the tile. Not to be confused with the y coordinate
    bool populated; // Whether the tile has a sprite on it or not
    bool placeable; // Whether it is allowed for a sprite to be placed on this tile
} Tile_t;

typedef struct TileMap {
    Tile_t** map;           // 2D array of Tile_t structs
    unsigned int cols;      // How many columns of tiles there are
    unsigned int rows;      // How many rows of tile there ares
} TileMap_t;

typedef struct Bullet {
    int type;
    SDL_Texture* text;
    SDL_Rect rect;
    float vel_x;
    float vel_y;
} Bullet_t;

typedef struct Enemy {
    bool update;
    int path_section;
    int type;
    int health;
    int damage;
    SDL_Rect rect;
    SDL_Texture* text;
} Enemy_t;

typedef struct Plant {
    bool placed;
    int cost;
    int type;               // Type of plant (carrot, tree, mushroom, etc.)
    SDL_Rect rect;          // SDL_Rect to store x, y, w, h
    SDL_Texture* text;      // SDL_Texture to store PNG texture
    int angle;              // Angle the Plant_t is facing
    Enemy_t* target;        // Pointer to the enemy currently being targeted
    LinkedList_t* bullet_list;   // Linked list of the bullets the plant shot
    int cooldown_time;      // How long a cooldown lasts
    int prev_shoot_time;    // The timestamp of the previous shot (to calculte how much cooldown remains)
} Plant_t;

typedef struct Slot {
    int plant_type;         // Type of plant this is displayingß
    SDL_Rect rect;          // Rect to store x, y, w, h
} Slot_t;

typedef struct Menu {
    Slot_t grid[2][3];      // 2D Array of Slot_t that form the grid. Fixed width and length currently
    int money;              // The amount of money the player has.
    int wave;               // The wave number the player is on.
} Menu_t;

typedef struct Wave {
    LinkedList_t* robot_list;   // Linked list that stores the robots in this wave
    int robot_num;              // The robot we are currently on
    int num_robots;             // Maximum number of robots in this wave
    int start_time;             // Time when wave began, for timing of robots spawning
    int delay;                  // Delay between robots spawning
    int health;                 // Health robots will spawn in with
    int speed;                  // Speed multiplier of robots
} Wave_t;

typedef struct App {
    int wave;
    int money;
    int health;
    SDL_Window* window;         // Window handle
    SDL_Renderer* renderer;     // Renderer handle
    LinkedList_t* plant_list;   // Linked list of all plants (defenders) in the game. Includes the drag and drop plant.
//    LinkedList_t* robot_list;   // Linked list of all robots
    LinkedList_t* bullet_list;  // Linked list of all robots
    LinkedList_t* wave_list;    // Linked list of all waves
    Node_t* cur_wave;           // Node_t object to store current wave
    TileMap_t* tile_map;        // Tile map
    TTF_Font* font;             // The font (for SDL_TTF)
} App_t;

#endif /* types_h */
