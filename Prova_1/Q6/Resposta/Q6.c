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
	int tamanho;
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
	p ->tamanho = 0;

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
		p ->tamanho ++;
    }
    else
    {
        e ->prox = p ->topo;
		p -> topo = e;
		p->tamanho ++;
    }    
}

elemento *Pop(pilha *p)
{
	elemento *aux = p->topo;
	p->topo = aux->prox;
	p->tamanho --;
	return aux;		
}

void MOV(pilha *p1, pilha *p2)
{
	if (p1->tamanho == 0)
	{
		Push(p1,Pop(p2));
	}
	else if (p2->tamanho == 0)
	{
		Push(p2,Pop(p1));
	}
	else if (p1->topo->conteudo < p2->topo->conteudo)
	{
		Push(p2,Pop(p1));
	}
	else if (p2->topo->conteudo < p1->topo->conteudo)
	{
		Push(p1,Pop(p2));
	}
}


void FreeStack(pilha *p)

{
	while(p->topo != NULL)
    {
		Pop(p);
	}
}


void torresHANOIpar(pilha *ori, pilha *aux, pilha*d)
{
    int contagem = 0;
	int tamanhoo = ori->tamanho;
	while (d->tamanho != tamanhoo)
	{
		MOV(ori,aux);
		contagem ++;
		if (d->tamanho == tamanhoo)
		{
			break;
		}
		else
		{
			MOV(ori,d);
			contagem ++;
		}
		if (d ->tamanho == tamanhoo)
		{
			break;
		}
		else
		{
			MOV(aux,d);
			contagem ++;
		}	
	}
	printf("%d\n", contagem);
}

void torresHANOIimpar(pilha *ori, pilha *aux, pilha*d)
{
    int contagem = 0;
	int tamanhoo = ori->tamanho;
	while (d->tamanho != tamanhoo)
	{
		MOV(ori,d);
		contagem ++;
		if (d ->tamanho == tamanhoo)
		{
			break;
		}
		else
		{
			MOV(ori,aux);
			contagem ++;
		}
		if (d ->tamanho == tamanhoo)
		{
			break;
		}
		else
		{
			MOV(d,aux);
			contagem ++;
		}
	}
	printf("%d\n", contagem);
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
    pilha *p3 = NewStack();


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

		for(int i = 0; i < *tamanho; i++)
		{
            {
                Push(p1,criar_elemento(elementos[i]));
            }
		}
		

		free(elementos);
		free(tamanho);

	}

	if (p1->tamanho % 2 == 0)
	{
		torresHANOIpar(p1,p2,p3);
	}
	else if (p1->tamanho % 2 != 0)
	{
		torresHANOIimpar(p1,p2,p3);
	}
	
	free(line);

	return 0;
}