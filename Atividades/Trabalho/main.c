//Olá professor, infelizmente não consegui concluir a atividade como deveria, mas gostaria de deixar aqui meus sinceros agradecimentos aos ensinamentos passados, abraços.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome[30];
    char curso[4];
    int matricula;
}aluno;

int chaveString(char str[]);
int funcaoHash(int valor);
void iniciaTab(aluno v[]);
void insereAlunoTab(aluno v[]);
aluno lerAluno();
aluno *busca(aluno v[], char chave[]);
void imprimirTab(aluno v[]);
void imprimirAlunoTab(aluno v);
void removeHash(aluno v[], char chave[]);
void limparBuffer();

int n;

int main()
{
    aluno *v;

    char chave[30];
    int op;

    //char arqNome[20];
    //scanf("%s", arqNome);
    scanf("%d", &n);

    v = (aluno*)malloc(n * sizeof(aluno));

    iniciaTab(v);

    inicio:
    scanf("%d", &op); //le a opção de ação
    switch(op)
    {
      case 1:
        {
            insereAlunoTab(v);
            goto inicio;
        }

      case 2:
        {
            aluno *buscar;

            scanf(" %[^\n]", chave);
            buscar = busca(v, chave);
            if (buscar)
            {
                imprimirAlunoTab(*buscar);
                printf("\n");
            }
            else
                printf("x\n");
            goto inicio;
        }

      case 3:
        {
            scanf(" %[^\n]", chave);
            removeHash(v, chave);

            goto inicio;
        }

      case 4:
        {
            imprimirTab(v);
            goto inicio;
        }

      default:
        goto inicio;

      case 9: //finaliza o programa
        break;
    }

    return 0;
}

int funcaoHash(int chave)
{
    return (chave & 0x7FFFFFFF) % n;
}

int chaveString(char str[])
{
    int i, valor = 0;

    for(i = 0; i < strlen(str); i++)
        valor = 31 * valor + (int)str[i];
    return valor;
}

void iniciaTab(aluno v[])
{
    int i;

    for(i = 0; i < n; i++)
        strcpy(v[i].nome, "@");
}

void insereAlunoTab(aluno v[])
{
    int valor, id;
    aluno al = lerAluno();

    valor = chaveString(al.nome);
    id = funcaoHash(valor);

    while(strcmp(v[id].nome, "@") && strcmp(v[id].nome, "#") != 0)
    {
        id = funcaoHash(valor + 1);
    }
    v[id] = al;
}

aluno lerAluno()
{
    aluno v;

        scanf(" %[^\n]", v.nome);
        scanf(" %[^\n]", v.curso);
        scanf("%d", &v.matricula);

    return v;
}

aluno *busca(aluno v[], char chave[])
{
    int valor, id;

    valor = chaveString(chave);
    id = funcaoHash(valor);

    while(strcmp(v[id].nome, "@") && strcmp(v[id].nome, "#")  != 0)
    {
        if(strcmp(v[id].nome, chave) == 0)
            return &v[id];
        else
            id = funcaoHash(valor + 1);
    }
    return NULL;
}

void imprimirTab(aluno v[])
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("[%d]: ", i);
        if(strcmp(v[i].nome, "@") && strcmp(v[i].nome, "#") != 0)
            imprimirAlunoTab(v[i]);
            printf("\n");
    }
}

void imprimirAlunoTab(aluno v)
{
    printf("%d %s %s", v.matricula, v.nome, v.curso);
}

void removeHash(aluno v[], char chave[])
{
    int valor, id, i = 0;

    valor = chaveString(chave);
    id = funcaoHash(valor);

    while(i < n)
    {
        if (strcmp(v[id].nome, chave) == 0)
        {
            strcpy(v[id].nome, "#");
            break;
        }
        id = id + 1;
        i++;
    }
    if (i == n)
        printf("x");
}













