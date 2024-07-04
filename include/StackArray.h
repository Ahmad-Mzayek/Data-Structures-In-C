#ifndef __STACK_ARRAY_H_
#define __STACK_ARRAY_H_

#include <stdbool.h>
#include "ExceptionsType.h"
#include "StackArrayType.h"

Exception_t newStackArray(const size_t capacity, StackArray_t* const pNewStack);

void destroyStackArray(StackArray_t* const pStack);

bool isStackArrayEmpty(const StackArray_t stack);

Exception_t pushStackArray(StackArray_t* const pStack, const PrimitiveData_t newData);

Exception_t popStackArray(StackArray_t* const pStack, PrimitiveData_t* const pPoppedData);

Exception_t topStackArray(const StackArray_t stack, PrimitiveData_t* const pTopData);

#endif // __STACK_ARRAY_H_