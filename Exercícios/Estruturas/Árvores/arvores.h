#ifndef ARVORES_INCLUDED
#define ARVORES_INCLUDED
#define bool int
#define true 1
#define false 0
/*--- Estruturas utilizadas para representar a raiz e os nós ---*/
typedef struct node Node;
typedef struct node* Root;
/*--- Funções que representam as operações triviais em árvores ---*/
Root* create();             // Cria uma árvore vazia.
bool isEmpty(Root* tree);   // Verifica se a árvore está vazia.
int size(Root* tree);       // Retorna a quantidade de nós da árvore.
int height(Root* tree);     // Retorna a altura da árvore.
void destroy(Root* tree);   // Libera a memória alocada para a árvore.
void node_Destroy(Node* node);  // Auxilia na função que libera a memória.

#endif // ARVORES_INCLUDED
