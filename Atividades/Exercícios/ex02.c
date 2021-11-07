#include <stdio.h>
#include <stdlib.h>

void leVetor(int *v, int n);
void selectionSort(int *V, int N, int *t, int *c);


int main() {
  int *v, n, c=0, t=0;

  scanf("%d", &n);

  v = (int*)malloc(n * sizeof(int));

  leVetor(v, n);
  selectionSort(v, n, &c, &t);

  printf("%d %d", c, t);

  return 0;
}

void leVetor(int *v, int n){
  int i;
  for (i = 0; i < n; i++)
    scanf("%d", &v[i]);
}

void selectionSort(int *V, int N, int *c, int *t){
    int i, j, menor, troca;
    for(i = 0; i < N-1; i++){
        menor = i;
        for(j = i+1; j < N; j++){
            if(V[j] < V[menor])
                menor = j;
                (*c) = (*c) + 1;
        }
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
            (*t) = (*t) + 1;
    }
}




