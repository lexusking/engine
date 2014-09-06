#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


int main(int argc, char *argv[])
{
   if ( argc < 2 )
   {
      printf("Usage:./sort_test \"merge|quick\"\n") ;
      exit(0) ;
   }

	int src[10] = {100,10,20,90,80,60,70,30,40,50};
	int i = 0 ;
	printf("before %sSort:\n",argv[1]);
	for ( i = 0; i < 10 ; i++ )
	{
		printf("%d ",src[i]);
	}

	printf("\n\nafter %sSort:\n",argv[1]);

   if(strcmp("merge",argv[1]) == 0)
   {
   	mergeSort(src,0,9);
   }

   else
   {
      quickSort(src,0,9) ;
   }

	for ( i = 0; i < 10 ; i++ )
	{
		printf("%d ",src[i]);
	}
	printf("\n\n");

	
	return 0;
}
