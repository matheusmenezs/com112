#include <stdio.h>
#include <stdlib.h>
#include <vector>

void combsort (std::vector<int> &v, int n);

int main() {

  std::vector<int> v;
  int i, n;
  FILE *f;
  char nome[20];

  scanf("%s", nome);

  f = fopen(nome, "r");
  fscanf(f, "%d", &i);

  while(!feof(f))
  {
    v.push_back(i);
    fscanf(f, "%d", &i);
  }
  fclose(f);
  n = v.size();

  combsort(v, n);

  return 0;
}


void combsort (std::vector<int> &v, int n){

    int step = n, i, j, k, aux, aux2, again = 1;
    int t = 0, c = 0;
    while((step = int(step / 1.3)) > 1)

        for(j = 0; j < (n - step); j++)
        {
            k = j + step;
            c++;
            if(v[j] > v[k]){
                printf("%d %d\n", j, k);
                aux = v[j];
                v[j] = v[k];
                v[k] = aux;
                t++;

            }
        }

        for(i = 0; i < n - 1 && again; i++)
            for(j = n - 1, again = 0; j > i; j--){
                c++;
                if(v[j] < v[j - 1]){
                    printf("%d %d\n", (j - 1), j);
                    aux2 = v[j];
                    v[j] = v[j - 1];
                    v[j-1] = aux2;
                    again = 1;
                    t++;
                }
            }

    printf("%d %d ", c, t);
}


