#include<stdio.h>
#include<stdlib.h>
#define tam 13

typedef struct no
{
    int dado;
    struct no *prox;
}no;

int funcaoHash(int valor);
void iniciaHash(no *elem[]);
void insereHash(no *elem[], int valor);
int buscaHash(no *elem[], int valor);
void printHash(no *elem[]);

int main()
{
    int op, valor;
    no *elem[tam];

    iniciaHash(elem);

    inicio:
    scanf("%d", &op);
    switch(op)
    {
        case 1:
        {
            scanf("%d", &valor);
            insereHash(elem, valor);
            goto inicio;
        }

        case 2:
        {
            scanf("%d", &valor);
            buscaHash(elem, valor);
            goto inicio;
        }

        case 3:
        {
            printHash(elem);
            goto inicio;
        }

        default:
            goto inicio;

        case 9:
            break;
    }

    return 0;
}

void iniciaHash(no *elem[])
{
    int i;
    for(i = 0; i < tam; i++)
        elem[i] = NULL;
}

int funcaoHash(int valor)
{
    return (valor & 0x7FFFFFFF) % tam;
}

void insereHash(no *elem[], int valor)
{
    int chave;

    no *novoNo;

    novoNo = malloc(sizeof(no));
    novoNo->dado = valor;
    novoNo->prox = NULL;

    chave = funcaoHash(valor);


    if(elem[chave] == NULL)
        elem[chave] = novoNo;
    else
    {
        no *temp = elem[chave];
        while(temp->prox != NULL)
            temp = temp->prox;
        temp->prox = novoNo;
    }
}

int buscaHash(no *elem[], int valor)
{
    int chave;
    no *temp;

    chave = funcaoHash(valor);
    temp = elem[chave];

    if(temp == NULL)
        return printf("x\n");
    else
    {
        while (temp != NULL)
        {
            if (temp->dado == valor)
                return printf("%d\n", valor);
            temp = temp ->prox;
        }
        return printf("x\n");
    }
}

void printHash(no *elem[])
{
    int i;

    for(i = 0; i < tam; i++)
    {
        no *temp = elem[i];

        printf("[%d]: ", i);
        while(temp!=NULL)
        {
            printf("%d ",temp->dado);
            temp = temp->prox;
        }
        printf("\n");
    }
}




