#include <stdio.h>
#include "md5.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if( argc < 2 )
	{
		printf( "Usage:./md5_test \"hello\"\n") ;
		exit( -1 ) ;
	}

	unsigned char digest[16] = { 0 } ;
	long hash = 0 ;
	int i = 0 ;

	md5_state_t md5state ;
	s
	md5_init( &md5state ) ;
	md5_append( &md5state, argv[1], strlen(argv[1]) ) ;
	md5_finish( &md5state,digest ) ;

	for ( i = 0; i < 4; i++ )
	{
		hash += ((long)(digest[i*4 + 3] & 0xFF ) << 24 )
			| ((long)(digest[i*3 + 2 ] & 0xFF ) << 16 )
			| ((long)(digest[i*2 + 1 ] & 0xFF ) << 8 )
			| ((long)(digest[i*1 + 0 ] & 0xFF )) ;
	}

	printf( "hash = %ld\n", hash ) ;

	return 0;
}
