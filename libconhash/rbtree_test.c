#include <stdio.h>
#include "util_rbtree.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define size 100

// print the key and data of a node
void print( util_rbtree_node_t *node, void *data )
{
	printf( "key=%d,data=%s\n", node->key, node->data ) ;
}

// free the momery of the node 
void freenode( util_rbtree_node_t *node )
{
	free( node->data ) ;
	free( node ) ;
}


int main(int argc, char *argv[])
{
	util_rbtree_t *tree = (util_rbtree_t *) malloc ( sizeof(utli_rbtree_t) ) ;
	util_rbtree_node_t *node[size] ;
	util_rbtree_node_t *temp ;
	srand((int)time(NULL)) ;
	int i = 0 ;

	// initialize nodes 
	for( ; i < size; i++ )
	{
		node[i] = (util_rbtree_node_t *) malloc ( sizeof(util_rbtree_node_t) ) ;
		node[i]->key = rand()%size ;
		node[i]->parent = NULL ;
		node[i]->right = NULL ;
		node[i]->left = NULL ;
		node[i]->color = 0 ;
		node[i]->data = (char *) malloc (sizeof(char) * 10) ;
		strncpy( node[i]->data, "hello", 10 ) ;
	}
	

	util_rbtree_init( tree ) ;

	// insert nodes into the rbtree
	for( i = 0; i < size; i++ )
	{
		util_rbtree_insert( tree, node[i] ) ;
	}


	// mid travel the tree
	util_rbtree_mid_travel( tree, print, NULL ) ;

	// free all nodes of the tree
	while( !util_rbtree_isempty(tree) )
	{
		temp = tree->root ;
		util_rbtree_delete( tree, temp ) ;
		freenode( temp ) ;
	}

	// free the memory of the tree
	free( tree ) ;

	printf( "finish.\n" ) ;
	return 0;
}
