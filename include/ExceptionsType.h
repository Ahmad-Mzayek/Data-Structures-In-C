/*
    @headerfile     ExceptionsType.h
    @author         Ahmad Mzayek
    @date           Thursday, July 4th, 2024
    @brief          This header file defines an Enumeration for various Exception types.
*/

#ifndef __EXCEPTIONS_TYPE_H_
#define __EXCEPTIONS_TYPE_H_

/*
    @enum           Exception_t
    @brief          Defines different types of Exceptions that can be used throughout the codebase to standardize Error Handling.
    @example        The Function 'Exception_t pushStackArray(const Data_t newData)' returns either 'NO_EXCEPTION' or 'STACK_OVERFLOW_EXCEPTION'.
*/
typedef enum Exception_t
{
    NO_EXCEPTION,
    STACK_OVERFLOW_EXCEPTION,
    STACK_UNDERFLOW_EXCEPTION,
    INVALID_ARGUMENT_EXCEPTION,
    NULL_POINTER_ARGUMENT_EXCEPTION,
    MEMORY_ALLOCATION_FAILURE_EXCEPTION
} Exception_t;

#endif // __EXCEPTIONS_TYPE_H_