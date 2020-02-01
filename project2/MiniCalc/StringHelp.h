#ifndef __STRINGHELP_H__
#define __STRINGHELP_H__

/* Create a new dynamic string. */
extern char* strnew();

/* Append SRC onto DEST, using reallocation. */
extern char* strapp(char** __dest, const char* __src);

#ifdef WIN32
#include <Windows.h>

/* Determine the length of SRC, a wide character string. */
extern size_t wstrlen(const WCHAR* __src);

/* Create a new dynamic string, using wide characters.*/
extern WCHAR* wstrnew();

/* Append SRC onto DEST both wide character strings, using reallocation. */
extern WCHAR* wstrapp(WCHAR** __dest, const WCHAR* __src);

#endif /* WIN32 */
#endif /* !__STRINGHELP_H__ */
