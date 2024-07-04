#ifndef __SINGLY_LINKED_LIST_BT_H_
#define __SINGLY_LINKED_LIST_BT_H_

#include <stdlib.h>
#include "ExceptionsType.h"
#include "SinglyLinkedListBTType.h"

NodeSLLBT_t* newNodeSLLBT(const NodeBT_t* data, NodeSLLBT_t* const next);

void destroySLLBT(NodeSLLBT_t** const pHead);

bool isSLLBTEmpty(const NodeSLLBT_t* const head);

Exception_t insertHeadSLLBT(NodeSLLBT_t** const pHead, const NodeBT_t* newData);

Exception_t insertTailSLLBT(NodeSLLBT_t** const pHead, const NodeBT_t* newData);

Exception_t insertNodeSLLBT(NodeSLLBT_t** const pHead, const NodeBT_t* newData, const size_t position);

Exception_t deleteHeadSLLBT(NodeSLLBT_t** const pHead, NodeBT_t** pDeletedData);

Exception_t deleteTailSLLBT(NodeSLLBT_t** const pHead, NodeBT_t** pDeletedData);

Exception_t deleteNodeSLLBT(NodeSLLBT_t** const pHead, NodeBT_t** pDeletedData, const size_t position);

void reverseSLLBT(NodeSLLBT_t** const pHead);

#endif // __SINGLY_LINKED_LIST_BT_H_