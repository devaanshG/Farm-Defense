/*
  list.c
  Farm Defense
  Generic doubly-linked list implementation. Basic functionality such as adding an item, removing an item, finding an item, etc.
  Created by Devaansh Gupta on 21/08/23.
*/

#include "list.h"
#include "types.h"

Node_t* makeNode(void* data);

LinkedList_t* initList(size_t data_size) {
    LinkedList_t* list = (LinkedList_t*)malloc(sizeof(LinkedList_t));
    
    list->head = NULL;
    list->data_size = data_size;
    
    return list;
}

Node_t* makeNode(void* data) {
    Node_t* node = (Node_t*)malloc(sizeof(Node_t));
    
    node->data = data;
    node->next = NULL;
    
    return node;
}

Node_t* prepend(LinkedList_t* list, void* data) {
    Node_t* node = makeNode(data);
    
    if (list->head == NULL) {
        list->head = node;
    } else {
        node->next = list->head;
        list->head = node;
    }
    
    return node;
}

Node_t* append(LinkedList_t* list, void* data) {
    Node_t* node = makeNode(data);
    
    if (list->head == NULL) {
        list->head = node;
    } else {
        // Go to the last element of the list
        Node_t* curNode = list->head;
        
        while (curNode->next != NULL) {
            curNode = curNode->next;
        }
        
        curNode->next = node;
    }
    
    return node;
}

void deleteNode(Node_t* node, LinkedList_t* list) {
    if (list->head == NULL) {
        return;
    }
    
    if (list->head == node) {   // Case 1: if the node we're looking for is the head
        list->head = node->next; // Set the list's head to the node after the one we're looking for
        
        free(node->data);   // Free the memory alloated for the data in the current node
        node->data = NULL;
        node->next = NULL;
        free(node);         // Free the memory allocated for the node itself
        
        return;
    } else {    // Case 2: if the node we're looking for is in between two other nodes OR the last node in the list
        Node_t* cur = list->head;
        Node_t* prev;
        Node_t* next = cur->next;
        
        while (next != NULL) { // Loop until we are at the node before the one we want
            if (next == node) {
                prev = cur;         // The node behind the node we're looking for
                cur = cur->next;    // The node after the node we're looking for
                next = cur->next;         // The node we're looking for
                
                prev->next = next;  // Establish the link between the nodes before and after the node we're looking for
                
                free(node->data);   // Free the memory alloated for the data in the current node
                node->data = NULL;
                node->next = NULL;
                free(node);         // Free the memory allocated for the node itself
                
                return;
            } else {
                cur = cur->next;    // Move to the next node
                next = cur->next;   // Update the 'next' node accordingly
            }
        }
    }
}

void linkedListTest(void) {
    LinkedList_t* list = initList(sizeof(Plant_t));
    
    for (int i = 0; i < 5; i++) {
        Plant_t* plant = (Plant_t*)malloc(sizeof(plant));
        prepend(list, (void*)plant);
    }
    
}
