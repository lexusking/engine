#ifndef _MIN_HEAP__H_
#define _MIN_HEAP__H_
                                       
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>


// cancel assert
//#define NDEBUG

typedef int data_type_t ;
typedef struct min_heap
{
   int cur ;
   int size ;
   data_type_t *data ;

}min_heap_t ;


// extern function , can use in other file.
int heap_elem_greater( data_type_t a, data_type_t b ) ;
void heap_init( min_heap_t **h, int max_size ) ;
min_heap_t* heap_build( data_type_t *x, int n ) ;
void heap_push( min_heap_t *h, data_type_t x ) ;
data_type_t heap_pop( min_heap_t *h ) ;
void heap_destroy(min_heap_t *h ) ;



#endif
