#include "pch.h"

int NotFound(const char* name)
{
    fprintf(stderr, "%s‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½\n", name);
    fputs("‚Ó‚ŸIH‚Á‚­\n", stderr);

    return -1;
}