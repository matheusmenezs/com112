#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

void bubbleSort (int *v, int n);
void leVetor (int *v, int n);

int main() {
  int *v = NULL, n;

  scanf("%d", &n);
  v = (int*)malloc(n * sizeof(int));

  leVetor(v, n);
  bubbleSort(v, n);
  free(v);

  return 0;
}

void leVetor(int *v, int n){
  int i;
  for (i = 0; i < n; i++)
    scanf("%d", &v[i]);
}

void bubbleSort (int *v, int n){
 int i, j, aux;
 long long int c = 0, t = 0;
 bool troca;

 for (i = n-1; i > 0; i--){
    troca = 0;
    for (j = 0; j < i; j++){
        c++;
        if(v[j] < v[j + 1]){
            t++;
            aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
            troca = 1;
        }
    }
    if (troca == 0)
            break;
 }
    for(i=0; i<n; i++)
    printf("%d ", v[i]);

    printf("\n%lli %lli", c, t);
}
