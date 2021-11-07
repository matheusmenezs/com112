#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct elemento
{
    int dado;
    struct elemento* prox;

}elemento;

int funcaoHash(int chave, int n);
void alteraHash(int *v, int n);
int buscaHash(int *v, int chave, int n);
void insereHash(int *v, int chave, int n);
void removeHash(int *v, int id);
void printHash(int *v, int chave, int n);

int main()
{
    int n, chave, id;
    int op;

    int *v;

    elemento *inicio;
    elemento *proxElemento;

    inicio = (elemento *)malloc(sizeof(elemento));

    proxElemento = inicio;

    while(1)
    {
        printf("Digite o elemento: ");
        scanf("%d", &proxElemento->dado);

    }
    return 0;





    scanf("%d", &n);
    v = (int*)malloc(n * sizeof(int));
    alteraHash(v, n);

    inicio:
    scanf("%d", &op); //le a opção de ação
    switch(op)
    {
      case 1:
        {
            scanf("%d", &chave);
            insereHash(v, chave, n);
            goto inicio;
        }

      case 2:
        {
            int busca;
            scanf("%d", &chave);
            busca = buscaHash(v, chave, n);
            printf("%d\n", busca);
            goto inicio;
        }

      case 3:
        {
            scanf("%d", &id);
            removeHash(v, id);
            goto inicio;
        }

      case 4:
        {
            printHash(v, chave, n);
            goto inicio;
        }

      default:
        goto inicio;

      case 9: //finaliza o programa
        break;
    }


    return 0;
}

int funcaoHash(int chave, int n)
{
    return (chave & 0x7FFFFFFF) % n;
}

void alteraHash(int *v, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        v[i] = -1;
    }
}

int buscaHash(int *v, int chave, int n)
{
    int id, i;

    id = funcaoHash(chave, n);
    i = id;

    while(i < n)
    {
        if(v[i] == chave)
            return i;
        i++;
    }

    if (i > n-1)
    {
        i = 0;
        while(i < n)
        {
            if(v[i] == chave)
                return i;
            i++;
        }
    }
    return -1;
}

void insereHash(int *v, int chave, int n)
{
    int id, i;

    id = funcaoHash(chave, n);
    i = id;

    while(i < n)
    {
        if(v[i] == -1 || v[i] == -2)
        {
            v[i] = chave;
            break;
        }
        i++;
    }

    if (i > n-1)
    {
        i = 0;
        while(i < n)
        {
            if(v[i] == -1 || v[i] == -2)
            {
                v[i] = chave;
                break;
            }
            i++;
        }
    }
}

void removeHash(int *v, int id)
{
    v[id] = -2;
}

void printHash(int *v, int chave, int n)
{
   int i;
   for (i = 0; i < n; i++)
        if(v[i] != -1 && v[i] != -2)
        {
            printf("%d ", v[i]);
        }
   printf("\n");
}
