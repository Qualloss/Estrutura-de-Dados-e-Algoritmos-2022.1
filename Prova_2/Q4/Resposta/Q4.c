#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 300



typedef struct elemento{
	int conteudo;
	struct elemento *prox;
    struct elemento *tail;

}elemento;

typedef struct lista{
	struct elemento *head;
    struct elemento *end;
	int tamanho;
}lista;

elemento *criar_elemento(int c){
	elemento *e = (elemento *)malloc(sizeof(elemento));
	e->conteudo = c;
	e->prox = NULL;
    e->tail = NULL;

	return e;
}

lista *criar_lista(){
	lista *l = (lista *) malloc (sizeof(lista));
	l->head = NULL;
    l->end = NULL;
	l->tamanho = 0;
	return l;
}

void Display(lista *l){
	elemento *aux = l->head;
	while(aux != NULL)
    {
		printf("%d ", aux->conteudo);
		aux = aux->prox;
	}
}

void append(lista *l, elemento *e)
{
	if (l->head == NULL){
		l->head = e;
        l->end = e;
		l ->tamanho ++;
	}else{
		elemento *aux = l->head;
		while(aux->prox != NULL)
		{
			aux = aux->prox;
		}	
		aux->prox = e;
        e->tail = aux;
        l->end = e;
		l ->tamanho ++;
	}
}


void FreeList(lista *l)
{
	while(l->head != NULL)
    {
		elemento *aux = l->head;
	    l->head = aux->prox;
		free(aux);
	}
}

int contagem = 0;
int pivo1;
int pivo2;

void Quicksort(lista *l, int pivo)
{
    elemento *aux = l->head;
    elemento *aux2 = l->head;
    lista *l2 = criar_lista();
    lista *l3 = criar_lista();
    if (l->head == l->end && l->tamanho > 0)
    {
        printf("%d ",l->head->conteudo);
        return;
    }
    else
    {
        for (int i = 0; i < pivo; i++)
        {
            aux = aux->prox;
        }
        
        while (aux2 != NULL)
        {
            if (aux2->conteudo < aux->conteudo)
            {
                append(l2,criar_elemento(aux2->conteudo));
            }
            else if (aux2->conteudo > aux->conteudo)
            {
                append(l3,criar_elemento(aux2->conteudo));
            }
            aux2 = aux2->prox;
        }
        if (contagem == 0)
        {
            pivo1 = l2->head->conteudo;
            pivo2 = l3->head->conteudo;
            printf("%d ",pivo1);
            printf("%d ",pivo2);
        }
        contagem ++;
        if (l2->tamanho > 0)
        {
            Quicksort(l2,0);
        }
        printf("%d ", aux->conteudo);
        if (l3->tamanho > 0)
        {
            Quicksort(l3,0);
        }   
    }
}

int main(int argc, char **argv)
{
    lista *l1 = criar_lista();
    
    int linhas;
    int pivo;
    scanf("%d", &linhas);
    int vetor[linhas-1];
    for (int i = 0; i < linhas; i++)
    {
        if (i == 0)
        {
            scanf("%d", &pivo);
        }
        else
        {
            scanf("%d", &vetor[i-1]);
        }
    }
    
    for (int i = 0; i < linhas-1; i++)
    {
        append(l1,criar_elemento(vetor[i]));
    }
    
    Quicksort(l1,pivo);

    printf("\n");

    return 0;
}