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

void append(lista *l, elemento *e){
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

void insertsort(lista *l)
{
	elemento *aux = l->end;
    elemento *aux2 = l->end->tail;
    if (aux->conteudo < l->head->conteudo)
    {
        aux->tail->prox = NULL;
        l->end = aux->tail;
        aux->prox = l->head;
        aux->tail = NULL;
        l->head->tail = aux;
        l->head = aux;
    }
    else if (aux->conteudo > l->head->conteudo && aux->conteudo < aux2->conteudo)
    {
        elemento *aux4 = criar_elemento(0);
        aux4->prox = aux2;
        aux4->tail = aux2->tail;
        aux2->tail->prox = aux2->prox;
        aux2->prox = aux->prox;
        aux->prox = aux4->prox;
        aux->tail = aux2->tail;
        aux2->tail = aux;
        l->end = aux2;
        aux2 = aux->tail;
        if (aux2 != l->head && aux->conteudo < aux2->conteudo)
        {
            do
            {
                elemento *aux3 = criar_elemento(0);
                aux3 ->prox = aux2;
                aux2->tail->prox = aux2->prox;
                aux2 ->prox = aux->prox;
                aux->prox = aux3->prox;
                aux2->prox->tail = aux2;
                aux->tail = aux2->tail;
                aux2->tail = aux;
                aux2 = aux->tail;
            } while (aux->conteudo < aux2->conteudo);
        }
        
        
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

int main(int argc, char **argv)
{
    lista *l1 = criar_lista();
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
    
    for (int i = 0; i < quantidade; i++)
    {
        if (i == 0)
        {
            append(l1,criar_elemento(vetor[i]));
        }
        else
        {
            append(l1,criar_elemento(vetor[i]));
            insertsort(l1);
        }
        
    }
    
    Display(l1);

    printf("\n");
    
    return 0;
}