#ifndef __SINGLY_LINKED_LIST_TYPE_H_
#define __SINGLY_LINKED_LIST_TYPE_H_

#include "PrimitiveDataType.h"

typedef struct NodeSLL_t
{
    PrimitiveData_t data;
    struct NodeSLL_t* next;
} NodeSLL_t;

#endif // __SINGLY_LINKED_LIST_TYPE_H_