#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leVetor(int *v, int n);

void troca(int *v, int i, int j, int *t);

void quickHoare(int *v, int p, int r, int *c, int *t);
void quickLomuto(int *v, int p, int r, int *c, int *t);
void quickSegde(int *v, int p, int r, int *c, int *t);

int particaoHoare(int *v, int p, int r, int *c, int *t);
int particaoLomuto(int *v, int p, int r, int *c, int *t);
int particaoSegde(int *v, int p, int r, int *c, int *t);


int main()
{

    int *v, *v1, *v2, n;
    int t = 0, c = 0;
    int i, j = 0, k = 0;

    scanf("%d", &n);
    v = (int*)malloc(n * sizeof(int));
    v1 = (int*)malloc(n * sizeof(int));
    v2 = (int*)malloc(n * sizeof(int));

    leVetor(v, n);

    for (i = 0; i < n; i++){
        v1[j] = v[i];
        j++;
    }

    for (i = 0; i < n; i++){
        v2[k] = v[i];
        k++;
    }

    quickHoare(v, 0, n-1, &c, &t);
    printf("%d %d", c, t);

    t = 0, c = 0;
    quickLomuto(v1, 0, n-1, &c, &t);
    printf("\n%d %d", c, t);

    t = 0, c = 0;
    quickSegde(v2, 0, n-1, &c, &t);
    printf("\n%d %d", c, t);


    return 0;
}

void leVetor(int *v, int n)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

}

void troca(int *v, int i, int j, int *t)
{
 int aux;
 aux = v[i];
 v[i] = v[j];
 v[j] = aux;
 *t = *t + 1;
}

void quickSegde(int *v, int p, int r, int *c, int *t)
{
    int q;

    if(p < r)
    {
        q = particaoSegde(v, p, r, c, t);
        quickSegde(v, p, q - 1, c, t);
        quickSegde(v, q + 1, r, c, t);
    }
}

int particaoSegde(int *v, int p, int r, int *c, int *t)
{
    int i = p, j = r + 1;
    int piv = v[p];

    while(1)
    {
        *c = *c + 1;
        while (v[++i] < piv)
        {
          if(i == r) break;
          *c = *c + 1;
        }
        *c = *c + 1;
        while (piv < v[--j])
        {
          if(j == p) break;
          *c = *c + 1;
        }
        if(i >= j) break;
        troca(v, i, j, t);
    }
    troca(v, p, j, t);
    return j;
}

void quickLomuto(int *v, int p, int r, int *c, int *t)
{
    int q;

    if(p < r)
    {
        q = particaoLomuto(v, p, r, c, t);
        quickLomuto(v, p, q - 1, c, t);
        quickLomuto(v, q + 1, r, c, t);
    }
}

int particaoLomuto(int *v, int p, int r, int *c, int *t)
{
    int i = p - 1, j;
    int piv = v[r];

    for (j = p; j < r; j++)
    {
        *c = *c + 1;
        if (v[j] <= piv){
            i++;
            troca(v, i, j, t);
        }
    }
    troca(v, i + 1, r, t);
    return i + 1;
}

void quickHoare(int *v, int p, int r, int *c, int *t)
{
    int q;

    if(p < r)
    {
        q = particaoHoare(v, p, r, c, t);
        quickHoare(v, p, q, c, t);
        quickHoare(v, q + 1, r, c, t);
    }
}

int particaoHoare(int *v, int p, int r, int *c, int *t)
{
    int i = p - 1, j = r + 1;
    int piv = v[p];

    while(1)
    {
        while (v[--j] > piv)
        {
           *c = *c + 1;
        }
        while (piv > v[++i])
        {
           *c = *c + 1;
        }
        if(i < j)
        {
            troca(v, i, j, t);
        }
        else
        {
            return j;
            *c = *c + 1;
        }
    }
}





