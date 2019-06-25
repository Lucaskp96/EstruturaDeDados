#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

/*** Cria um ponteiro para o primeiro nó, ou seja, raiz da árvore. ***/
Apontador* create_tree(){
    Apontador* root = (Apontador*) malloc( sizeof( Apontador ) );
    root = NULL;
    *root = NULL;
    return root;
}
/*** Calcula a altura da arvore ***/
int tree_height(Apontador* root){
    int iLeft, iRight;

    if(root == NULL){
        return 0;
    }

    iLeft = tree_height(root->pLeft);
    iRight = tree_height(root->pRight);

    if(iLeft > iRight){
        return iLeft + 1;
    }else{
        return iRight + 1;
    }
}
/*** Calcula o fator de balanceamento. ***/
int FB(Apontador* root){
    int fb;

    if(root == NULL){
        return 0;
    }

    fb = tree_height(root->pLeft) - tree_height(root->pRight);
/*  fb > 0: esq > dir.   fb < 0: dir > esq. */
    return fb;
}
/*** Rotação simples à direita ***/
int rotate_ll(Apontador* root){ //RSD
    Node* node;
    node = (*root)->pLeft;
    (*root)->pLeft = node->pRight;
    node->pRight = *root;
    (*root) = node;
}
/*** Rotação simples à esquerda ***/
int rotate_rr(Apontador* root){ //RSE
    Node* node;
    node = (*root)->pRight;
    (*root)->pRight = node->pLeft;
    node->pLeft = (*root);
    (*root) = node;
}
/*** Rotação dupla à direita ***/
int rotate_lr(Apontador* root){
    int fbe = FB((*root)->pLeft);

    if(fbe > 0){
        rotate_ll(root);
        return 1;
    }else if (fbe < 0){
        rotate_rr(&((*root)->pLeft));
        rotate_ll(root);
        return 1;
    }
    return 0;
}
/*** Rotação dupla à esquerda ***/
int rotate_rl(Apontador* root){
    int fbd = FB((*root)->pRight);

    if(fbd < 0){
        rotate_rr(root);
        return 1;
    }else if(fbd > 0){
        rotate_ll( &((*root)->pRight));
        rotate_rr(root);
        return 1;
    }
    return 0;
}
/*** Faz o balanceamento da arvore ***/
int balancing(Apontador* root){
    int fb = FB(*root);

    if(fb > 1)
        return rotate_rr(root);
    else if(fb < -1)
        return rotate_ll(root);
    else
        return 0;
}
/*** Insere novo no na árvore ***/
bool insert_node(Apontador* root, Person* person){
    if(*root == NULL){
        *root = (Node*) malloc(sizeof(Node));
        (*root)->data = *person;
        (*root)->pLeft = NULL;
        (*root)->pRight = NULL;
        return true;
    }else if( (*root)->data.key > person->key ){
        if(insert_node(&(*root)->pLeft,person)){
            if(balancing(root))
                return false;
            else
                return true;
        }
    }else if((*root)->data.key < person->key){
        if(insert(&(*root)->pRight,person)){
            if(balancing(root))
                return false;
            else
                return true;
        }else
            return false;
    }else
        return false;
}

bool remove_node(Node* node);




int node_height(Node* node);
