#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct elemento{
	int conteudo;
	struct elemento *prox;

}elemento;

typedef struct fila{
	struct elemento *head;
}fila;

elemento *criar_elemento(int c){
	elemento *e = (elemento *)malloc(sizeof(elemento));
	e->conteudo = c;
	e->prox = NULL;

	return e;
}

fila *NewQueue(){
	fila *f = (fila *) malloc (sizeof(fila));
	f->head = NULL;

	return f;
}

void Display(fila *f)
{
	elemento *aux = f->head;
	while(aux != NULL)
    {
		printf("%d ",aux->conteudo);
		aux = aux->prox;
	}
}

void append(fila *f, elemento *e)
{
	if (f->head == NULL){
		f->head = e;
	}else{
		elemento *aux = f->head;
		while(aux->prox != NULL)
		{
			aux = aux->prox;
		}	
		aux->prox = e;
	}
}

elemento *pop(fila *f)
{
	elemento *aux = f->head;
	f->head = aux->prox;
    aux ->prox = NULL;
	
	return(aux);
	free(aux);
}

elemento *poposicao(fila *f, int num)
{
    elemento *aux, *remover = NULL;
    int contagem = 1;
    if(f ->head != NULL){
        if(num == 1){
            remover = f->head;
            f ->head = remover->prox;
        }
        else
		{
            aux = f->head;
            while(contagem != num)
            {
				aux = aux->prox;
			}	
            if(contagem == num)
            {
                remover = aux->prox;
                aux->prox = remover->prox;
            }
        }
    }
    return remover;
}


void FreeQueue(fila *f)
{
	while(f->head != NULL)
    {
		elemento *aux = f->head;
	    f->head = aux->prox;
		free(aux);
	}
}

int tamanholista(fila *f)
{
	int tamanho = 0;
	elemento *aux = f->head;
	while (f -> head != NULL)
	{
		f -> head = aux -> prox;
		tamanho ++;
	}
	return tamanho;
}

void tirarpreferencial(fila *f1, fila *f2, fila *f3, fila *f4)
{
    int contagem = 1;
    while (f1 ->head != NULL)
    {
        while (f2->head != NULL)
		{
			if (contagem == f2->head->conteudo)
			{
				elemento *novo = pop(f1);
				append(f3,novo);
            	pop(f2);
        		contagem ++;	
        	}
			else if (f1->head->conteudo >= 60)
        	{
				append(f3,pop(f1));
            	contagem ++;	
        	}
			else if (f1->head->conteudo <= 5)
        	{
				append(f3,pop(f1));
        		contagem ++;
        	}
			else
			{
				append(f4,pop(f1));
            	contagem ++;
			}
		}
		while (f2->head == NULL && f1->head != NULL)
		{
			if (f1->head->conteudo >= 60)
        	{
            	if (f1->head == NULL)
				{
					break;
				}
				else
				{
					append(f3,pop(f1));
				}	
        	}
			else if (f1->head->conteudo <= 5)
        	{
            	if (f1->head == NULL)
				{
					break;
				}
				else
				{
					append(f3,pop(f1));
				}
        	}
			else 
        	{
            	if (f1->head == NULL)
				{
					break;
				}
				else
				{
					append(f4,pop(f1));
				}	
        	}
		}	
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
    fila *f1 = NewQueue();
    fila *f2 = NewQueue();
    fila *f3 = NewQueue();
	fila *f4 = NewQueue();


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
                append(f1,criar_elemento(elementos[i]));
            }
            else if (j == 1)
            {
                append(f2,criar_elemento(elementos[i]));
            }
		}
		

		free(elementos);
		free(tamanho);

	}

	tirarpreferencial(f1,f2,f3,f4);

    Display(f4);

	printf("\n");

    Display(f3);

	printf("\n");

	free(line);

	return 0;
}