#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "pilha.h"

Descritor * CriaDescritor(){
	Descritor* Desc=(Descritor *)malloc(sizeof(Descritor));
	Desc->tamanho = 0;
	Desc->Pilha = NULL;
    printf("\n\nLista criada com sucesso.\n");
	return Desc;
};

Nodo* Crianodo(Musica *novamusica){
 struct nodo * listaMuisca = (struct nodo*)malloc(sizeof(struct nodo));
	listaMuisca->info = novamusica;
	listaMuisca->prox = NULL;
	return listaMuisca;
};

Musica * Criamusica(char *tituloInf, char *artistaInf, char *letraInf, char *generoInf, int anoInf, int execucoesInf){
	Musica * novamusica = (Musica*)malloc(sizeof(Musica));
	strcpy(novamusica->titulo, tituloInf);
	strcpy(novamusica->artista, artistaInf);
	strcpy(novamusica->letra, letraInf);
  strcpy(novamusica->genero, generoInf);
  novamusica->ano = (int)anoInf;
	novamusica->execucoes = (int)execucoesInf;
	return novamusica;
};

Descritor * push(Descritor *Desc, Nodo *noMusica){
	Nodo * aux = NULL;
	if((Desc->tamanho==0) && (Desc->Pilha==NULL)){
		Desc->Pilha = noMusica;
		Desc->tamanho++;
		return Desc;
	}else{
        aux = Desc->Pilha;
        Desc->Pilha = noMusica;
        noMusica->prox = aux;
        Desc->tamanho++;
        return Desc;
	}
};

Descritor * pop(Descritor *Desc){
    if(empty(Desc)){
        printf("A lista esta vazia.\n");
        return Desc;
    }else{
        Nodo *aux = NULL;
        Nodo *atua = NULL;
        Desc->Pilha = Desc->Pilha->prox;
        Desc->tamanho--;
        return Desc;
    }
};

int empty(Descritor *Desc){
    if((Desc->tamanho==0) && (Desc->Pilha==NULL)){
        return 1;
    }else{
        return 0;
    }
};

void * TOP(Descritor *Desc){
    imprimeMusica(Desc->Pilha);
    return 0;
};

void * imprimeLista(Descritor *Desc){
    printf("titulo - artista - letra - codigo\n");
    if(empty(Desc)){
        printf("A lista esta vazia.\n");
        return Desc;
    }
    struct nodo *aux = Desc->Pilha;
    	while (aux != NULL){
            imprimeMusica(aux);
            aux = aux->prox;
		}
	return 0;
};

void *imprimeMusica(Nodo *aux){
    printf("%s - ", aux->info->titulo);
    printf("%s - ", aux->info->artista);
    printf("%s - ", aux->info->letra);
    printf("%s - ", aux->info->genero);
    printf("%d - ", aux->info->ano);
    printf("%d\n", aux->info->execucoes);
    return 0;
};

Descritor * limpalista(Descritor *Desc){
    free(Desc);
    return Desc;
};
