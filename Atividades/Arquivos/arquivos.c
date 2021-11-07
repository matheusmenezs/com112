#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *f;
    int v[5] = {1, 3, 5, 7, 9};
    int x[5], i;
    int a;

    f = fopen("arq.bin", "wb");
    fwrite(v, sizeof(int), 5, f); //abre o arquivo para escrita
    fclose(f);

    f = fopen("arq.bin", "rb"); //abre o arquivo para leitura
    fread(x, sizeof(int), 5, f);

    fseek(f, 3 * sizeof(int), SEEK_SET); //posiciona o ponteiro
    fread(&a, sizeof(int), 1, f); //leitura de uma posição do arquivo

    fclose(f);

    printf("A = %d\n", a);

    for(i = 0; i < 5; i++)
        printf("%d ", x[i]);

    return 0;

}
