#include <stdlib.h>
#include <stdio.h>
#include "arvores.h"

/*--- ---*/
struct node{
  struct node *pLeft, *pRight;
  int element;
};

/*--- ---*/
Root* create(){
  Root* root = (Root*) malloc(sizeof(Root));
  if(root != NULL)
    *root = NULL;
  return root;
}

/*--- ---*/
bool isEmpty(Root* tree){
  if(tree == NULL){
    return true;
  }if(*tree == NULL){
    return true;
  }
  return false;
}

/*--- ---*/
int height(Root* tree){
  int left_height, right_height;
  if(root == NULL)
    return 0;
  if(*root == NULL)
    return 0;
  left_height = tree_height( &( (*tree)->pLeft) );
  right_height = tree_height( &( (*tree)->pRight) );
  if(left_height > right_height)
    return (left_height + 1);
  else
    return (right_height + 1);
}

/*--- ---*/
int size(Root* tree){
  int left, right;
  if(tree == NULL)
    return 0;
  if(*tree == NULL)
    return 0;
  left = tree_size( &( (*tree)->pLeft) );
  right = tree_size( &( (*tree)->pRight) );

  return (left + right + 1);
}

/*--- ---*/
void destroy(Root* tree){
  if(tree == NULL)
    return;
  node_Destroy(*tree);
  free(tree);
}
void node_Destroy(Node* node){
  if(node == NULL)
    return;
  node_Destroy(node->pLeft);
  node_Destroy(node->pRight);
  free(node);
  node = NULL;
}
/*--- ---*/

}
