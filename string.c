/*
 * Some string handling routines
 */
#include "c2man.h"
#include <ctype.h>

/* Copy the string into an allocated memory block.
 * Return a pointer to the copy.
 */
char * strduplicate(const char *s)
{
    char *dest;

    if (!s)	return NULL;
    
    if ((dest = malloc((unsigned)(strlen(s)+1))) == NULL)
	outmem();

    strcpy(dest, s);
    return dest;
}

/* compare two strings case insensitively, for up to n chars */
int strncmpi(const char *s1, const char *s2, size_t n)
{
    while(n--)
    {
	int c1 = *s1, c2 = *s2;

	if (c1 == '\0' && c2 == '\0')	break;

	if (isalpha(c1) && isupper(c1))	c1 = tolower(c1);
	if (isalpha(c2) && isupper(c2))	c2 = tolower(c2);

	if (c1 < c2)	return -1;
	if (c1 > c2)	return 1;
	s1++; s2++;
    }
    return 0;
}

/* convert string to upper case */
char * strtoupper(char *in)
{
    char *s;

    for (s = in; *s; s++)
    {
	if (islower(*s))	*s = (char)toupper((unsigned char)*s);
    }
    return in;
}
