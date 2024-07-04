#include "StackArray.h"
#include "Exceptions.h"

Exception_t newStackArray(const size_t capacity, StackArray_t* const pNewStack)
{
    StackArray_t stack;
    stack.capacity = capacity;
    stack.nbElements = 0U;
    stack.data = (PrimitiveData_t*)malloc(stack.capacity * sizeof(PrimitiveData_t));
    if (stack.data == NULL)
        return MEMORY_ALLOCATION_FAILURE_EXCEPTION;
    *pNewStack = stack;
    return NO_EXCEPTION;
}

void destroyStackArray(StackArray_t* const pStack)
{
    if (pStack->data != NULL)
        free(pStack->data);
    pStack->capacity = 0U;
    pStack->nbElements = 0U;
}

bool isStackArrayEmpty(const StackArray_t stack)
{
    return stack.nbElements == 0U;
}

bool isStackArrayFull(const StackArray_t stack)
{
    return stack.nbElements == stack.capacity;
}

Exception_t pushStackArray(StackArray_t* const pStack, const PrimitiveData_t newData)
{
    if (isStackArrayFull(*pStack))
        return STACK_OVERFLOW_EXCEPTION;
    pStack->data[pStack->nbElements++] = newData;
    return NO_EXCEPTION;
}

Exception_t popStackArray(StackArray_t* const pStack, PrimitiveData_t* const pPoppedData)
{
    if (isStackArrayEmpty(*pStack))
        return STACK_UNDERFLOW_EXCEPTION;
    *pPoppedData = pStack->data[--pStack->nbElements];
    return NO_EXCEPTION;
}

Exception_t topStackArray(const StackArray_t stack, PrimitiveData_t* const pTopData)
{
    if (isStackArrayEmpty(stack))
        return STACK_UNDERFLOW_EXCEPTION;
    *pTopData = stack.data[stack.nbElements - 1U];
    return NO_EXCEPTION;
}