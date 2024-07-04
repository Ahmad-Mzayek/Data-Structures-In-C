#include "StackSLL.h"
#include "Exceptions.h"
#include "SinglyLinkedList.h"

StackSLL_t newStackSLL(void)
{
    StackSLL_t stack;
    stack.top = NULL;
    return stack;
}

void destroyStackSLL(StackSLL_t* const pStack)
{
    destroySLL(&(pStack->top));
}

bool isStackSLLEmpty(const StackSLL_t stack)
{
    return isSLLEmpty(stack.top);
}

Exception_t pushStackSLL(StackSLL_t* const pStack, const PrimitiveData_t newData)
{
    return insertHeadSLL(&(pStack->top), newData);
}

Exception_t popStackSLL(StackSLL_t* const pStack, PrimitiveData_t* const pPoppedData)
{
    return deleteHeadSLL(&(pStack->top), pPoppedData);
}

Exception_t topStackSLL(const StackSLL_t stack, PrimitiveData_t* const pTopData)
{
    if (isStackSLLEmpty(stack))
        return NULL_POINTER_ARGUMENT_EXCEPTION;
    *pTopData = stack.top->data;
    return NO_EXCEPTION;
}
