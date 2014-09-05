#include "min_heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// the heap max size
#define N 20

int main(int argc, char *argv[])
{
   srand((int)time(NULL)) ;
   data_type_t x[N] = {0} ;
   int result = 0 ;
   data_type_t num = 300 ;
   int i = 0 ;
   int j = 0 ;
   for( ; i < N; i++ )
   {
      x[i] = rand()%1000 ;
   }

   min_heap_t *h = heap_build( x, N ) ;

   printf("before build:\n") ;
   for( i = 0 ; i < N; i++ )
   {
      printf("%d ", x[i] ) ;
   }
   printf( "\n\nafter build:\n" ) ;
   
   for( i = 1; i <= h->cur; i++ )
   {
      printf("%d ", h->data[i] ) ;
   }

   printf("\n\npush: 300\n") ;

   heap_push(h, num) ;
   for( i = 1; i <= h->cur; i++ )
   {
      printf("%d ", h->data[i] ) ;
   }

   printf("\n\npop on bye one:\n") ;
   for( i = h->cur; i > 0; i-- )
   {
      result = heap_pop(h) ;
      printf("%d ",result) ;
   }
   printf("\n\n");

   heap_destroy( h ) ;

   return 0 ;

}

