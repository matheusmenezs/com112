#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void leVetor (int *v, int n);
void mergeSort(int *v, int p, int r, int *cp, int *tr);
void intercala(int *v, int p, int q, int r, int *cp, int *tr);



int main()
{
    int *v;
    int t = 0, c = 0;
    int n;



    scanf("%d", &n);
    v = (int*)malloc(n * sizeof(int));

    leVetor(v, n);


    mergeSort(v, 0, n, &c, &t);

    printf("%d %d", c, t);

 return 0;
}

void leVetor(int *v, int n){

  int i;
  for (i = 0; i < n; i++)
    scanf("%d", &v[i]);
}

void mergeSort(int *v, int p, int r, int *cp, int *tr){

    if(p < r - 1)

    {
        int q = (p + r) / 2;
        mergeSort(v, p, q, cp, tr);
        mergeSort(v, q, r, cp, tr);
        intercala(v, p, q, r, cp, tr);
    }

}

void intercala(int *v, int p, int q, int r, int *cp, int *tr){

    int i, j, k;
    int *w;

    w = (int *)malloc((r - p) * sizeof(int));
    i = p;
    j = q;
    k = 0;

    while(i < q && j < r)
    {
        (*cp) = (*cp) + 1;

        if(v[i] <= v[j]){
            w[k++] = v[i++];
            (*tr) = (*tr) + 1;
        }

        else{
            w[k++] = v[j++];
            (*tr) = (*tr) + 1;
        }
    }

    while(i < q){
        w[k++] = v[i++];
        (*tr) = (*tr) + 1;
    }

    while(j < r){
        w[k++] = v[j++];
        (*tr) = (*tr) + 1;
    }

    for(i = p; i < r; i++){
        v[i] = w[i - p];
        (*tr) = (*tr) + 1;
    }

    free(w);
}




