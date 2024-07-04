#ifndef __BINARY_TREE_H_
#define __BINARY_TREE_H_

#include <stdlib.h>
#include "ExceptionsType.h"
#include "BinaryTreeType.h"

NodeBT_t* newNodeBT(const PrimitiveData_t newData, NodeBT_t* const left, NodeBT_t* const right);

void destroyBT(NodeBT_t** const pRoot);

size_t getNbNodes(const NodeBT_t* const root);

size_t getNbLevels(const NodeBT_t* const root);

size_t getNbLeaves(const NodeBT_t* const root);

Exception_t preOrderBT(const NodeBT_t* const root, PrimitiveData_t** const pDataArray, size_t* const pNbNodes);

Exception_t inOrderBT(const NodeBT_t* const root, PrimitiveData_t** const pDataArray, size_t* const pNbNodes);

Exception_t postOrderBT(const NodeBT_t* const root, PrimitiveData_t** const pDataArray, size_t* const pNbNodes);

Exception_t levelOrderBT(const NodeBT_t* const root, PrimitiveData_t** const pDataArray, size_t* const pNbNodes);

#endif // __BINARY_TREE_H_