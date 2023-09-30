#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct elemento{
	int conteudo;
	struct elemento *prox;
    struct elemento *tail;

}elemento;

typedef struct pilha{
	struct elemento *topo;
}pilha;

elemento *criar_elemento(int c){
	elemento *e = (elemento *)malloc(sizeof(elemento));
	e->conteudo = c;
	e->prox = NULL;
    e -> tail = NULL;

	return e;
}

pilha *NewStack(){
	pilha *p = (pilha *) malloc (sizeof(pilha));
	p->topo = NULL;

	return p;
}

void Display(pilha *p){
	elemento *aux = p->topo;
	while(aux != NULL)
    {
		printf("%d\n", aux->conteudo);
		aux = aux->prox;
	}
}

void Push(pilha *p, elemento *e)
{
    if (p -> topo == NULL)
    {
        p -> topo = e;
    }
    else
    {
        e ->prox = p ->topo;
		p -> topo = e;
    }    
}

float Pop(pilha *p, elemento *e)
{
	elemento *aux = p->topo;
	while(aux != e)
    {
		aux = aux->prox;
	}
	if (aux == e)
	{
		e -> tail = aux;
		aux -> prox = e -> prox;
	}
	float escolhido = e -> conteudo;
	return escolhido;	
}

void FreeStack(pilha *p)
{
	elemento *aux = p->topo;
	while(aux != NULL)
    {
		Pop(p, aux ->prox);
	}
}

void Empilhar(pilha *p1, pilha *p2)
{
	elemento *aux = p1 -> topo;
	elemento *aux1 = p2 -> topo;
	while (aux -> prox != NULL)
	{
		aux = aux -> prox;
	}
	if (aux -> prox == NULL)
	{
		aux -> prox = p2 -> topo;
		aux1 -> tail = aux;
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

    pilha *p1 = NewStack();
    pilha *p2 = NewStack();

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
                Push(p1,criar_elemento(elementos[i]));
            }
            else if (j == 1)
            {
                Push(p2,criar_elemento(elementos[i]));
            }
		}
		

		free(elementos);
		free(tamanho);
	}
	/*Display(p2);
	Display(p1);
	*/

	Empilhar(p2,p1);

	Display(p2);
}
