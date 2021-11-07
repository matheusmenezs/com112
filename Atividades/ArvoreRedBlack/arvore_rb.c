// Renan Vitor da Silva, Matheus Henrique Menezes, João Vítor Oliveira Araujo

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
    Esta estrutura representa o no de uma arvore LLRB.
*/
typedef struct Node
{
    char color;
    int key; // chave
    struct Node *left, *right; // ponteiros para as subarvores
    int n; // qtd de nos na subarvore - size na implementacao de Sedgewick
    int height; // altura da subarvore
}Node;

int isRed(Node *h);
int size(Node *x);

Node* rotateLeft(Node *h);
Node* rotateRight(Node *h);
Node* flipColors(Node *h);

void insert(Node **root, int key);
Node* put(Node **x, int key);

int search(Node *x, int valor);
Node *buscaNo(Node *x , int valor); 

void preOrder(struct Node *x);
void inOrder(struct Node *x);
void postOrder(struct Node *x);

void nodeColor(Node *x, int key);

int main()
{
    int op, valor;
    Node *root = NULL; // A raiz da arvore.

    inicio:
    scanf("%d", &op); //le a opção de ação
    switch(op)
    { 
      case 1:
        {
          scanf("%d", &valor); 
          insert(&root, valor); //insere o valor lido
          goto inicio;
        }
      
      case 2:
        {
          scanf("%d", &valor); 
          int busca = search(root, valor); //armazena o retorno da função numa variável
          
          if(busca != -1) //caso encontre o valor buscado, imprime na tela
            printf("%d\n", busca);
          else 
            printf("x\n");
          goto inicio;
        }
     
      case 3:
        {
          preOrder(root);
          printf("\n");
          goto inicio;
        }
       
      case 4:
        {
          inOrder(root);
          printf("\n");
          goto inicio;
        }
       
      case 5:
        {
          postOrder(root);
          printf("\n");
          goto inicio;
        }
        
      case 6:
        {
          scanf("%d", &valor);
          nodeColor(root, valor);
          goto inicio;
        }
        
      case 7: //finaliza o programa
        break;       
    }
   return 0;
}

// Função que verifica se o nó é vermelho
int isRed(Node *h)
{
  if(h==NULL) return 0;
  if(h->color == 'R') return 1;
  return 0;
}

// Função de rotação para a esquerda
Node* rotateLeft(Node *h)
{
    Node *x = h->right;
    h->right = x->left;
    x->left = h;

    x->color = h->color;
    h->color = 'R';

    x->n = h->n;
    h->n = 1 + size(h->left) + size(h->right);
    return x;
}

//Função de rotação para a direita
Node* rotateRight(Node *h)
{
    Node *x = h->left;
    h->left = x->right;
    x->right = h;

    x->color = h->color;
    h->color = 'R';

    x->n = h->n;
    h->n = 1 + size(h->left) + size(h->right);
    return x;
}

//Sobe as cores vermelhas dos dois filhos para o pai
Node*  flipColors(Node *h)
{
  h->color = 'R';
  h->left->color = 'B';
  h->right->color = 'B';
  return h;
}

//Retorna o tamanho da subarvore
int size(Node *x)
{
    if(!x) return 0;
    return x->n;
}


// Função auxiliar de inserção
void insert(Node **root, int key)
{
  put(&(*root), key);
  (*root)->color = 'B';
}

Node* put(Node **x, int key)
{
  if(!(*x))
  {
    (*x) = (Node *)malloc(sizeof(Node));
    (*x)->key = key;
    (*x)->left = (*x)->right = NULL;
    (*x)->color = 'R';
    (*x)->n = 1;
    (*x)->height = 0;
      return (*x);
    }
  if(key < (*x)->key)
    put(&(*x)->left, key);
  else
    put(&(*x)->right, key);

  if( isRed((*x)->right) && !isRed((*x)->left) )
    (*x) = rotateLeft(*x);
  if( isRed((*x)->left) && isRed((*x)->left->left) )
    (*x) = rotateRight((*x));
  if( isRed((*x)->left) && isRed((*x)->right) )
    (*x) = flipColors((*x));
  
  (*x)->n = 1 + size((*x)->left) + size((*x)->right);

  return (*x);
}


//Função que retorna elemento buscado 
int search(Node *x, int valor)
{
    if(x == NULL) return -1;

    else if(valor < x->key)
      return search(x->left, valor);

    else if(valor > x->key)
      return search(x->right, valor);

    else
      return x->key;
}

//Funções de percurso 
void preOrder(struct Node *x)
{
	if(x != NULL)
	{
		printf("%d ", x->key);
		preOrder(x->left);
		preOrder(x->right);
	}
}

void inOrder(struct Node *x)
{
	if(x != NULL)
	{
		inOrder(x->left);
    printf("%d ", x->key);
		inOrder(x->right);
	}
}

void postOrder(struct Node *x)
{
	if(x != NULL)
	{
		postOrder(x->left);
		postOrder(x->right);
    printf("%d ", x->key);
	}
}

//função pra buscar nó
Node *buscaNo(Node *x , int valor){

    if(x == NULL) return NULL;

    else if(valor < x->key)
      return buscaNo(x->left, valor);

    else if(valor > x->key)
      return buscaNo(x->right, valor);

    else
      return x;
}
void nodeColor(Node *x, int valor)
{
  Node *no = buscaNo(x, valor);
  if(no){
    printf("%c\n", no->color);
  }
}