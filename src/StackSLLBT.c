#include "StackSLLBT.h"
#include "Exceptions.h"
#include "SinglyLinkedListBT.h"

StackSLLBT_t newStackSLLBT(void)
{
    StackSLLBT_t stack;
    stack.top = NULL;
    return stack;
}

void destroyStackSLLBT(StackSLLBT_t* const pStack)
{
    destroySLLBT(&(pStack->top));
}

bool isStackSLLBTEmpty(const StackSLLBT_t stack)
{
    return isSLLBTEmpty(stack.top);
}

Exception_t pushStackSLLBT(StackSLLBT_t* const pStack, const NodeBT_t* newData)
{
    return insertHeadSLLBT(&(pStack->top), newData);
}

Exception_t popStackSLLBT(StackSLLBT_t* const pStack, NodeBT_t** const pPoppedData)
{
    return deleteHeadSLLBT(&(pStack->top), pPoppedData);
}

Exception_t topStackSLLBT(const StackSLLBT_t stack, NodeBT_t** const pTopData)
{
    if (isStackSLLBTEmpty(stack))
        return NULL_POINTER_ARGUMENT_EXCEPTION;
    *pTopData = stack.top->data;
    return NO_EXCEPTION;
}
