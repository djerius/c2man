/*
 * concatenate a list of strings, storing them in a malloc'ed region
 */
#include "c2man.h"
#include "strconcat.h"

#include <stdarg.h>

extern void outmem(void);

char *strconcat(const char *first, ...)
{
    size_t totallen;
    va_list argp;
    char *s, *retstring;
    /* add up the total length */
    va_start(argp,first);
#ifdef DEBUG
    fprintf(stderr,"strconcat: \"%s\"",first);
#endif
    totallen = strlen(first);
    while ((s = va_arg(argp,char *)) != NULL)
    {
	totallen += strlen(s);
#ifdef DEBUG
	fprintf(stderr,",\"%s\"",s);
#endif
    }
#ifdef DEBUG
    fprintf(stderr,"\nstrlen = %ld\n",(long)totallen);
#endif
    va_end(argp);
    
    /* malloc the memory */
    if ((retstring = malloc(totallen + 1)) == 0)
	outmem();
	
    va_start(argp,first);
    /* copy the stuff in */
    strcpy(retstring,first);

    while ((s = va_arg(argp,char *)) != NULL)
	strcat(retstring,s);

    va_end(argp);

#ifdef DEBUG
    fprintf(stderr,"strconcat returns \"%s\"\n",retstring);
#endif
    return retstring;
}
