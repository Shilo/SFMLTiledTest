#include "Utils.h"
#include <stdio.h>
#include <stdarg.h>

void Utils::log(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
    fprintf(stdout, "\n");
}