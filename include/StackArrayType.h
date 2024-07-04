#ifndef __STACK_ARRAY_TYPE_H_
#define __STACK_ARRAY_TYPE_H_

#include <stdlib.h>
#include "PrimitiveDataType.h"

typedef struct StackArray_t
{
    PrimitiveData_t* data;
    size_t nbElements;
    size_t capacity;
} StackArray_t;

#endif // __STACK_ARRAY_TYPE_H_