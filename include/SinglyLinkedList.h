#ifndef __SINGLY_LINKED_LIST_H_
#define __SINGLY_LINKED_LIST_H_

#include <stdlib.h>
#include "ExceptionsType.h"
#include "SinglyLinkedListType.h"

NodeSLL_t* newNodeSLL(const PrimitiveData_t data, NodeSLL_t* const next);

void destroySLL(NodeSLL_t** const pHead);

bool isSLLEmpty(const NodeSLL_t* const head);

Exception_t insertHeadSLL(NodeSLL_t** const pHead, const PrimitiveData_t newData);

Exception_t insertTailSLL(NodeSLL_t** const pHead, const PrimitiveData_t newData);

Exception_t insertNodeSLL(NodeSLL_t** const pHead, const PrimitiveData_t newData, const size_t position);

Exception_t deleteHeadSLL(NodeSLL_t** const pHead, PrimitiveData_t* pDeletedData);

Exception_t deleteTailSLL(NodeSLL_t** const pHead, PrimitiveData_t* pDeletedData);

Exception_t deleteNodeSLL(NodeSLL_t** const pHead, PrimitiveData_t* pDeletedData, const size_t position);

void reverseSLL(NodeSLL_t** const pHead);

#endif // __SINGLY_LINKED_LIST_H_