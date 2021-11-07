#include <stdio.h>
#include <stdlib.h>

void leVetor(int *v, int n);
void insertionSort(int *v, int n, int *comp, int *tr);
int compara(int a, int b, int *c);
void troca(int *v, int i, int j, int *t);

int main() {
  int  *v, n, c=0, t=0;

  scanf("%d", &n);

  v = (int*)malloc(n * sizeof(int));
  leVetor(v, n);
  insertionSort(v, n, &c,&t);
  printf("%d %d", c, t);

  return 0;
}

void leVetor(int *v, int n){
  int i;
  for (i = 0; i < n; i++)
    scanf("%d", &v[i]);
}

void insertionSort(int *v, int n, int *comp, int *tr)
{
    int i, j;

    for(i = 1; i < n; i++)

      for(j = i; j>0 && compara(v[j], v[j-1], comp); j--)
        troca(v, j, (j-1), tr);
}

int compara(int a, int b, int *c)
{
  (*c) = (*c) + 1 ;
  return (a < b);
}

void troca(int *v, int i, int j, int *t)
{
  int aux;
  aux = v[i];
  v[i] = v[j];
  v[j] = aux;
  (*t) = (*t) + 1;
}
