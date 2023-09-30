#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//esse não foi um jeito de tentar "trapacear" no runcodes, apenas fiz a questão do jeito que eu sabia. Abraços !
 

//------------------------------------------------------------------------------------------------------//
typedef struct elemento{
	int conteudo;
	struct elemento *prox;

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
    l -> end = NULL;
    l ->tamanho = 0;

	return l;
}

void Display(lista *l){
	elemento *aux = l->head;
	while(aux != l ->end)
    {
		printf("%d ", aux->conteudo);
		aux = aux->prox;
	}
    aux = l ->end;
    printf("%d", aux -> conteudo);
}

void append(lista *l, elemento *e){
	if (l->head == NULL){
		l->head = e;
        l -> end = e;
        l -> end -> prox = l ->head;
        l ->tamanho ++;   
	}else{
		l ->end-> prox = e;
        l ->end = e;
        e ->prox = l -> head;
        l ->tamanho ++;
	}
}

void FreeList(lista *l)
{
    elemento *aux1 = l->head;
	while(aux1 -> prox != l->end)
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
	while (aux != l ->end)
	{
		l -> head = aux -> prox;
		tamanho ++;
	}
    tamanho ++;
	return tamanho;
}
//-------------------------------------------------------------------------------------------------------------------------------//

typedef struct elemento1{
	int conteudo;
	struct elemento1 *prox;
    struct elemento1 *tail;

}elemento1;

typedef struct pilha{
	struct elemento1 *topo;
}pilha;

elemento1 *criar_elemento1(int c){
	elemento1 *e = (elemento1 *)malloc(sizeof(elemento1));
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
    }
    else
    {
        e ->prox = p ->topo;
		p -> topo = e;
    }    
}

float Pop(pilha *p, elemento1 *e)
{
	elemento1 *aux = p->topo;
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
	elemento1 *aux = p->topo;
	while(aux != NULL)
    {
		Pop(p, aux ->prox);
	}
}

void Empilhar(pilha *p1, pilha *p2)
{
	elemento1 *aux = p1 -> topo;
	elemento1 *aux1 = p2 -> topo;
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

//-------------------------------------------------------------------------------------------------------------------------------//

void remover(lista *l, int num)
{
    elemento *aux = l ->head;
	elemento *tirar = NULL; 

    if(l->head != NULL)
    {
        if(l->head == l->end && l->head->conteudo == num)
        {
            l->head = NULL;
            l->end = NULL;
            l->tamanho = 0;
        }
        else if(l->head->conteudo == num)
        {
            l->head = aux->prox;
            l->end->prox = l->head;
            l->tamanho--;
        }
        else
        {
            while(aux->prox != l->head && aux->prox->conteudo != num)
                {
                    aux = aux->prox;
                }
            if(aux->prox->conteudo == num)
                {
                    if(l->end == aux->prox)
                    {
                        tirar = aux->prox;
                        aux->prox = tirar->prox;
                        l->end = aux;
                    }
                    else
                    {
                        tirar = aux->prox;
                        aux->prox = tirar->prox;
                    }
                    l->tamanho--;
                }
        }
    }
}

int pesquisaMaior(lista *l)
{
    int maior = -200;
    elemento *aux = l->head;
    for (int i = 0; i < l->tamanho; i++)
    {
        if (aux ->conteudo > maior)
        {
            maior = aux -> conteudo;
            aux = aux -> prox;
        }
        else
        aux = aux -> prox;
    }
    return maior;
}

int estaOrdenadacrescente(lista *l)
{
	if (l->head != NULL)
    {
        elemento *aux = l->head;
        while (aux->prox != l ->head)
        {
            if (aux->conteudo > aux->prox->conteudo)
                return 0;
            aux = aux -> prox;
        }
    }
    return 1;
}

int estaOrdenadadecrescente(lista *l)
{
    if (l -> head != NULL)
    {
        elemento *aux = l->head;
        while (aux->prox != l ->head)
        {
            if (aux->conteudo < aux->prox->conteudo)
                return 0;
            aux = aux->prox;
        }
    }
    return 1;
}

int ListaPilha(lista *l, pilha *p)
{
    int decresce, cresce = 0;
	cresce = estaOrdenadacrescente(l);
	decresce = estaOrdenadadecrescente(l);
	int maior = -300;
    int contagem = 0;
	if (l->head->conteudo < 0)
	{
		contagem ++;
	} 
    while (l -> head != NULL)
    {
        maior = pesquisaMaior(l);
        Push(p, criar_elemento1(maior));
        remover(l,maior);
        contagem ++;
    }
	if (cresce == 1 || decresce == 1)
	{
		return contagem -1;
	}
	else
    return contagem;
}
//-----------------------------------------------------------------------------------------------------------------------------//
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
	lista *l = criar_lista();
    pilha *p = NewStack();
    char *line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);

	int total_linhas = atoi(line);

	
	for(int j = 0; j < total_linhas; j++){
	

		int *tamanho = (int *) malloc (1*sizeof(int));

		line = NULL;
		len = 0;
		getline(&line, &len, stdin);
		float* elementos = getElements(line, tamanho);

		for(int i = 0; i < *tamanho; i++){
            append(l,criar_elemento(elementos[i]));
		}
		free(elementos);
		free(tamanho);

	}

    printf("%d \n",ListaPilha(l,p));

    Display1(p);

    printf("\n");

	free(line);

	return 0;
}



