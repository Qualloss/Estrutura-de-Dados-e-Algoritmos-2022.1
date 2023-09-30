#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct elemento{
	int conteudo;
	struct elemento *prox;

}elemento;

typedef struct lista{
	struct elemento *head;
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

int tamanholista(lista *l)
{
	int tamanho = 0;
	elemento *aux = l->head;
	while (l -> head != NULL)
	{
		l -> head = aux -> prox;
		tamanho ++;
	}
	return tamanho;
}

void Insert(lista *l, lista *l1, int num)
{
    int contagem = 0;
    elemento *aux = l-> head;
    elemento *aux2 = l1 -> head;
	if (l1 ->tamanho== 1 && num == 0)
	{
        aux2 ->prox =aux->prox;
		aux-> prox = aux2;
	}
	else if (l1 ->tamanho== 1)
	{
		while (contagem != num - 1)
    	{
       	aux = aux->prox;
       	contagem ++;
    	}
    	if (contagem == num - 1)
    	{
        aux2 -> prox = aux -> prox;
        aux -> prox = l1 -> head;
    	}
	}
	else
	{
		do
    	{
		aux2 = aux2 -> prox;
    	} 
		while (aux2 ->prox != NULL);
		if (num == 0)
		{
			aux2 -> prox = l -> head;
			l -> head = l1 -> head; 
		}
    	else
		{
			while (contagem != num - 1)
    		{	
       		aux = aux->prox;
       		contagem ++;
    		}
    		if (contagem == num - 1)
    		{
        	aux2 -> prox = aux -> prox;
        	aux -> prox = l1 -> head;
    		}
		}
	}
}

void removerDuplicadas(lista *l) 
{    
    struct elemento *aux = l->head;
    struct elemento *aux1 = aux ->prox;
	struct elemento *aux2 = aux;
      
    while(aux != NULL)
	{   
		aux2 = aux;
		aux1 = aux2 ->prox;
		while (aux1 != NULL)
        {
			if (aux->conteudo == aux1->conteudo)
            {
                aux2->prox = aux1 ->prox;
            }
            else
            {
				aux2 = aux2 ->prox;
            }
			aux1 = aux1 ->prox;
        }
        aux = aux->prox;
    }          
}  

float *
getElements(char *line, int *tamanho){
	float *elementos = (float *) malloc (0*sizeof(float));
	int i = 0;
	
	char* token = strtok(line, " ");
	while (token) {
		i += 1;
		elementos = (float *) realloc (elementos, sizeof(int)*i);
		elementos[i-1] = atof(token);
		token = strtok(NULL, " ");
        }

	*tamanho = i;
	free(token);
	return (elementos);

}

int main(void)
{
    int posicao = 0;
    lista *l1 = criar_lista();
    lista *l2 = criar_lista();

	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);

	int total_linhas = atoi(line);

	for(int j = 0; j < total_linhas; j++)
    {
	    int *tamanho = (int *) malloc (1*sizeof(int));

		line = NULL;
		len = 0;
		getline(&line, &len, stdin);
		float* elementos = getElements(line, tamanho);

		for(int i = 0; i < *tamanho; i++){
			if (j == 0)
            {
                append(l1,criar_elemento(elementos[i]));
            }
            else if (j == 1)
            {
                append(l2,criar_elemento(elementos[i]));
            }
            else
            {
                posicao = elementos[i];
            }
		}
		

		free(elementos);
		free(tamanho);

	}

    Insert(l1,l2,posicao);

    Display(l1);

	printf("\n");

	removerDuplicadas(l1);

	Display(l1);

	printf("\n");

	free(line);

	return 0;
}

