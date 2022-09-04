#include "shell.h"
#include <stdio.h>

char * mystrchr(const char * s, const char c) {
    while ( *s && *s != c )
        ++s;
    return ( *s ) ? (char*) s : NULL;
}
 
char * str_tok(char * str, const char * delim) {
    static char * next;
    
    if ( str ) {
        next = str;
        while ( *next && mystrchr(delim, *next) )
            *next++ = '\0';
    }
    
    if ( ! *next )
        return NULL;
    
    str = next;
    
    while ( *next && ! mystrchr(delim, *next) )
        ++next;
    while ( *next && mystrchr(delim, *next) )
        *next++ = '\0';
    
    return str;
}

