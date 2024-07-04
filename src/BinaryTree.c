#include "Exceptions.h"
#include "BinaryTree.h"
#include "QueueSLLBT.h"
#include "StackSLLBT.h"

NodeBT_t* newNodeBT(const PrimitiveData_t newData, NodeBT_t* const left, NodeBT_t* const right)
{
    NodeBT_t* newNode = (NodeBT_t*)malloc(sizeof(NodeBT_t));
    if (newNode == NULL)
        return NULL;
    newNode->data = newData;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

void destroyBT(NodeBT_t** const pRoot)
{
    if (*pRoot == NULL)
        return;
    destroyBT(&((*pRoot)->left));
    destroyBT(&((*pRoot)->right));
    free(*pRoot);
    *pRoot = NULL;
}

size_t getNbNodes(const NodeBT_t* const root)
{
    if (root == NULL)
        return 0U;
    return getNbNodes(root->left) + getNbNodes(root->right) + 1U;
}

static inline size_t maxSizeT(const size_t a, const size_t b)
{
    return (a > b) ? a : b;
}

size_t getNbLevels(const NodeBT_t* const root)
{
    if (root == NULL)
        return 0U;
    return maxSizeT(getNbLevels(root->left), getNbLevels(root->right)) + 1U;
}

size_t getNbLeaves(const NodeBT_t* const root)
{
    if (root == NULL)
        return 0U;
    if (root->left == NULL && root->right == NULL)
        return 1U;
    return getNbLeaves(root->left) + getNbLeaves(root->right);
}

Exception_t preOrderBT(const NodeBT_t* const root, PrimitiveData_t** const pDataArray, size_t* const pNbNodes)
{
    if (root == NULL)
    {
        *pDataArray = NULL;
        *pNbNodes = 0U;
        return NO_EXCEPTION;
    }
    PrimitiveData_t* dataArray = (PrimitiveData_t*)malloc(MAXIMUM_NB_NODES * sizeof(PrimitiveData_t));
    if (dataArray == NULL)
        return MEMORY_ALLOCATION_FAILURE_EXCEPTION;
    StackSLLBT_t stack = newStackSLLBT();
    pushStackSLLBT(&stack, root);
    size_t nbNodes = 0U;
    while (!isStackSLLBTEmpty(stack))
    {
        NodeBT_t* popped;
        popStackSLLBT(&stack, &popped);
        dataArray[nbNodes++] = popped->data;
        if (popped->right != NULL)
            pushStackSLLBT(&stack, popped->right);
        if (popped->left != NULL)
            pushStackSLLBT(&stack, popped->left);
    }
    destroyStackSLLBT(&stack);
    dataArray = (PrimitiveData_t*)realloc(dataArray, nbNodes * sizeof(PrimitiveData_t));
    *pDataArray = dataArray;
    *pNbNodes = nbNodes;
    return NO_EXCEPTION;
}

Exception_t inOrderBT(const NodeBT_t* const root, PrimitiveData_t** const pDataArray, size_t* const pNbNodes)
{
    if (root == NULL)
    {
        *pDataArray = NULL;
        *pNbNodes = 0U;
        return NO_EXCEPTION;
    }
    PrimitiveData_t* dataArray = (PrimitiveData_t*)malloc(MAXIMUM_NB_NODES * sizeof(PrimitiveData_t));
    if (dataArray == NULL)
        return MEMORY_ALLOCATION_FAILURE_EXCEPTION;
    StackSLLBT_t stack = newStackSLLBT();
    size_t nbNodes = 0U;
    const NodeBT_t* current = root;
    while (!isStackSLLBTEmpty(stack) || current != NULL)
    {
        if (current != NULL)
        {
            pushStackSLLBT(&stack, current);
            current = current->left;
            continue;
        }
        NodeBT_t* popped;
        popStackSLLBT(&stack, &popped);
        dataArray[nbNodes++] = popped->data;
        current = popped->right;
    }
    destroyStackSLLBT(&stack);
    dataArray = (PrimitiveData_t*)realloc(dataArray, nbNodes * sizeof(PrimitiveData_t));
    *pDataArray = dataArray;
    *pNbNodes = nbNodes;
    return NO_EXCEPTION;
}

Exception_t postOrderBT(const NodeBT_t* const root, PrimitiveData_t** const pDataArray, size_t* const pNbNodes)
{
    if (root == NULL)
    {
        *pDataArray = NULL;
        *pNbNodes = 0U;
        return NO_EXCEPTION;
    }
    PrimitiveData_t* dataArray = (PrimitiveData_t*)malloc(MAXIMUM_NB_NODES * sizeof(PrimitiveData_t));
    if (dataArray == NULL)
        return MEMORY_ALLOCATION_FAILURE_EXCEPTION;
    StackSLLBT_t stack = newStackSLLBT();
    const NodeBT_t* current = root;
    NodeBT_t* lastVisited = NULL;
    size_t nbNodes = 0U;
    while (!isStackSLLBTEmpty(stack) || current != NULL)
    {
        if (current != NULL)
        {
            pushStackSLLBT(&stack, current);
            current = current->left;
            continue;
        }
        NodeBT_t* top;
        topStackSLLBT(stack, &top);
        if (top->right != NULL && lastVisited != top->right)
        {
            current = top->right;
            continue;
        }
        popStackSLLBT(&stack, &top);
        dataArray[nbNodes++] = top->data;
        lastVisited = top;
    }
    destroyStackSLLBT(&stack);
    dataArray = (PrimitiveData_t*)realloc(dataArray, nbNodes * sizeof(PrimitiveData_t));
    *pDataArray = dataArray;
    *pNbNodes = nbNodes;
    return NO_EXCEPTION;
}

Exception_t levelOrderBT(const NodeBT_t* const root, PrimitiveData_t** const pDataArray, size_t* const pNbNodes)
{
    if (root == NULL)
    {
        *pDataArray = NULL;
        *pNbNodes = 0U;
        return NO_EXCEPTION;
    }
    PrimitiveData_t* dataArray = (PrimitiveData_t*)malloc(MAXIMUM_NB_NODES * sizeof(PrimitiveData_t));
    if (dataArray == NULL)
        return MEMORY_ALLOCATION_FAILURE_EXCEPTION;
    QueueSLLBT_t queue = newQueueSLLBT();
    enqueueQueueSLLBT(&queue, root);
    size_t nbNodes = 0U;
    while (!isQueueSLLBTEmpty(queue))
    {
        NodeBT_t* dequeued;
        dequeueQueueSLLBT(&queue, &dequeued);
        dataArray[nbNodes++] = dequeued->data;
        if (dequeued->left != NULL)
            enqueueQueueSLLBT(&queue, dequeued->left);
        if (dequeued->right != NULL)
            enqueueQueueSLLBT(&queue, dequeued->right);
    }
    destroyQueueSLLBT(&queue);
    dataArray = (PrimitiveData_t*)realloc(dataArray, nbNodes * sizeof(PrimitiveData_t));
    *pDataArray = dataArray;
    *pNbNodes = nbNodes;
    return NO_EXCEPTION;
}