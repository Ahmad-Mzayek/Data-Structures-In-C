#ifndef __QUEUE_SLL_BT_H_
#define __QUEUE_SLL_BT_H_

#include <stdlib.h>
#include <stdbool.h>
#include "QueueSLLBTType.h"
#include "ExceptionsType.h"

QueueSLLBT_t newQueueSLLBT(void);

void destroyQueueSLLBT(QueueSLLBT_t* const pQueue);

bool isQueueSLLBTEmpty(const QueueSLLBT_t queue);

Exception_t enqueueQueueSLLBT(QueueSLLBT_t* const pQueue, const NodeBT_t* newData);

Exception_t dequeueQueueSLLBT(QueueSLLBT_t* const pQueue, NodeBT_t** const pDequeuedData);

Exception_t frontQueueSLLBT(const QueueSLLBT_t queue, NodeBT_t** const pFrontData);

#endif // __QUEUE_SLL_BT_H_