#include "min_heap.h"

// static function , just use in this file.
static void heap_shift_up( min_heap_t *h, int hole )
{
	data_type_t temp = h->data[hole] ;
	int i = hole ;
	int parent = i >> 1 ;

	while( i && heap_elem_greater( h->data[parent], temp ) )
	{
		h->data[i] = h->data[parent] ;
		i = parent ;
		parent = i >> 1 ;
	}

	h->data[i] = temp ;
}


static void heap_shift_down( min_heap_t *h, int hole )
{
	int i = hole ;
	data_type_t temp = h->data[hole] ;
	int child = i << 1 ;

	while(  child <= h->cur )
	{
		if( child != h->cur )
		{
			if( h->data[child+1] < h->data[child] )
			{
				child = child + 1 ;
			}
		}

		if( temp > h->data[child] )
		{
			h->data[i] = h->data[child] ;
		}
		else
		{
			break ;
		}

		i = child ;
		child = i << 1 ;
		
	}

	h->data[i] = temp ;

}

int heap_elem_greater( data_type_t a, data_type_t b )
{
	return (a>b)? 1 : 0 ;
}


void heap_init( min_heap_t **h, int max_size )
{
	if( (*h) != NULL )
	{
		if( (*h)->data != NULL )
		{
			free( (*h)->data ) ;
		}

		free( (*h) ) ;
	}

	(*h) = ( min_heap_t *) malloc ( sizeof(min_heap_t) ) ;
    assert( (*h) != NULL ) ;

	(*h)->data = ( data_type_t *) malloc ( sizeof(data_type_t) * max_size ) ;
	assert( (*h)->data != NULL ) ;

	(*h)->size = max_size ;
	(*h)->cur = 0 ;
	memset( (*h)->data, 0, sizeof(data_type_t)*max_size ) ;

}


void heap_push( min_heap_t *h, data_type_t x )
{
	int i = 0 ;
	if( h->cur >= h->size - 1 )
	{
		printf( "heap is full!\n") ;
		return ;
	}
	
	h->cur ++ ;
	h->data[h->cur] = x ;
	heap_shift_up( h, h->cur ) ;

}


data_type_t heap_pop( min_heap_t *h )
{
	data_type_t temp = h->data[1] ;
	h->data[1] = h->data[h->cur] ;
	h->cur -- ;
	heap_shift_down( h, 1 ) ;
	return temp ;
}

void heap_destroy(min_heap_t *h )
{
	if( h != NULL )
	{
		if( h->data != NULL )
		{
			free( h->data ) ;
		}

		free( h ) ;
	}

}

min_heap_t* heap_build( data_type_t *x, int n )
{
	int i = 0 ;
	min_heap_t *h = NULL ;
	heap_init( &h, n*2 ) ;
	for( i = 0; i < n; i++)
	{
		h->data[i+1] = x[i] ;
	}

	h->cur = n ;

	for( i = n/2; i >= 1 ; i-- )
	{
		heap_shift_down( h, i ) ;
	}

	return h ;
}

