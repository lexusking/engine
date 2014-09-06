#ifndef _TRIE__H_
#define _TRIE__H_

//only use by 'a~z'
#define MAX 26
#define MAXSIZE 100000
typedef struct trieNode
{
   int count ;
   struct trieNode *next[MAX] ;
}trie_node_t;

extern trie_node_t memory[MAXSIZE] ;
extern int cur;

extern void initTrieRoot( trie_node_t **pRoot ) ;
trie_node_t* createTrieNode() ;
void insertTrie( trie_node_t **pRoot, char *s ) ;
int searchTrie( trie_node_t **pRoot, char *s ) ;

#endif
