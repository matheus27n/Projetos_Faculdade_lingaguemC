/*
LISTA ENCADEADA COM TAD
Data 06/05/2022
Matheus Fagundes de Oliveira (matheusoliveira.aluno@unipampa.edu.br)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"

int main(void){
  int op = 0;
  int cont = 0;
  int posicao;
  struct musica *novamusica;
  struct nodo *novoNodo;
  struct desc_LSE *minhanova_LSE;
  do{
    setbuf(stdin,NULL);
		setbuf(stdin,NULL);
		printf("\t\t--------Menu--------");
		printf("\n[1]-cria");
		printf("\n[2]-insere");
		printf("\n[3]-imprime");
		printf("\n[4]-remover");
		printf("\n[5]-libera lista");
		printf("\n[6]-consulta");
		printf("\n[7]-sair");
		printf("\nescolha a opcao: ");
		scanf("%d",&op);
		setbuf(stdin,NULL);
		switch(op){		
		case 1:
					minhanova_LSE = criaDesc();
					printf("voce criou o descritor!\n");
					break;
		case 2:	
		            novamusica = iniciaMusica("a", "b", "c", cont , 22);
		            cont++;
					novoNodo = criaNodo(novamusica);
					printf("digite a posicao do novo nodo\n");
					setbuf(stdin,NULL);
					scanf("%d",&posicao);
					insere(minhanova_LSE,novoNodo,posicao);
					break;
		case 3:
					imprime(minhanova_LSE);
					break;
		case 4:
					printf("digite a posicao da remocao\n");
					setbuf(stdin,NULL);
					scanf("%d",&posicao);
					removeLista(minhanova_LSE,posicao);
					break;
		case 5:
					libera(minhanova_LSE);
					printf("A lista foi liberada!");
					break;
					
		case 6:      
		            Consulta(minhanova_LSE);
		            break;			
		case 7: 	
				    printf("Saindo do Sistema!\n");
				    break;			
				    
		default :
		printf("OPÇÃO INVALIDA!");
		break ;
		
		}
	}while(op != 6);
	return 0;
}




