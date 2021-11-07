#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 typedef struct Node
 {
    int key; // chave
    struct Node *left, *right; // ponteiros para as subarvores
    int n; // qtd de nos na subarvore
 }Node;


void insert(Node **root, int key);
Node* remove_ArvBin (Node* r, int valor);
Node* put(Node **x, int key);
int size(Node *x);

int main()
{
    Node *root = NULL;

    insert(&root, 50);

  return 0;
}

void insert(Node **root, int key)
 {
    (*root) = put(&(*root), key);
 }


Node* put(Node **x, int key)
{
if(!(*x))
{
    (*x) = (Node *)malloc(sizeof(Node));
    (*x)->key = key;
    (*x)->left = (*x)->right = NULL;
    (*x)->n = 1;
    return (*x);
 }

 if(key < (*x)->key)
    (*x)->left = put(&(*x)->left, key);
 else
    (*x)->right = put(&(*x)->right, key);

 (*x)->n = 1 + size((*x)->left) + size((*x)->right);

 return (*x);
 }


 int size(Node *x)
 {
    if(!x) return 0;
    else return x->n;
 }


int busca(Node *x, int valor)
{
    if(x == NULL) return NULL;

    else if(valor < x->key)
        return busca(x->left, valor);

    else if(valor > x->key)
        return busca(x->right, valor);

    else
        return x->key;
}


//Pré-ordem
void PreOrdem(Node *x){
    if(x != NULL){
        printf("\n%i", x->key);
        PreOrdem(x->left);
        PreOrdem(x->right);
    }
}

//In-ordem
void InOrdem(Node *x){
    if(x != NULL){
        InOrdem(x->left);
        printf("\n%i", x->key);
        InOrdem(x->right);
    }
}

//Pós-ordem
void PosOrdem(Node *x){
    if(x != NULL){
        PosOrdem(x->left);
        PosOrdem(x->right);
        printf("\n%i", x->key);
    }
}




//Remoção Código em Java: Adaptar

/*
public void deleteMin()
{
root = deleteMin(root);
}

private Node deleteMin(Node x)
{
if (x.left == null) return x.right;
x.left = deleteMin(x.left);
x.N = size(x.left) + size(x.right) + 1;
return x;
}

public void delete(Key key)
{ root = delete(root, key); }


private Node delete(Node x, Key key)
{
if (x == null) return null;
int cmp = key.compareTo(x.key);
if (cmp < 0) x.left = delete(x.left, key);
else if (cmp > 0) x.right = delete(x.right, key);
else
{
if (x.right == null) return x.left;
if (x.left == null) return x.right;
Node t = x;
x = min(t.right); // See page 407.
x.right = deleteMin(t.right);
x.left = t.left;
}
x.N = size(x.left) + size(x.right) + 1;

return x;
}
*/

