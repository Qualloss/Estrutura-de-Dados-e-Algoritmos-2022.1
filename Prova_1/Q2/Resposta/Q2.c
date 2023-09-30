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
    struct elemento *fim;
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
    l->fim = NULL;
    l->tamanho = 0;
	return l;
}

void Display(lista *l)
{
	elemento *aux = l->head;
	while(aux != NULL)
    {
		printf("%d ", aux->conteudo);
		aux = aux->prox;
	}
}
void Display1(lista *l){
	elemento *aux = l->head;
	while(aux ->prox != NULL)
    {
		aux = aux->prox;
	}
    for (int i = 0; i < l ->tamanho + 1; i++)
    {
        printf("%d ",aux ->conteudo);
        aux = aux ->tail;
    }
    
}

void inserinicio(lista *l, elemento *e)
{
    if (l->head == NULL)
    {
		l ->head = e;
        e ->tail = NULL;
	}
    else
    {
		l ->head->tail = e;
        e->prox = l ->head;
        l->head = e; 
        l ->tamanho ++;
	}
}

void append(lista *l, elemento *e){
	if (l->head == NULL)
    {
		l ->head = e;
        e ->tail = NULL;
	}
    else
    {
		elemento *aux = l->head;
		while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = e;
        e->tail = aux;
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

void inversao(lista *l1, lista *l4) 
{        
    elemento *aux = l1->head;
    while (aux != NULL)
    {
        inserinicio(l4,criar_elemento(aux->conteudo));
        aux = aux ->prox;
    }
}

void Pop(lista *f)
{
    elemento *aux = f->head;
    f -> head = aux -> prox;
    f ->tamanho --;
}

void caminholistas(lista *l1, lista *l2, lista *l3)
{
    elemento *aux = l1->head;
    elemento *aux1 = l2->head;

    while (aux1 != NULL)
    {
        while (aux ->prox != NULL)
        {
            if (aux1 == NULL)
            {
                break;
            }
            else
            {
                if (aux1->conteudo < aux->conteudo)
                {
                    if (aux1 == NULL)
                    {
                        break;
                    }
                    else 
                    {
                        append(l3,criar_elemento(aux->conteudo));
                        aux1 = aux1 ->prox;
                    }
                }
                else if (aux1->conteudo > aux->conteudo)
                {
                    append(l3,criar_elemento(aux->conteudo));
                    aux = aux->prox;
                }
                else if (aux1->conteudo == aux->conteudo)
                {
                    if (aux1 == NULL)
                    {
                        break;
                    }
                    else 
                    {
                       append(l3,criar_elemento(aux->conteudo));
                       aux1 = aux1 ->prox;
                    }
                }
            }    
        }
        if (aux ->prox == NULL)
        {
            if (aux1 == NULL)
            {
                break;
            }
            else
            {
                if (aux1->conteudo > aux->conteudo)
                {
                    if (aux1 == NULL)
                    {
                        break;
                    }
                    else 
                    {
                    append(l3,criar_elemento(aux->conteudo));
                    aux1 = aux1 ->prox;
                    }
                }
                else if (aux1->conteudo < aux->conteudo)
                {
                    append(l3,criar_elemento(aux->conteudo));
                    aux1 = aux1 -> prox;
                }
                else if (aux1->conteudo == aux->conteudo)
                {
                    if (aux1 == NULL)
                    {
                        break;
                    }
                    else 
                    {
                        append(l3,criar_elemento(aux->conteudo));
                        aux1 = aux1 ->prox;
                    }
                }
            }
        }
        while(aux ->prox == NULL)
        {
            if (aux1 == NULL)
            {
                break;
            }
            else
            {
                if (aux1->conteudo > aux->conteudo)
                {
                    if (aux1 == NULL)
                    {
                        break;
                    }
                    else 
                    {
                    append(l3,criar_elemento(aux->conteudo));
                    aux1 = aux1 ->prox;
                    }
                }
                else if (aux1->conteudo < aux->conteudo)
                {
                    append(l3,criar_elemento(aux->conteudo));
                    aux = aux -> tail;
                }
                else if (aux1->conteudo == aux->conteudo)
                {
                    if (aux1 == NULL)
                    {
                        break;
                    }
                    else 
                    {
                        append(l3,criar_elemento(aux->conteudo));
                        aux1 = aux1 ->prox;
                    }
                }
            }
        }
        while (aux ->tail != NULL)
        {
            if (aux1 == NULL)
            {
                break;
            }
            else
            {
                if (aux1->conteudo > aux->conteudo)
                {
                    if (aux1 == NULL)
                    {
                        break;
                    }
                    else 
                    {
                       append(l3,criar_elemento(aux->conteudo));
                       aux1 = aux1 ->prox;
                    }
                }
                else if (aux1->conteudo < aux->conteudo)
                {
                    append(l3,criar_elemento(aux->conteudo));
                    aux = aux->tail;
                }
                else if (aux1->conteudo == aux->conteudo)
                {
                    if (aux1 == NULL)
                    {
                        break;
                    }
                    else 
                    {
                       append(l3,criar_elemento(aux->conteudo));
                       aux1 = aux1 ->prox;
                    }
                }    
            }
        }
        if (aux ->tail ==NULL)
        {
            if (aux1 == NULL)
            {
                break;
            }      
            else
            {
                if (aux1->conteudo > aux->conteudo)
                {
                    if (aux1 == NULL)
                    {
                        break;
                    }
                    else 
                    {
                       append(l3,criar_elemento(aux->conteudo));
                       aux1 = aux1 ->prox;
                    }
                }
                else if (aux1->conteudo < aux->conteudo)
                {
                    append(l3,criar_elemento(aux->conteudo));
                    aux1 = aux1->prox;
                }
                else if (aux1->conteudo == aux->conteudo)
                {
                    if (aux1 == NULL)
                    {
                        break;
                    }
                    else 
                    {
                       append(l3,criar_elemento(aux->conteudo));
                       aux1 = aux1 ->prox;
                    }
                }
            } 
        }
        while (aux ->tail ==NULL)
        {
            if (aux1 == NULL)
            {
                break;
            }      
            else
            {
                if (aux1->conteudo > aux->conteudo)
                {
                    if (aux1 == NULL)
                    {
                        break;
                    }
                    else 
                    {
                       append(l3,criar_elemento(aux->conteudo));
                       aux = aux ->prox;
                    }
                }
                else if (aux1->conteudo < aux->conteudo)
                {
                    append(l3,criar_elemento(aux->conteudo));
                    aux1 = aux1->prox;
                }
                else if (aux1->conteudo == aux->conteudo)
                {
                    if (aux1 == NULL)
                    {
                        break;
                    }
                    else 
                    {
                       append(l3,criar_elemento(aux->conteudo));
                       aux1 = aux1 ->prox;
                    }
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
    lista *l1 = criar_lista();
    lista *l2 = criar_lista();
    lista *l3 = criar_lista();


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
		}
		

		free(elementos);
		free(tamanho);

	}

    caminholistas(l1,l2,l3);

    Display(l3);

    printf("\n");

	free(line);

	return 0;
}