#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STRLIMIT 15

typedef struct elemento{
	char nome[STRLIMIT];
	int conteudo;
	struct elemento *prox;

}elemento;

typedef struct lista{
	struct elemento *head;
	struct elemento *fim;
	int tamanho;
}lista;

elemento *criar_elemento(char name[],int c,int tamanho)
{
	elemento *e = (elemento *)malloc(sizeof(elemento));
	e->conteudo = c;
	e->prox = NULL;
	for (int i = 0; i < tamanho; i++)
	{
		e->nome[i] = name[i];
	}
	e->nome[tamanho] = '\0';
	return e;
}

lista *criar_lista(){
	lista *l = (lista *) malloc (sizeof(lista));
	l->head = NULL;
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
		l->fim = e;
		l->tamanho ++;
	}
	else if (l->tamanho == 1)
	{
		elemento *aux = l->head;
		aux->prox = e;
		e->prox = l->head;
		l->fim = e;
		l ->tamanho ++;
	}
	else
	{
		elemento *aux = l->head;
		while(aux != l->fim)
		{
			aux = aux->prox;
		}	
		aux->prox = e;
		e -> prox = l->head;
		l->fim = e;
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

int soma(lista *l)
{
	int soma = 0;
	elemento *aux = l->head;
	while (aux != l->fim)
	{
		soma+= aux -> conteudo;
		aux = aux ->prox;
	}
	if (aux == l->fim)
	{
		soma += aux->conteudo;
	}
	return soma;
}

void escolhido(lista *l, int soma,char escolhidoo[])
{
	elemento *aux = l->head;
	for (int i = 0; i < l->tamanho; i++)
	{
		if (aux->nome[0] == escolhidoo[0] && aux->nome[1] == escolhidoo[1])
		{
			break;
		}
		else
		{
			aux = aux ->prox;
		}
	}
	for (int i = 0; i < soma; i++)
	{
		aux = aux ->prox;
	}
	printf("%s\n", aux->nome);
}

int main()
{
	int numero;
	lista *l = criar_lista();
	scanf("%d", &numero);

	for (int i = 0; i < numero-1; i++)
	{
		char nome[15];
		int conteudo;
		scanf("%s %d",nome,&conteudo);
		int tamanho = strlen(nome);
		append(l,criar_elemento(nome,conteudo,tamanho));
	}
	
	char escolhidooo[15];

	scanf("%s", escolhidooo);

	int somar = soma(l);

	escolhido(l,somar,escolhidooo);
	
	return 0;
}