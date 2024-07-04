#include "QueueSLL.h"
#include "Exceptions.h"
#include "SinglyLinkedList.h"

QueueSLL_t newQueueSLL(void)
{
    QueueSLL_t newQueue;
    newQueue.front = NULL;
    newQueue.rear = NULL;
    return newQueue;
}

void destroyQueueSLL(QueueSLL_t* const pQueue)
{
    destroySLL(&(pQueue->front));
    pQueue->rear = NULL;
}

bool isQueueSLLEmpty(const QueueSLL_t queue)
{
    return isSLLEmpty(queue.front);
}

Exception_t enqueueQueueSLL(QueueSLL_t* const pQueue, const PrimitiveData_t newData)
{
    NodeSLL_t* newNode = newNodeSLL(newData, NULL);
    if (newNode == NULL)
        return MEMORY_ALLOCATION_FAILURE_EXCEPTION;
    if (isQueueSLLEmpty(*pQueue))
    {
        pQueue->front = newNode;
        pQueue->rear = newNode;
        return NO_EXCEPTION;
    }
    pQueue->rear->next = newNode;
    pQueue->rear = newNode;
    return NO_EXCEPTION;
}

Exception_t dequeueQueueSLL(QueueSLL_t* const pQueue, PrimitiveData_t* const pDequeuedData)
{
    if (isQueueSLLEmpty(*pQueue))
        return NULL_POINTER_ARGUMENT_EXCEPTION;
    NodeSLL_t* toDequeue = pQueue->front;
    pQueue->front = toDequeue->next;
    *pDequeuedData = toDequeue->data;
    free(toDequeue);
    if (pQueue->front == NULL)
        pQueue->rear = NULL;
    return NO_EXCEPTION;
}

Exception_t frontQueueSLL(const QueueSLL_t queue, PrimitiveData_t* const pFrontData)
{
    if (isQueueSLLEmpty(queue))
        return NULL_POINTER_ARGUMENT_EXCEPTION;
    *pFrontData = queue.front->data;
    return NO_EXCEPTION;
}