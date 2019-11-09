//Exercício 3 - Navegador
//Felipe de Oliveira Nº10284970
#include <stdio.h>
#include <stdlib.h>
#include "listadupla.h"

//#define COMP 1000

int main(void)
{
	Lista *li;
	
	char titulo[40],url[512];

	int operacao=0,pos;

	cria_lista(&li);
	
	while(1)
	{
		printf("\nOperacao: ");
		scanf("%d",&operacao);
		
		if(operacao==1)
		{
			scanf("%s",titulo);
			scanf("%s",url);
			insere_aba(li,titulo,url);
		}
		else if(operacao==2){
				scanf("%d",&pos);
				troca(li,titulo,pos);
		}
		else if(operacao==3)
				imprime(li);
		else if(operacao==4)
			break;
	}	
/*
	//while de insercao do valor digitado pelo usuario
	j=0;
	while(j<tam)
	{
		scanf("%d",&valor);
		
		if(p[valor-1]==1)
		{
			compara++;
		}
		else
		{
			compara++;
			insere_lista(li,valor); // insere na lista caso elemento ainda nao estiver nela
			p[valor-1]=1;
		}
		
		j++;
	}
*/	
	

	
	destroi_abas(&li);
	
return 0;
}
