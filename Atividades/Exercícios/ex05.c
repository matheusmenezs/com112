#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void combsort (int v[], int n);
void bubbleSort (int *v, int n);
void leVetor (int *v, int n);


int main() {
  int *v, n,i;

  scanf("%d", &n);
  v = (int*)malloc(n * sizeof(int));

  leVetor(v, n);
  combsort(v, n);

  for(i=0; i < n; i++)
    printf("%d", v[i]);

  free(v);

  return 0;
}

void leVetor(int *v, int n){
  int i;
  for (i = 0; i < n; i++)
    scanf("%d", &v[i]);
}

void combsort (int v[], int n){

    int step = n, i, j, k, aux, aux2, again = 1;

    //Fase 1
    while((step = int(step / 1.3)) > 1)
        for(j = 0; j <= step; j++)
        {
            k = j + step;
            if(v[k] < v[j]){
                //troca
                aux = v[k];
                v[k] = v[j];
                v[j] = aux;
            }
        }
    //Fase 2
        for(i = 0; i < n - 1 && again; i++)
            for(j = n - 1, again = 0; j > i; j--)
                if(v[j] < v[j - 1]){
                    aux2 = v[j];
                    v[j] = v[j - 1];
                    v[j-1] = aux2;
                    again = 1;
                }

}


/*
void bubbleSort (int *v, int n){
 int i, j, aux;
 long long int c = 0, t = 0;


 for (i = n - 1; i > 0; i--)
    for (j = 0; j < i; j++){
        c++;
        if(v[j] > v[j + 1]){
            t++;
            aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
        }
    }
    printf("%lli %lli", c, t);
}
*/


