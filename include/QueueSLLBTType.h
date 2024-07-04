#ifndef __QUEUE_SLL_BT_TYPE_H_
#define __QUEUE_SLL_BT_TYPE_H_

#include "SinglyLinkedListBTType.h"

typedef struct QueueSLLBT_t
{
    NodeSLLBT_t* front;
    NodeSLLBT_t* rear;
} QueueSLLBT_t;

#endif // __QUEUE_SLL_BT_TYPE_H_