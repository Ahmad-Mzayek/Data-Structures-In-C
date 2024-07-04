#include <stdio.h>
#include "TextColors.h"
#include "Exceptions.h"
#include "SinglyLinkedList.h"

NodeSLL_t* newNodeSLL(const PrimitiveData_t data, NodeSLL_t* const next)
{
    NodeSLL_t* newNode = (NodeSLL_t*)malloc(sizeof(NodeSLL_t));
    if (newNode == NULL)
        return NULL;
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

void destroySLL(NodeSLL_t** const pHead)
{
    while (!isSLLEmpty(*pHead))
    {
        NodeSLL_t* toDelete = *pHead;
        *pHead = (*pHead)->next;
        free(toDelete);
    }
    *pHead = NULL;
}

bool isSLLEmpty(const NodeSLL_t* const head)
{
    return head == NULL;
}

Exception_t insertHeadSLL(NodeSLL_t** const pHead, const PrimitiveData_t newData)
{
    NodeSLL_t* newNode = newNodeSLL(newData, *pHead);
    if (newNode == NULL)
        return MEMORY_ALLOCATION_FAILURE_EXCEPTION;
    *pHead = newNode;
    return NO_EXCEPTION;
}

Exception_t insertTailSLL(NodeSLL_t** const pHead, const PrimitiveData_t newData)
{
    if (isSLLEmpty(*pHead))
        return insertHeadSLL(pHead, newData);
    NodeSLL_t* current = *pHead;
    while (current->next != NULL)
        current = current->next;
    current->next = newNodeSLL(newData, NULL);
    return (current->next == NULL) ? MEMORY_ALLOCATION_FAILURE_EXCEPTION : NO_EXCEPTION;
}

Exception_t insertNodeSLL(NodeSLL_t** const pHead, const PrimitiveData_t newData, const size_t position)
{
    if (position == 0U)
        return insertHeadSLL(pHead, newData);
    NodeSLL_t* current = *pHead;
    for (size_t i = 1U; i < position && current != NULL; ++i)
        current = current->next;
    if (current == NULL)
        return INVALID_ARGUMENT_EXCEPTION;
    current->next = newNodeSLL(newData, current->next);
    return (current->next == NULL) ? MEMORY_ALLOCATION_FAILURE_EXCEPTION : NO_EXCEPTION;
}

Exception_t deleteHeadSLL(NodeSLL_t** const pHead, PrimitiveData_t* const pDeletedData)
{
    if (isSLLEmpty(*pHead))
        return NULL_POINTER_ARGUMENT_EXCEPTION;
    NodeSLL_t* toDelete = *pHead;
    *pDeletedData = toDelete->data;
    *pHead = (*pHead)->next;
    free(toDelete);
    return NO_EXCEPTION;
}

Exception_t deleteTailSLL(NodeSLL_t** const pHead, PrimitiveData_t* const pDeletedData)
{
    if (isSLLEmpty(*pHead) || (*pHead)->next == NULL)
        return deleteHeadSLL(pHead, pDeletedData);
    NodeSLL_t* current = *pHead;
    while (current->next->next != NULL)
        current = current->next;
    *pDeletedData = current->next->data;
    free(current->next);
    current->next = NULL;
    return NO_EXCEPTION;
}

Exception_t deleteNodeSLL(NodeSLL_t** const pHead, PrimitiveData_t* const pDeletedData, const size_t position)
{
    if (isSLLEmpty(*pHead) || position == 0U)
        return deleteHeadSLL(pHead, pDeletedData);
    NodeSLL_t* current = *pHead;
    for (size_t i = 1U; i < position && current->next != NULL; ++i)
        current = current->next;
    if (current->next == NULL)
        return INVALID_ARGUMENT_EXCEPTION;
    NodeSLL_t* toDelete = current->next;
    *pDeletedData = toDelete->data;
    current->next = toDelete->next;
    free(toDelete);
    return NO_EXCEPTION;
}

void reverseSLL(NodeSLL_t** const pHead)
{
    if (isSLLEmpty(*pHead))
        return;
    NodeSLL_t* previous = *pHead;
    while ((*pHead)->next != NULL)
    {
        NodeSLL_t* next = (*pHead)->next;
        (*pHead)->next = next->next;
        next->next = previous;
        previous = next;
    }
    *pHead = previous;
}