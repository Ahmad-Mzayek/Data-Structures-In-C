#include <stdio.h>
#include "Exceptions.h"
#include "TextColors.h"

bool isSuccessful(const Exception_t exception)
{
    return exception == NO_EXCEPTION;
}

void printExceptionMessage(const Exception_t exception)
{
    switch (exception)
    {
        case NULL_POINTER_ARGUMENT_EXCEPTION:
            fprintf(stderr, RED_BOLD "Error:\tNull Pointer Argument.\n" DEFAULT_COLOR);
            break;
        case INVALID_ARGUMENT_EXCEPTION:
            fprintf(stderr, RED_BOLD "Error:\tInvalid Argument.\n" DEFAULT_COLOR);
            break;
        case STACK_OVERFLOW_EXCEPTION:
            fprintf(stderr, RED_BOLD "Error:\tStack Overflow.\n" DEFAULT_COLOR);
            break;
        case STACK_UNDERFLOW_EXCEPTION:
            fprintf(stderr, RED_BOLD "Error:\tStack Underflow.\n" DEFAULT_COLOR);
            break;
        case MEMORY_ALLOCATION_FAILURE_EXCEPTION:
            fprintf(stderr, RED_BOLD "Error:\tMemory Allocation Failure.\n" DEFAULT_COLOR);
            break;
        default:
            break;
    }
}

void printCustomExceptionMessage(const char* const customMessage)
{
    fprintf(stderr, RED_BOLD "Error:\t%s\n" DEFAULT_COLOR, customMessage);
}