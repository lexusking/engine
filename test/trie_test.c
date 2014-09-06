#include <stdio.h>
#include "trie.h"

int main()
{
   trie_node_t *root ;
   int count = -1 ;
   initTrieRoot( &root ) ;
   insertTrie( &root, "hello" ) ;
   insertTrie( &root, "hello" ) ;
   insertTrie( &root, "world" ) ;
   printf( "hello = %d\n", searchTrie( &root, "hello")) ;
   printf( "he = %d\n", searchTrie( &root, "he")) ;
   printf( "world = %d\n", searchTrie( &root, "world")) ;
   printf( "llo = %d\n", searchTrie( &root, "llo")) ;
   printf( "wor = %d\n", searchTrie( &root, "wor")) ;
   printf( "china = %d\n", searchTrie( &root, "china")) ;
   return 0 ;

}
