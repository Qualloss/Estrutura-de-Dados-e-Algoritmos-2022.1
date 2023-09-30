#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//----------------------------------------------------------------------------------------------------------------------------
typedef struct elemento1{
	int conteudo;
	struct elemento1 *prox;
    struct elemento1 *tail;

}elemento1;

typedef struct pilha{
	struct elemento1 *topo;
    int tamanho;
}pilha;

elemento1 *criar_elemento1(int c){
	elemento1 *e = (elemento1 *)malloc(sizeof(elemento1));
	e->conteudo = c;
	e->prox = NULL;
    e->tail = NULL;

	return e;
}

pilha *NewStack(){
	pilha *p = (pilha *) malloc (sizeof(pilha));
	p->topo = NULL;
    p->tamanho = 0;
	return p;
}

void Display1(pilha *p){
	elemento1 *aux = p->topo;
	while(aux != NULL)
    {
		printf("%d ", aux->conteudo);
		aux = aux->prox;
	}
}

void Push(pilha *p, elemento1 *e)
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
        p ->tamanho ++;
    }    
}

int Pop(pilha *p)
{
	elemento1 *aux = p->topo;
	p -> topo = aux -> prox;
	return aux ->conteudo;
    free(aux);
    
}

void FreeStack(pilha *p)
{
	while(p ->topo != NULL)
    {
		Pop(p);
	}
}
//-------------------------------------------------------------------------------------------------------
typedef struct elemento{
	int conteudo;
	struct elemento *prox;

}elemento;

typedef struct fila{
	struct elemento *head;
    int tamanho;
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
    f->tamanho = 0;

	return f;
}

void Display(fila *f){
	elemento *aux = f->head;
	while(aux != NULL)
    {
		printf("%d ", aux->conteudo);
		aux = aux->prox;
	}
}

void append(fila *f, elemento *e){
	if (f->head == NULL){
		f->head = e;
        f ->tamanho ++;
	}else{
		elemento *aux = f->head;
		while(aux->prox != NULL)
			aux = aux->prox;

		aux->prox = e;
        f ->tamanho ++;
	}
}

int Poop(fila *f)
{
    elemento *aux = f->head;
    f -> head = aux -> prox;
    f ->tamanho --;
    return(aux ->conteudo);
}

void FreeQueue(fila *f)
{
	while(f->head != NULL)
    {
		elemento *aux = f->head;
	    f->head = aux->prox;
        f ->tamanho --;
		free(aux);
	}
}

int tamanhofila(fila *f)
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
//-------------------------------------------------------------------------------------------------------

void pilhafila(pilha *p, fila *f)
{
    while (p ->topo != NULL)
    {
        int escolhido = Pop(p);
        append(f,criar_elemento(escolhido));
    }    
}

/*fila *menor(fila *f1, fila *f2)
{
    int tamanho1 = tamanhofila(f1);
    int tamanho2 = tamanhofila(f2);

    if (tamanho1 > tamanho2)
    {
        return f2;
    }
    else if (tamanho2 > tamanho1)
    {
        return f1;
    }
    else if (tamanho1 == tamanho2)
    {
        return f1;
    }    
}

fila *maior(fila *f1, fila *f2)
{
    int tamanho1 = tamanhofila(f1);
    int tamanho2 = tamanhofila(f2);

    if (tamanho1 > tamanho2)
    {
        return f1;
    }
    else if (tamanho2 > tamanho1)
    {
        return f2;
    }
    else if (tamanho1 == tamanho2)
    {
        return f1;
    }    
}
*/

void intercalar(fila *f1, fila *f2,fila *f3)
{   
    int contagem = 0;
    if (f1 ->tamanho < f2 ->tamanho)
    {
        for (int i = 0; i < ((f1 ->tamanho + 2) *2); i++)
        {
            append(f3,criar_elemento((Poop(f1))));
            append(f3,criar_elemento((Poop(f2))));
            contagem ++;
        }
        append(f3,criar_elemento((Poop(f2))));
        for (int i = 0; i < ((f2 ->tamanho + 1) *2) - contagem; i++)
        {
            append(f3,criar_elemento((Poop(f2))));
        }
        append(f3,criar_elemento((Poop(f2))));
        if (f2 ->head != NULL)
        {
            while (f2 ->head != NULL)
            {
                append(f3,criar_elemento((Poop(f2))));
            }
        }   
    }
    else if (f1 ->tamanho == f2 ->tamanho)
    {
        for (int i = 0; i < ((f1 ->tamanho +1) *2); i++)
        {
            append(f3,criar_elemento((Poop(f1))));
            append(f3,criar_elemento((Poop(f2))));
        }
        if (f2 ->head != NULL && f1->head != NULL)
        {
            while (f2 ->head != NULL && f1->head != NULL)
            {
                append(f3,criar_elemento((Poop(f1))));
                append(f3,criar_elemento((Poop(f2))));
            }
        }
    }
    else if (f1 ->tamanho > f2 ->tamanho)
    {
        for (int i = 0; i < ((f2 ->tamanho + 2) *2); i++)
        {
            append(f3,criar_elemento((Poop(f1))));
            append(f3,criar_elemento((Poop(f2))));
            contagem ++;
        }
        for (int i = 0; i < ((f1 ->tamanho + 1) *2) - contagem; i++)
        {
            append(f3,criar_elemento((Poop(f1))));
        }
        append(f3,criar_elemento((Poop(f1))));
        if (f1 ->head != NULL)
        {
            while (f1 ->head != NULL)
            {
                append(f3,criar_elemento((Poop(f1))));
            }
        }
        
    }
}
//------------------------------------------------------------------------------------------------------

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
    pilha *p1 = NewStack();
    pilha *p2 = NewStack();
    pilha *p3 = NewStack();
    pilha *p4 = NewStack();

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
                Push(p1,criar_elemento1(elementos[i]));
            }
            else if (j == 1)
            {
                Push(p2,criar_elemento1(elementos[i]));
            }
		}
		

		free(elementos);
		free(tamanho);

	}

    
    for (int i = 0; i < p1 ->tamanho; i++)
    {
        Push(p3,criar_elemento1(Pop(p1)));
    }
     for (int i = 0; i < p2 ->tamanho; i++)
    {
        Push(p4,criar_elemento1(Pop(p2)));
    }


    Display1(p3);

    printf("\n");

    Display1(p4);
    
    printf("\n");

    pilhafila(p3,f1);

    pilhafila(p4,f2);

    Display(f1);

	printf("\n");

    Display(f2);

    printf("\n");

    intercalar(f1,f2,f3);

    Display(f3);

    printf("\n");

	free(line);

	return 0;
}

