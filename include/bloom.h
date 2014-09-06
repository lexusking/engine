#ifndef __BLOOM_H__
#define __BLOOM_H__
#include <stdlib.h>

typedef unsigned int (*hashfunc_t)(const char *) ;
typedef struct {
         size_t asize ;
         unsigned char *a ;
         size_t nfuncs ;
         hashfunc_t *funcs ;
} bloom_t ;

bloom_t *bloomCreate(size_t size, size_t nfuncs, ... ) ;
int bloomDestroy( bloom_t *bloom ) ;
int bloomAdd( bloom_t *bloom, const char *s ) ;
int bloomCheck( bloom_t *bloom, const char *s ) ;

#endif
