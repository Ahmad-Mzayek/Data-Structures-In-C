#ifndef __STACK_SLL_BT_H_
#define __STACK_SLL_BT_H_

#include <stdbool.h>
#include "ExceptionsType.h"
#include "StackSLLBTType.h"

StackSLLBT_t newStackSLLBT(void);

void destroyStackSLLBT(StackSLLBT_t* const pStack);

bool isStackSLLBTEmpty(const StackSLLBT_t stack);

Exception_t pushStackSLLBT(StackSLLBT_t* const pStack, const NodeBT_t* data);

Exception_t popStackSLLBT(StackSLLBT_t* const pStack, NodeBT_t** const pPoppedData);

Exception_t topStackSLLBT(const StackSLLBT_t stack, NodeBT_t** const pTopData);

#endif // __STACK_SLL_BT_H_