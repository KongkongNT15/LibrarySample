#include "pch.h"

int RunNotFound(const char* tag)
{
    fprintf(stderr, "\"%s\"‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½\n", tag);
    fputs("‚Ó‚ŸIH‚Á‚­\n", stderr);

    return -1;
}