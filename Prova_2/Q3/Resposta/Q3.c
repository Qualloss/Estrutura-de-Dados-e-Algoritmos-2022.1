#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void bubblesort(lista *l)
{
    elemento *aux = l->head;
    elemento *aux2 = l->head->prox;
    if (aux->conteudo > aux2->conteudo)
    {
        aux->prox = aux2->prox;
        aux2->prox = aux;
        aux2 ->tail = aux ->tail;
        aux->tail = aux2;
        aux->prox->tail = aux;
        l->head = aux2;
        aux2 = aux->prox;

    }
    else
    {
        aux = aux->prox;
        aux2 = aux->prox;
    }
    do
    {
        if (aux->conteudo > aux2->conteudo)
        {
            aux->prox = aux2->prox;
            aux2->prox = aux;
            aux->tail->prox = aux2;
            aux2->tail = aux->tail;
            aux->tail = aux2;
            aux->prox->tail = aux;
            aux2 = aux->prox;
        }
        else
        {
            aux = aux->prox;
            aux2 = aux->prox;
        }    
    } while (aux2 != l->end);
    if (aux2 == l->end && aux->conteudo > aux2->conteudo)
    {
        aux->prox = aux2->prox;
        aux2->prox = aux;
        aux->tail->prox = aux2;
        aux2->tail = aux->tail;
        aux->tail = aux2;
        l->end = aux;
    }   
}

int main(int argc, char **argv)
{
    lista *l1 = criar_lista();
    int n;
    scanf("%d", &n);
    int vetor[n-1];
    int voltas;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            scanf("%d", &voltas);
        }
        else
        {
            scanf("%d", &vetor[i-1]);
        }
    }
    
    for (int i = 0; i < n-1; i++)
    {
        append(l1,criar_elemento(vetor[i]));
    }

    

    for (int i = 0; i < voltas; i++)
    {
        bubblesort(l1);
    }


    Display(l1);

    printf("\n");

    return 0;       
}