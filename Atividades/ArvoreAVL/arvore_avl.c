// Renan Vitor da Silva Matheus Henrique Menezes João Vítor Oliveira Araujo

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
    Esta estrutura representa o no de uma arvore AVL.
*/
typedef struct Node
{
    int key; // chave
    struct Node *left, *right; // ponteiros para as subarvores
    int n; // qtd de nos na subarvore - size na implementacao de Sedgewick
    int height; // altura da subarvore
}Node;

/**
    A funcao balance e responsavel por realizar o balaceamento de um no
    apos o processo de insercao e/ou remocao de um elemento, de modo
    a manter a propriedade da arvore AVL.
    @param x O endereco do ponteiro do no a ser balanceado.
    @return o no da arvore AVL, agora balanceado.
*/
Node* balance(Node **x);

/**
    A funcao balanceFactor calcula o fator de balanceamento de um no.
    @param x O no cujo fator de balanceamento deve ser calculado.
    @return o fator de balanceamento do no.
*/
int balanceFactor(Node *x);

/**
    A funcao height devolve a altura da maior sub-arvore do no
    recebido como parametro.
    @param x o no cuja altura deve ser calculada.
    @return a altura da maior sub-arvore do no.
*/
int height(Node *x);

/**
    A funcao insert e responsavel por inserir uma nova chave
    na arvore AVL.
    @param root A raiz da arvore.
    @param key O elemento a ser inserido.
*/
void insert(Node **root, int key);

/**
    A funcao put percorre as sub-arvores e realiza a insercao
    de uma nova chave em seu local correto. Esta e uma funcao
    auxiliar, invocada pela funcao insert, e nao deve ser
    explicitamente utilizada pelo usuario/programador.
    @param A raiz da sub-arvore.
    @param key O elemento a ser inserido.
*/
Node* put(Node **x, int key);

/**
    A funcao rotateLeft executa uma rotacao simples a esquerda
    na sub-arvore recebida como parametro.
    @param h O ponteiro da sub-arvore a ser rotacionada.
    @return o ponteiro para o no rotacionado.
*/
Node* rotateLeft(Node *h);

/**
    A funcao rotateRight executa uma rotacao simples a direita
    na sub-arvore recebida como parametro.
    @param h O ponteiro da sub-arvore a ser rotacionada.
    @return o ponteiro para o no rotacionado.
*/
Node* rotateRight(Node *h);

/**
    A funcao size devolve o numero de nos na sub-arvore recebida
    como parametro.
    @param x O ponteiro para a sub-arvore.
    @return a quantidade de nos na sub-arvore.
*/
int size(Node *x);

/**
    Funcao principal.
    Ponto de inicio do programa.
    @return zero.
*/

int search(Node *x, int valor);

int removeBinThree(Node **root, int key);

Node* remove_cur(Node *x);

void preOrder(struct Node *x);

void inOrder(struct Node *x);

void postOrder(struct Node *x);

Node *buscaNo(Node *x , int valor);  

void factorNo(Node *x, int valor);

int remove_ArvAVL(Node **root, int valor);

Node* procuraMenor(Node* cur);

int maior(int x, int y);


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
          scanf("%d", &valor); 
          //removeBinThree(&root, valor); //remove elemento da arvore
          remove_ArvAVL(&root,  valor);
          goto inicio;
        }
       
      case 4:
        {
          preOrder(root);
          printf("\n");
          goto inicio;
        }
       
      case 5:
        {
          inOrder(root);
          printf("\n");
          goto inicio;
        }
        
      case 6:
        {
          postOrder(root);
          printf("\n");
          goto inicio;
        }
        
      case 7:
        {
          scanf("%d", &valor);
          factorNo(root, valor); //imprime fator de balanceamento do nó
          goto inicio;   
        }
        
      case 8: //finaliza o programa
        break;  
    }
   return 0;
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

//Correção Balanceamento do Sedgewick
Node* balance(Node **x)
{
    if(balanceFactor((*x)) < -1)
    {
        if(balanceFactor((*x)->left) > 0)
            (*x)->left = rotateLeft((*x)->left);
        (*x) = rotateRight((*x));
    }
    else if(balanceFactor((*x)) > 1)
    {
        if(balanceFactor((*x)->right) < 0)
            (*x)->right = rotateRight((*x)->right);
        (*x) = rotateLeft((*x));
    }
    return (*x);
}

int balanceFactor(Node *x)
{
    return  height(x->right) - height(x->left); //Correção FB do Sedgewick
}

int height(Node *x)
{
    if(!x) return -1;
    return x->height;
}

void insert(Node **root, int key)
{
    put(&(*root), key);
}

Node* put(Node **x, int key)
{
    if(!(*x))
    {
        (*x) = (Node *)malloc(sizeof(Node));
        (*x)->key = key;
        (*x)->left = (*x)->right = NULL;
        (*x)->n = 1;
        (*x)->height = 0;
        return (*x);
    }

    if(key < (*x)->key)
        put(&(*x)->left, key);
    else
        put(&(*x)->right, key);

    (*x)->n = 1 + size((*x)->left) + size((*x)->right);
    (*x)->height = 1 + fmax(height((*x)->left), height((*x)->right));

    return balance(&(*x));
}

Node* rotateLeft(Node *h)
{
    Node *x = h->right;
    h->right = x->left;
    x->left = h;
    x->n = h->n;
    h->n = 1 + size(h->left) + size(h->right);
    h->height = 1 + fmax(height(h->left), height(h->right));
    x->height = 1 + fmax(height(x->left), height(x->right));
    return x;
}

Node* rotateRight(Node *h)
{
    Node *x = h->left;
    h->left = x->right;
    x->right = h;
    x->n = h->n;
    h->n = 1 + size(h->left) + size(h->right);
    h->height = 1 + fmax(height(h->left), height(h->right));
    x->height = 1 + fmax(height(x->left), height(x->right));
    return x;
}

int size(Node *x)
{
    if(!x) return 0;
    return x->n;
}

Node* procuraMenor(Node* cur)
{
    Node *no1 = cur;
    Node *no2 = cur->left;

    while(no2 != NULL)
    {
        no1 = no2;
        no2 = no2->left;
    }
    return no1;
}

//Função que realiza remoção de elemento da arvore
int remove_ArvAVL(Node **root, int valor)
{
	if((*root) == NULL)// valor não existe
	  return 0;

  int res;
	if(valor < (*root)->key)
  {
	  if((res = remove_ArvAVL(&(*root)->left, valor)) == 1)
      balance(&(*root)); 
	  
	}

	if((*root)->key < valor)
  {
	  if((res = remove_ArvAVL(&(*root)->right, valor)) == 1)
      balance(&(*root));
	}

	if((*root)->key == valor){
	  if(((*root)->left == NULL || (*root)->right == NULL))
    {// nó tem 1 filho ou nenhum
			Node *oldNode = (*root);

			if((*root)->left != NULL)
        *root = (*root)->left;
      else
        *root = (*root)->right;

			free(oldNode);

		}else 
    { // nó tem 2 filhos
			Node* temp = procuraMenor((*root)->right);
			(*root)->key = temp->key;
			remove_ArvAVL(&(*root)->right, (*root)->key);
      balance(&(*root)); 
		}

		if (*root != NULL)
      (*root)->height = maior(height((*root)->left),height((*root)->right)) + 1;  

		return 1;
	}
	(*root)->height = maior(height((*root)->left),height((*root)->right)) + 1;

	return res;
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

//retorna o fator de balanceamento do nó buscado
void factorNo(Node *x, int valor) 
{
  Node *no = buscaNo(x, valor);
  if(no)
      printf("%d\n", balanceFactor(no));
}
