#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct aluno {
  char nome[100];
  char curso[4];
  int matricula;
}aluno;

void leVetor(aluno *v, char *nomeArquivo, int *cont);
void imprimeVetor(aluno *v, int n);
void quickSort(aluno *v, int p, int r);
int particao(aluno *v, int p, int r);

void trocanome(aluno *v, int i, int j);
void trocacurso(aluno *v, int i, int j);
void trocamatr(aluno *v, int i, int j);


int main()
{
    aluno Aluno[1000];
    char arq[50];
    int n = 0;

    scanf("%s", arq);
    leVetor(Aluno, arq, &n);

    quickSort(Aluno, 0, n-1);
    imprimeVetor(Aluno, n-1);

    return 0;
}

void leVetor(aluno *v, char *nomeArquivo, int *cont){

    int i = 0;
    FILE *f;

    f = fopen(nomeArquivo, "r");

    fscanf(f, "%[^\t] %s %d", v[i].nome, v[i].curso, &v[i].matricula);

    while(!(feof(f))){
        i++;
        fscanf(f, "\n");

        fscanf(f, "%[^\t] %s %d", v[i].nome, v[i].curso, &v[i].matricula);
        (*cont)++;
    }
    fclose(f);
}

void imprimeVetor(aluno *v, int n){

   int i;

   for(i = 0; i <= n; i++){
        printf("%s %s %d\n", v[i].nome, v[i].curso, v[i].matricula);
    }
}

void quickSort(aluno *v, int p, int r)
{
    int q;

    if(p < r)
    {
        q = particao(v, p, r);
        quickSort(v, p, q - 1);
        quickSort(v, q + 1, r);
    }
}

int particao(aluno *v, int p, int r)
{
    int i = p, j = r + 1;

    aluno piv;

    piv = v[p];

    while(1){

        while (strcmp(piv.nome, v[++i].nome)>0) if(i == r) break;
        while (strcmp(piv.nome, v[--j].nome)<0) if(j == p) break;

        if(i >= j) break;
        trocanome(v, i, j);
        trocacurso(v, i, j);
        trocamatr(v, i, j);
    }
    trocanome(v, p, j);
    trocacurso(v, p, j);
    trocamatr(v, p, j);

    return j;
}



void trocanome(aluno *v, int i, int j){
    char aux[100];

    strcpy(aux, v[i].nome);
    strcpy(v[i].nome, v[j].nome);
    strcpy(v[j].nome, aux);

}

void trocacurso(aluno *v, int i, int j){
    char aux[4];

    strcpy(aux, v[i].curso);
    strcpy(v[i].curso, v[j].curso);
    strcpy(v[j].curso, aux);
}

void trocamatr(aluno *v, int i, int j){
    int aux;

    aux = v[i].matricula;
    v[i].matricula = v[j].matricula;
    v[j].matricula = aux;
}

