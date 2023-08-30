//
//  list.h
//  Farm Defense
//
//  Created by Devaansh Gupta on 21/08/23.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include "types.h"

LinkedList_t* initList(size_t data_size);

Node_t* prepend(LinkedList_t* list, void* data);

Node_t* append(LinkedList_t* list, void* data);

void deleteNode(Node_t* node, LinkedList_t* list);

void linkedListTest(void);

#endif /* list_h */
