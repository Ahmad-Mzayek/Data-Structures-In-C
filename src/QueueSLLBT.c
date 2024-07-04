#include "Exceptions.h"
#include "QueueSLLBT.h"
#include "SinglyLinkedListBT.h"

QueueSLLBT_t newQueueSLLBT(void)
{
    QueueSLLBT_t newQueue;
    newQueue.front = NULL;
    newQueue.rear = NULL;
    return newQueue;
}

void destroyQueueSLLBT(QueueSLLBT_t* const pQueue)
{
    destroySLLBT(&(pQueue->front));
    pQueue->rear = NULL;
}

bool isQueueSLLBTEmpty(const QueueSLLBT_t queue)
{
    return isSLLBTEmpty(queue.front);
}

Exception_t enqueueQueueSLLBT(QueueSLLBT_t* const pQueue, const NodeBT_t* newData)
{
    NodeSLLBT_t* newNode = newNodeSLLBT(newData, NULL);
    if (newNode == NULL)
        return MEMORY_ALLOCATION_FAILURE_EXCEPTION;
    if (isQueueSLLBTEmpty(*pQueue))
    {
        pQueue->front = newNode;
        pQueue->rear = newNode;
        return NO_EXCEPTION;
    }
    pQueue->rear->next = newNode;
    pQueue->rear = newNode;
    return NO_EXCEPTION;
}

Exception_t dequeueQueueSLLBT(QueueSLLBT_t* const pQueue, NodeBT_t** const pDequeuedData)
{
    if (isQueueSLLBTEmpty(*pQueue))
        return NULL_POINTER_ARGUMENT_EXCEPTION;
    NodeSLLBT_t* toDequeue = pQueue->front;
    pQueue->front = toDequeue->next;
    *pDequeuedData = toDequeue->data;
    free(toDequeue);
    if (pQueue->front == NULL)
        pQueue->rear = NULL;
    return NO_EXCEPTION;
}

Exception_t frontQueueSLLBT(const QueueSLLBT_t queue, NodeBT_t** const pFrontData)
{
    if (isQueueSLLBTEmpty(queue))
        return NULL_POINTER_ARGUMENT_EXCEPTION;
    *pFrontData = queue.front->data;
    return NO_EXCEPTION;
}