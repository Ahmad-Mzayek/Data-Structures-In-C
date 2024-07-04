#ifndef __SINGLY_LINKED_LIST_BT_TYPE_H_
#define __SINGLY_LINKED_LIST_BT_TYPE_H_

#include "BinaryTreeType.h"

typedef struct NodeSLLBT_t
{
    NodeBT_t* data;
    struct NodeSLLBT_t* next;
} NodeSLLBT_t;

#endif // __SINGLY_LINKED_LIST_BT_TYPE_H_