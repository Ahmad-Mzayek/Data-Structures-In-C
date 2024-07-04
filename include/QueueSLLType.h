#ifndef __QUEUE_SLL_TYPE_H_
#define __QUEUE_SLL_TYPE_H_

#include "SinglyLinkedListType.h"

typedef struct QueueSLL_t
{
    NodeSLL_t* front;
    NodeSLL_t* rear;
} QueueSLL_t;

#endif // __QUEUE_SLL_TYPE_H_