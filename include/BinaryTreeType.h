#ifndef __BINARY_TREE_TYPE_H_
#define __BINARY_TREE_TYPE_H_

#include "PrimitiveDataType.h"
#define MAXIMUM_NB_NODES (size_t)256

typedef struct NodeBT_t
{
    PrimitiveData_t data;
    struct NodeBT_t* left;
    struct NodeBT_t* right;
} NodeBT_t;

#endif // __BINARY_TREE_TYPE_H_