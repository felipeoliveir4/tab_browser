//Exercício 3 - Aba Navegador
//Felipe de Oliveira Nº10284970
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadupla.h"

struct aba
{	
	char titulo[40], url[512];
	struct aba *ant, *prox;
};

struct lista_aba
{	int size;
	Aba *inicio,*fim;
};


void cria_lista(Lista **li){
		*li=malloc(sizeof(Lista));
		(*li)->inicio=NULL;
		(*li)->fim=NULL;
		(*li)->size=0;
		return;
}
void destroi_abas(Lista **li){
		Aba *aux;

		while((*li)->inicio!=NULL){
				aux=(*li)->inicio;
				(*li)->inicio=(*li)->inicio->prox;
				free(aux);
		}

		return;

}

int insere_aba(Lista *li, char *titulo, char *url)
{
	if(li == NULL) return 0;
	
	Aba *aba;
	aba=malloc(sizeof(Aba));

	if(aba==NULL) return 0;
	strcpy(aba->titulo,titulo);
	strcpy(aba->url,url);
	aba->prox=NULL;
	
	if(li->inicio==NULL) //insere primeiro, se lista vazia
	{
		aba->ant=NULL;
		li->inicio=aba;

	}else
	{
		Aba *aux=li->inicio;
		while(aux->prox!=NULL)
			aux=aux->prox;

		aux->prox=aba;
		aba->ant=aux;
		li->fim=aba;
		
	}

	li->size++;
	return 1;
}


Aba *procura(Lista *li,char *titulo)
{
		if(li == NULL) return NULL;

		int lugar=0;
		Aba *no;
		no=malloc(sizeof(Aba));
		no->prox=li->inicio;

		while(no!=NULL)
		{
			if(strcmp(no->titulo,titulo)==0)
					return no; //procura no
			no=no->prox;
		}

		return NULL;
}

int troca(Lista *li, char *titulo, int pos)
{
	if(li==NULL) return 0;

	Aba *no;
	no=malloc(sizeof(Aba));

	no=procura(li,titulo);

	if(no==NULL)
	{
		free(no);
		return 0; //no não existe
	} 

	int i=1;

	Aba *aux;
	aux	= malloc(sizeof(Aba));
	aux=li->inicio;

	while(pos>i)
	{
		 aux=aux->prox;
		 i++;
	}

	//elemento no inicio da lista
	if(no==li->inicio)
	{
		no->prox->ant=NULL;
		li->inicio=no->prox;
	}
	//trocar elemento do fim
	else if(no==li->fim)
	{
		no->ant->prox=NULL;

	}
	else //troca elemento do meio da lista
	{
		no->ant->prox = no->prox;
		no->prox->ant = no->ant;
	}
	//////////////////////////////////////////////////////////////////
	//insere o "no" no inicio
	if(aux->ant==NULL && (pos<(li->size)))
	{
		//no se posiciona no inicio
		no->prox=li->inicio;
		no->ant=NULL;
		li->inicio->ant=no;
		li->inicio=no;
	}else if(aux->ant!=NULL && aux->prox!=NULL && (pos<(li->size)))
	{
		no->ant=aux->ant;
		no->prox=aux;
		aux->ant->prox=no;
		aux->ant=no;
	}
	else
	{   
		no->ant=aux;
		no->prox=NULL;
		aux->prox=no;
		li->fim=no;
	}

	free(no);
	free(aux);
	return 1;

}

void imprime(Lista *li){
	Aba *aux=malloc(sizeof(Aba));
	aux=li->inicio;

	while(aux!=NULL)
	{
		printf("%s %s\n",aux->titulo,aux->url);
		aux=aux->prox;
	}
	return;
}
