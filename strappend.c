#include "c2man.h"
#include "strappend.h"

#include <stdarg.h>


/*
 * append a list of strings to another, storing them in a malloc'ed region.
 * The first string may be NULL, in which case the rest are simply concatenated.
 */
char *strappend(char *first, ...)
{
    size_t totallen;
    va_list argp;
    char *s, *retstring;
    /* add up the total length */
    va_start(argp,first);
    totallen = first ? strlen(first) : 0;
    while ((s = va_arg(argp,char *)) != NULL)
	totallen += strlen(s);
    va_end(argp);
    
    /* malloc the memory */
    totallen++;	/* add space for the nul terminator */
    if ((retstring = first ? realloc(first,totallen) : malloc(totallen)) == 0)
	outmem();

    if (first == NULL)	*retstring = '\0';

    va_start(argp,first);

    while ((s = va_arg(argp,char *)) != NULL)
	strcat(retstring,s);

    va_end(argp);

    return retstring;
}
