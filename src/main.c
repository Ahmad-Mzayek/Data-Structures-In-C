#include <stdio.h>
#include <stdlib.h>
#include "Exceptions.h"
#include "BinaryTree.h"
#include "TextColors.h"

static NodeBT_t* testCaseBT(void)
{
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
           /   /
          7   8
    */
    return
        newNodeBT(1,
            newNodeBT(2,
                newNodeBT(4,
                    NULL,
                    NULL),
                newNodeBT(5,
                    newNodeBT(7,
                        NULL,
                        NULL),
                    NULL)),
            newNodeBT(3,
                NULL,
                newNodeBT(6,
                    newNodeBT(8,
                        NULL,
                        NULL),
                    NULL)));
}

static void testPropertiesBT(const NodeBT_t* const root)
{
    const size_t nbNodes = getNbNodes(root), nbLeaves = getNbLeaves(root), nbLevels = getNbLevels(root);
    fprintf(stdout, GREEN_BOLD "Number Of Nodes:\t" CYAN_BOLD "%zu\n" DEFAULT_COLOR, nbNodes);
    fprintf(stdout, GREEN_BOLD "Number Of Leaves:\t" CYAN_BOLD "%zu\n" DEFAULT_COLOR, nbLeaves);
    fprintf(stdout, GREEN_BOLD "Number Of Levels:\t" CYAN_BOLD "%zu\n" DEFAULT_COLOR, nbLevels);
}

static void printPrimitiveDataArray(const PrimitiveData_t* const array, const size_t nbElements)
{
    if (array == NULL || nbElements == 0U)
    {
        fprintf(stdout, YELLOW_BOLD "{" RED_BOLD "/" YELLOW_BOLD "}.\n" DEFAULT_COLOR);
        return;
    }
    fprintf(stdout, YELLOW_BOLD "{" BLUE_BOLD PRIMITIVE_DATA_FORMAT DEFAULT_COLOR, array[0U]);
    for (size_t i = 1U; i < nbElements; ++i)
        fprintf(stdout, YELLOW_BOLD ", " BLUE_BOLD PRIMITIVE_DATA_FORMAT DEFAULT_COLOR, array[i]);
    fprintf(stdout, YELLOW_BOLD "}.\n" DEFAULT_COLOR);
}

static bool testPreOrderBT(const NodeBT_t* const root)
{
    size_t nbNodes;
    PrimitiveData_t* preOrderArray;
    const Exception_t preOrderCall = preOrderBT(root, &preOrderArray, &nbNodes);
    if (!isSuccessful(preOrderCall))
    {
        printExceptionMessage(preOrderCall);
        return false;
    }
    fprintf(stdout, GREEN_BOLD "Pre-Order Traversal:\t" DEFAULT_COLOR);
    printPrimitiveDataArray(preOrderArray, nbNodes);
    free(preOrderArray);
    return true;
}

static bool testInOrderBT(const NodeBT_t* const root)
{
    size_t nbNodes;
    PrimitiveData_t* inOrderArray;
    const Exception_t inOrderCall = inOrderBT(root, &inOrderArray, &nbNodes);
    if (!isSuccessful(inOrderCall))
    {
        printExceptionMessage(inOrderCall);
        return false;
    }
    fprintf(stdout, GREEN_BOLD "In-Order Traversal:\t" DEFAULT_COLOR);
    printPrimitiveDataArray(inOrderArray, nbNodes);
    free(inOrderArray);
    return true;
}

static bool testPostOrderBT(const NodeBT_t* const root)
{
    size_t nbNodes;
    PrimitiveData_t* postOrderArray;
    const Exception_t postOrderCall = postOrderBT(root, &postOrderArray, &nbNodes);
    if (!isSuccessful(postOrderCall))
    {
        printExceptionMessage(postOrderCall);
        return false;
    }
    fprintf(stdout, GREEN_BOLD "Post-Order Traversal:\t" DEFAULT_COLOR);
    printPrimitiveDataArray(postOrderArray, nbNodes);
    free(postOrderArray);
    return true;
}

static bool testLevelOrderBT(const NodeBT_t* const root)
{
    size_t nbNodes;
    PrimitiveData_t* levelOrderArray;
    const Exception_t levelOrderCall = levelOrderBT(root, &levelOrderArray, &nbNodes);
    if (!isSuccessful(levelOrderCall))
    {
        printExceptionMessage(levelOrderCall);
        return false;
    }
    fprintf(stdout, GREEN_BOLD "Level-Order Traversal:\t" DEFAULT_COLOR);
    printPrimitiveDataArray(levelOrderArray, nbNodes);
    free(levelOrderArray);
    return true;
}

int main(void)
{
    NodeBT_t* root = testCaseBT();
    testPropertiesBT(root);
    const bool isTraversalSuccessful = (testPreOrderBT(root) && testInOrderBT(root) && testPostOrderBT(root) && testLevelOrderBT(root));
    destroyBT(&root);
    return (isTraversalSuccessful) ? EXIT_SUCCESS : EXIT_FAILURE;
}
