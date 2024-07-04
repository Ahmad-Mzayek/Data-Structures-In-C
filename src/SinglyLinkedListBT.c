#include <stdio.h>
#include "Exceptions.h"
#include "SinglyLinkedListBT.h"

NodeSLLBT_t* newNodeSLLBT(const NodeBT_t* data, NodeSLLBT_t* const next)
{
    NodeSLLBT_t* newNode = (NodeSLLBT_t*)malloc(sizeof(NodeSLLBT_t));
    if (newNode == NULL)
        return NULL;
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

void destroySLLBT(NodeSLLBT_t** const pHead)
{
    while (!isSLLBTEmpty(*pHead))
    {
        NodeSLLBT_t* toDelete = *pHead;
        *pHead = (*pHead)->next;
        free(toDelete);
    }
    *pHead = NULL;
}

bool isSLLBTEmpty(const NodeSLLBT_t* const head)
{
    return head == NULL;
}

Exception_t insertHeadSLLBT(NodeSLLBT_t** const pHead, const NodeBT_t* newData)
{
    NodeSLLBT_t* newNode = newNodeSLLBT(newData, *pHead);
    if (newNode == NULL)
        return MEMORY_ALLOCATION_FAILURE_EXCEPTION;
    *pHead = newNode;
    return NO_EXCEPTION;
}

Exception_t insertTailSLLBT(NodeSLLBT_t** const pHead, const NodeBT_t* newData)
{
    if (isSLLBTEmpty(*pHead))
        return insertHeadSLLBT(pHead, newData);
    NodeSLLBT_t* current = *pHead;
    while (current->next != NULL)
        current = current->next;
    current->next = newNodeSLLBT(newData, NULL);
    return (current->next == NULL) ? MEMORY_ALLOCATION_FAILURE_EXCEPTION : NO_EXCEPTION;
}

Exception_t insertNodeSLLBT(NodeSLLBT_t** const pHead, const NodeBT_t* newData, const size_t position)
{
    if (position == 0U)
        return insertHeadSLLBT(pHead, newData);
    NodeSLLBT_t* current = *pHead;
    for (size_t i = 1U; i < position && current != NULL; ++i)
        current = current->next;
    if (current == NULL)
        return INVALID_ARGUMENT_EXCEPTION;
    current->next = newNodeSLLBT(newData, current->next);
    return (current->next == NULL) ? MEMORY_ALLOCATION_FAILURE_EXCEPTION : NO_EXCEPTION;
}

Exception_t deleteHeadSLLBT(NodeSLLBT_t** const pHead, NodeBT_t** const pDeletedData)
{
    if (isSLLBTEmpty(*pHead))
        return NULL_POINTER_ARGUMENT_EXCEPTION;
    NodeSLLBT_t* toDelete = *pHead;
    *pDeletedData = toDelete->data;
    *pHead = (*pHead)->next;
    free(toDelete);
    return NO_EXCEPTION;
}

Exception_t deleteTailSLLBT(NodeSLLBT_t** const pHead, NodeBT_t** const pDeletedData)
{
    if (isSLLBTEmpty(*pHead) || (*pHead)->next == NULL)
        return deleteHeadSLLBT(pHead, pDeletedData);
    NodeSLLBT_t* current = *pHead;
    while (current->next->next != NULL)
        current = current->next;
    *pDeletedData = current->next->data;
    free(current->next);
    current->next = NULL;
    return NO_EXCEPTION;
}

Exception_t deleteNodeSLLBT(NodeSLLBT_t** const pHead, NodeBT_t** const pDeletedData, const size_t position)
{
    if (isSLLBTEmpty(*pHead) || position == 0U)
        return deleteHeadSLLBT(pHead, pDeletedData);
    NodeSLLBT_t* current = *pHead;
    for (size_t i = 1U; i < position && current->next != NULL; ++i)
        current = current->next;
    if (current->next == NULL)
        return INVALID_ARGUMENT_EXCEPTION;
    NodeSLLBT_t* toDelete = current->next;
    *pDeletedData = toDelete->data;
    current->next = toDelete->next;
    free(toDelete);
    return NO_EXCEPTION;
}

void reverseSLLBT(NodeSLLBT_t** const pHead)
{
    if (isSLLBTEmpty(*pHead))
        return;
    NodeSLLBT_t* previous = *pHead;
    while ((*pHead)->next != NULL)
    {
        NodeSLLBT_t* next = (*pHead)->next;
        (*pHead)->next = next->next;
        next->next = previous;
        previous = next;
    }
    *pHead = previous;
}