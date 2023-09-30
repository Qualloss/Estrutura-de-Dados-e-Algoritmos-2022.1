#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int num;
    int quantidade;
    scanf("%d", &num);
    int vetor[num-1];

    for (int i = 0; i < num; i++)
    {
        if (i == 0)
        {
            scanf("%d", &quantidade);
        }
        else
        {
            scanf("%d", &vetor[i-1]);
        }    
    }
    
    int posicao;
    
    for (int i = 0; i < quantidade; i++)
    {
        int menor = 39999;
        int j = i + 1;
        while (j < num-1)
        {
            if (vetor[j] < menor)
            {
                menor = vetor[j];
                posicao = j;
            }
            j ++;
        }
        if (vetor[i] > menor)
        {
            int aux = vetor[i];
            vetor[i] = menor;
            vetor[posicao] = aux;
        }
    }
    
    for (int i = 0; i < num-1; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");


    return 0;
}