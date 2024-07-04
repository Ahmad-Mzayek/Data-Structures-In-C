#ifndef __STACK_SLL_H_
#define __STACK_SLL_H_

#include <stdbool.h>
#include "ExceptionsType.h"
#include "StackSLLType.h"

StackSLL_t newStackSLL(void);

void destroyStackSLL(StackSLL_t* const pStack);

bool isStackSLLEmpty(const StackSLL_t stack);

Exception_t pushStackSLL(StackSLL_t* const pStack, const PrimitiveData_t data);

Exception_t popStackSLL(StackSLL_t* const pStack, PrimitiveData_t* const pPoppedData);

Exception_t topStackSLL(const StackSLL_t stack, PrimitiveData_t* const pTopData);

#endif // __STACK_SLL_H_