/*
LISTA ENCADEADA COM TAD
Data 06/05/2022
Matheus Fagundes de Oliveira (matheusoliveira.aluno@unipampa.edu.br)
*/
#include<stdio.h>
#include<stdlib.h>
#include "lista.h"
#include <string.h>

//INICIALIZA DESCRITOR
struct desc_LSE *criaDesc(void){
    struct desc_LSE *minha_LSE = (struct desc_LSE*)malloc(sizeof(struct desc_LSE));
    minha_LSE->LSE = NULL;  
    minha_LSE->tamanho = 0;  
    return minha_LSE;
}
//INICIA MUSICA
struct musica *iniciaMusica(char *novotitulo, char *novoartista, char *novaletra, int codigo, int execucoes){
    struct musica *minhaMusica = (struct musica*)malloc(sizeof(struct musica));
    strcpy(minhaMusica->titulo, novotitulo);
    strcpy(minhaMusica->artista, novoartista);
    strcpy(minhaMusica->letra, novaletra);
    minhaMusica->codigo = codigo;
    minhaMusica->execucoes = execucoes;
    return minhaMusica;

}

//INICIALIA NODO
struct nodo *criaNodo(struct musica * minhaMusica){
     struct nodo *novoelemento = (struct nodo*)malloc(sizeof(struct nodo));
     novoelemento->info = minhaMusica;
     novoelemento->prox = NULL;
     return novoelemento;
}

//REMOVE LISTA
struct nodo *removeLista(struct desc_LSE *minha_LSE, int posicao){
  if((minha_LSE->tamanho == 0) && (posicao > minha_LSE->tamanho)){ //POSICAO NAO EXISTE
    printf("posição não existe ou LISTA VAZIA!\n");
    return NULL;
  }else{
	  if(posicao == 0){ // INICIO DA LISTA
    struct nodo *aux = minha_LSE->LSE;
    minha_LSE->LSE = minha_LSE->LSE->prox;
    minha_LSE->tamanho--;
    return aux;
   }else{ // MEIO OU FIM
	   int listaPos=0;
	   struct nodo *ant;
	   struct nodo * aux = minha_LSE->LSE;
	   while(aux != NULL){
		   ant = aux;
		   aux = aux->prox;
		   listaPos++;
		   if(listaPos == posicao){
			   ant->prox = aux->prox;
			   minha_LSE->tamanho--;
			   return aux;
		    }
	     }
      }
   }
   return minha_LSE->LSE;
}
	   


//INSERIR 
void insere(struct desc_LSE *minhaLSE, struct nodo *novoelemento, int posicao){
    if((minhaLSE->LSE == NULL) || (posicao == 0)){ //INICIO
        minhaLSE->LSE = novoelemento;
        minhaLSE->tamanho++;
    }else{
        struct nodo *aux = minhaLSE->LSE;
        int listaPos = 0;
        if(minhaLSE->tamanho < posicao){
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novoelemento;
            minhaLSE->tamanho++;
            return;
        }else{
            struct nodo *anterior;
            while(aux != NULL){
                anterior = aux;
                aux = aux->prox;
                listaPos++;
                if(listaPos == posicao){
                    novoelemento->prox = aux;
                    anterior->prox = novoelemento;
                    minhaLSE->tamanho++;
                    return;
                }

            }
        }
    }
}

//TAMANHO
int tamanho(struct desc_LSE *minha_LSE){
    return minha_LSE->tamanho;
}

//LIBERA
void libera(struct desc_LSE *minha_LSE){
    struct nodo *aux = minha_LSE->LSE;
    struct nodo *corrente;
    while(aux->prox != NULL){
        corrente = aux;
        aux = aux->prox;
        free(corrente);
    }
    free(aux);
    minha_LSE->LSE = NULL;
    minha_LSE->tamanho = 0;
}

//IMPRIMIR
void imprime(struct desc_LSE *minha_LSE){
  struct nodo *aux = minha_LSE->LSE;
  if(aux == NULL){
	  printf("\n");
	  printf("A lista esta vazia!");
	  printf("\n");
   }
  while(aux != NULL){
	printf("\n");
    printf("\n Nome do Artista: [%s] ", aux->info->artista);
    printf("\n Nome da Musica: [%s] ", aux->info->titulo);
    printf("\n Letra da Musica: [%s] ", aux->info->letra);
    printf("\n Codigo da Musica: [%d] ", aux->info->codigo);
    printf("\n Quantas vezes ouviu: [%d] ", aux->info->execucoes);
    aux = aux->prox;
    printf("\n");
  }

  printf("\n");
  printf("A lista tem [%d] elementos", minha_LSE->tamanho);
  printf("\n");
}

//CONSULTA 
void Consulta(struct desc_LSE *minha_LSE){
	struct nodo *aux = minha_LSE->LSE;
	for(aux = minha_LSE->LSE; aux!=NULL; aux=aux->prox){
	printf("\n");
    printf("Nome do Artista: [%s] ", aux->info->artista);
    printf("\n Nome da Musica: [%s] ", aux->info->titulo);
    printf("\n Letra da Musica: [%s] ", aux->info->letra);
    printf("\n Codigo da Musica: [%d] ", aux->info->codigo);
    printf("\n Quantas vezes ouviu: [%d] ", aux->info->execucoes);
    printf("\n");
	}
	return ;
}
