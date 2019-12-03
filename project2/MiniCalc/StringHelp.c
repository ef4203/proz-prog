#include <stdlib.h>
#include <string.h>

/* We are aware that stdlib.h and string.h are unsafe, that's why we
disable this warning, because we write a safe wrapper for strcat. */
#pragma warning(disable : 4996) /* This function may be unsafe. */

/* Append SRC onto DEST, using reallocation. */
char *strapp(char **dest, const char *src)
{
    char *newstr = (char *)malloc((strlen(*dest) + strlen(src)) * sizeof(char) + 1);

    if (!newstr)
        return NULL; /* Memory allocation failed. */

    strcpy(newstr, *dest);
    strcat(newstr, src);
    free(*dest);
    *dest = newstr;

    return *dest;
}

/* Create a new dynamic string. */
char *strnew()
{
    char *newstr = (char *)malloc(sizeof(char));

    if (!newstr)
        return NULL; /* Memory allocation failed. */

    memset(newstr, 0, 1);

    return newstr;
}

#ifdef WIN32

#include <Windows.h>

/* Determine the length of SRC, a wide character string. */
size_t wstrlen(const WCHAR *src)
{
    int i = 0;

    WCHAR *srcptr = src;
    while (*(srcptr++) != NULL)
        i++;

    return (size_t)i;
}

/* Create a new dynamic string, using wide characters.*/
WCHAR *wstrnew()
{
    WCHAR *newstr = (WCHAR *)malloc(sizeof(WCHAR));

    if (!newstr)
        return NULL; /* Memory allocation failed. */

    memset(newstr, 0, sizeof(WCHAR));

    return newstr;
}

/* Append SRC onto DEST both wide strings, using reallocation. */
WCHAR *wstrapp(WCHAR **dest, const WCHAR *src)
{
    WCHAR *newstr = (WCHAR *)malloc((wstrlen(*dest) + wstrlen(src)) * sizeof(WCHAR) + 1);

    if (!newstr)
        return NULL; /* Memory allocation failed. */

    lstrcpyW(newstr, *dest);
    lstrcatW(newstr, src);
    /* TODO: Fix heap corruption occuring when calling free(),
       Currently, omitting this causes a slight memory leak.
    free(*dest);
    */
    *dest = newstr;

    return *dest;
}

#endif /* WIN32 */

#pragma warning(default : 4996) /* This function may be unsafe. */
