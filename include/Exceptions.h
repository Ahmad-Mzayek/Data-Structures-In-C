#ifndef __EXCEPTIONS_H_
#define __EXCEPTIONS_H_

#include <stdbool.h>
#include "ExceptionsType.h"

bool isSuccessful(const Exception_t exception);

void printExceptionMessage(const Exception_t exception);

void printCustomExceptionMessage(const char* const customMessage);

#endif // __EXCEPTIONS_H_