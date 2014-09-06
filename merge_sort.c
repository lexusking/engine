#include <stdio.h>
#include <stdlib.h>

void merge( int *data,int start, int mid, int end )
{
	int *temp = (int*) malloc((end-start+1)*sizeof(int));
	int i = start ;
	int j = mid+1 ;
	int k = 0 ;

	while( i <= mid && j <= end )
	{
		temp[k++] = (data[i]<=data[j])?data[i++]:data[j++] ;
	}

	while( i <= mid )
	{
		temp[k++] = data[i++] ;
	}

	while( j <= end )
	{
		temp[k++] = data[j++] ;
	}

	k = 0 ;

	// i start's with start, k start's with 0
	for( i = start; i <= end; i++ )
	{
		data[i] = temp[k++] ;
	}

	free( temp ) ;
}

void mergeSort(int *data, int start,int end )
{
	if (start == end)
	{	
		return ;
	}

	int mid = (end+start)/2 ;
	mergeSort(data,start,mid);
	mergeSort(data,mid+1,end);
	merge(data,start,mid,end);
}

int main(int argc, char *argv[])
{
	int src[10] = {100,10,20,90,80,60,70,30,40,50};
	int i = 0 ;
	printf("before mergeSort:\n");
	for ( i = 0; i < 10 ; i++ )
	{
		printf("%d ",src[i]);
	}

	printf("\n\nafter mergeSort:\n");
	mergeSort(src,0,9);
	for ( i = 0; i < 10 ; i++ )
	{
		printf("%d ",src[i]);
	}
	printf("\n\n");

	
	return 0;
}
