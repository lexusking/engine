#include "trie.h"
#include <stdio.h>

// definition the extern variable
int cur = 0 ;
trie_node_t memory[MAXSIZE] = {0} ;

void initTrieRoot( trie_node_t **pRoot )
{
   *pRoot = NULL ;
}

trie_node_t* createTrieNode()
{
   int i ;
   trie_node_t *p ;
   p = &memory[cur++] ;
   p->count = 1;
   for ( i = 0; i < MAX; i++ )
   {
      p->next[i] = NULL ;
   }

   return p ;
}

void insertTrie( trie_node_t **pRoot, char *s )
{
   int i, k ;
   trie_node_t *p ;
   if(!(p=*pRoot))
   {
      p = *pRoot = createTrieNode() ;
   }

   i = 0 ;
   while( s[i] )
   {
      k = s[i++] - 'a' ;
      if(p->next[k])
         p->next[k]->count++ ;
      else
         p->next[k] = createTrieNode() ;

      p = p->next[k] ;
   }
   printf("insert: \"%s\"\n",s) ;
}

int searchTrie( trie_node_t **pRoot, char *s )
{
   trie_node_t *p ;
   int i, k ;
   if(!(p=*pRoot))
   {
      return 0 ;
   }

   i = 0 ;
   while(s[i])
   {
      k = s[i++] - 'a' ;
      if(p->next[k] == NULL)
         return 0 ;
      p = p->next[k] ;
   }

   return p->count ;
}



