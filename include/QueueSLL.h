#ifndef __QUEUE_SLL_H_
#define __QUEUE_SLL_H_

#include <stdlib.h>
#include <stdbool.h>
#include "QueueSLLType.h"
#include "ExceptionsType.h"

QueueSLL_t newQueueSLL(void);

void destroyQueueSLL(QueueSLL_t* const pQueue);

bool isQueueSLLEmpty(const QueueSLL_t queue);

Exception_t enqueueQueueSLL(QueueSLL_t* const pQueue, const PrimitiveData_t newData);

Exception_t dequeueQueueSLL(QueueSLL_t* const pQueue, PrimitiveData_t* const pDequeuedData);

Exception_t frontQueueSLL(const QueueSLL_t queue, PrimitiveData_t* const pFrontData);

#endif // __QUEUE_SLL_H_