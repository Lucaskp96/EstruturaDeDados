#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#define bool int
#define true 1
#define false 0

typedef struct p{
    long int key;
    char name[32];
    int age;
}Person;

typedef struct no{
    Person* data;
    int height;
    struct no* pLeft;
    struct no* pRight;
}Node;

typedef Node* Apontador;

Apontador create_tree();
int FB(Node* root);
bool insert_node(Node* root, Node* newNode);
bool remove_node(Node* node);
void rotate_ll(Node* root);
void rotate_rr(Node* root);
void rotate_lr(Node* root);
void rotate_rl(Node* root);
int tree_height(Node* root);
int node_height(Node* node);

#endif // AVL_H_INCLUDED
