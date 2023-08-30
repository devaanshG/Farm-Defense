//
//  update.c
//  Farm Defense
//
//  Created by Devaansh Gupta on 25/08/23.
//

#include "update.h"
#include "types.h"
#include "utils.h"
#include "list.h"

void updateDragNDrop(Plant_t* plant) {
    int mouse_x, mouse_y;
    
    SDL_GetMouseState(&mouse_x, &mouse_y);
    
    plant->rect.x = mouse_x;
    plant->rect.y = mouse_y;
}

void updateWaves(App_t* game) {
    Node_t* wave_node = game->cur_wave;
    
        Wave_t* wave = (Wave_t*)wave_node->data;
        
        if (SDL_GetTicks() - wave->start_time >= wave->delay * wave->robot_num && wave->robot_num < wave->num_robots) {
            wave->robot_num++;
            
            printf("Robot Num: %d\n", wave->robot_num);
            
            Node_t* node = wave->robot_list->head;
            
            for (int i = 0; i < wave->robot_num - 1; i++) {
                if (node->next) {
                    node = node->next;
                }
            }
            
            Enemy_t* robot = (Enemy_t*)node->data;
            robot->update = true;
        }
        
        if (wave->robot_list->head == NULL) {
            if (wave_node->next != NULL) {
                game->cur_wave = wave_node->next;
                game->wave++;
                Wave_t* curWave = (Wave_t*)game->cur_wave->data;
                curWave->start_time = SDL_GetTicks();
            } else {
                printf("YOU WIN\n");
                return;
            }
        }
}

void updateRobots(App_t* game, LinkedList_t* robot_list) {
    bool delete = false;
    Node_t* curNode = robot_list->head;
    Node_t* nodeToDelete = NULL;
    
    Wave_t* cur_wave = (Wave_t*)game->cur_wave->data;
    
    int speed = cur_wave->speed;
    
    if (curNode->data == NULL) {
        return;
    }
    
    while(curNode != NULL) {
        Enemy_t* robot = (Enemy_t*)curNode->data;
        
        delete = false;
        
        if (robot->health <= 0) {
            delete = true;
            nodeToDelete = curNode;
            game->money += 100;
        } else if (robot->update == true) {
            switch (robot->path_section) {
                case 0:
                    if (robot->rect.y >= 270) {
                        robot->path_section++;
                        break;
                    }
                    robot->rect.y += TILE_SIZE / 4 * speed;
                    break;
                case 1:
                    robot->rect.x += TILE_SIZE / 8 * speed;
                    
//                    robot->rect.y = -0.009742 * pow((robot->rect.x - 212 + 30), 2) + 425 - 30;
                    
                    robot->rect.y = -0.0095*pow(robot->rect.x + 40, 2)+4.1*(robot->rect.x + 40)-26;
                    
                    if (robot->rect.x >= 310) {
                        robot->path_section++;
                    }
                    
                    break;
                case 2:
                    robot->rect.x += TILE_SIZE / 8 * speed;
                    
                    robot->rect.y = 0.0117*pow(robot->rect.x + 40, 2)-9.3*(robot->rect.x+40)+2092;
                    
                    if (robot->rect.y >= 600) {
                        delete = true;
                        
                        game->health -= robot->damage;
                        
                        nodeToDelete = curNode;
                    }
                    
                    break;
                default:
                    break;
            }
        }
        
        curNode = curNode->next;
        
        if (delete) {
            Wave_t* cur_wave = (Wave_t*)game->cur_wave->data;
            deleteNode(nodeToDelete, cur_wave->robot_list);
            printf("Deleting robot\n");
        }
    }
}

void updatePlants(App_t* game) {
    bool target = false;
    
    Wave_t* cur_wave = (Wave_t*)game->cur_wave->data;
    
    LinkedList_t* plant_list = game->plant_list;
    LinkedList_t* robot_list = cur_wave->robot_list;
    
    Node_t* curNode   = plant_list->head;
    
    if (curNode->data == NULL) {
        return;
    }
    
    while(curNode != NULL) {
        Plant_t* plant = (Plant_t*)curNode->data;
        
        Node_t* robotNode = robot_list->head;
        
        while (robotNode != NULL) {
            Enemy_t* robot = (Enemy_t*)robotNode->data;
            
            if (pow(robot->rect.x - plant->rect.x, 2) + pow(robot->rect.y - plant->rect.y, 2) < pow(200, 2)) {
                plant->target = robot;
                target = true;
            }
            
            robotNode = robotNode->next;
        }
        
        if (!target) {
            plant->target = NULL;
        }
        
        curNode = curNode->next;
    }
    
}

void updateBullets(App_t* game) {
    LinkedList_t* plant_list = game->plant_list;
    
    Node_t* curNode = plant_list->head;
    
    if (curNode->data == NULL) {
        return;
    }
    
    while(curNode != NULL) {
        Plant_t* plant = (Plant_t*)curNode->data;
        
        
     
            if (SDL_GetTicks() - plant->prev_shoot_time >= plant->cooldown_time && plant->target && plant->placed) {
                Bullet_t* bullet = (Bullet_t*)malloc(sizeof(Bullet_t));
                
                SDL_Surface* bulletSurf = IMG_Load("./assets.xcassets/bullet.imageset/Bullet (1).png");
                bullet->text = SDL_CreateTextureFromSurface(game->renderer, bulletSurf);
                SDL_FreeSurface(bulletSurf);
                
                bullet->rect.x = plant->rect.x + plant->rect.w / 2;
                bullet->rect.y = plant->rect.y + plant->rect.h / 2;
                
                bullet->rect.w = bullet->rect.h = 5;
                
                int d_x = plant->target->rect.x - bullet->rect.x;
                int d_y = plant->target->rect.y - bullet->rect.y;
                
                float mag = pow((d_x * d_x + d_y * d_y), 0.5);
                
                bullet->vel_x = d_x / mag;
                bullet->vel_y = d_y / mag;
                
                prepend(plant->bullet_list, bullet);
                
                plant->prev_shoot_time = SDL_GetTicks();
            }
        
            if (plant->bullet_list->head != NULL) {
                LinkedList_t* bullet_list = plant->bullet_list;
                Node_t* curNode           = bullet_list->head;
                Node_t* nodeToDelete      = NULL;
                
                bool delete = false;
                
                while (curNode != NULL) {
                    Bullet_t* bullet = (Bullet_t*)curNode->data;
                    
                    bullet->rect.x += bullet->vel_x * 30;
                    bullet->rect.y += bullet->vel_y * 30;
                    
                    if (plant->target) {
                        if (checkCollision(bullet->rect, plant->target->rect)) {
                            plant->target->health -= 40;
                            delete = true;
                            nodeToDelete = curNode;
                        }
                    }
                    
                    curNode = curNode->next;
                    
                    if (delete) {
                        deleteNode(nodeToDelete, bullet_list);
                    }
                }
            }
        
        curNode = curNode->next;
    }
}
