/*
FILA COM TAD
Data 06/05/2022
Matheus Fagundes de Oliveira (matheusoliveira.aluno@unipampa.edu.br)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fila.h"

Descritor * Criadescritor(){
    Descritor * Desc =(Descritor*)malloc(sizeof(Descritor));
    Desc->tamanho = 0;
    Desc->head = NULL;
    Desc->tail = NULL;
    printf("\n\nPilha criada com sucesso.\n");
    return Desc;
}
Nodo * Crianodo(Musica *novamusica){
    struct nodo * listaMuisca = (struct nodo*)malloc(sizeof(struct nodo));
    listaMuisca->info = novamusica;
    listaMuisca->prox = NULL;
    listaMuisca->ant = NULL;
    return listaMuisca;
}
Musica * Criamusica(char *tituloInf, char *artistaInf, char *letraInf, char *generoInf, int anoInf, int execucoesInf){
    Musica * novamusica = (Musica*)malloc(sizeof(Musica));
    strcpy(novamusica->titulo, tituloInf);
    strcpy(novamusica->artista, artistaInf);
    strcpy(novamusica->letra, letraInf);
    strcpy(novamusica->genero, generoInf);
    novamusica->ano = (int)anoInf;
    novamusica->execucoes = (int)execucoesInf;
    return novamusica;
}
Descritor * enqueue(Nodo * novoNodo, Descritor * Desc){
    Nodo * aux = NULL;
    if((Desc->tamanho==0) && (Desc->head)==NULL){
        Desc->head = novoNodo;
        Desc->tail = novoNodo;
        Desc->tamanho++;
        return Desc;
    }else{
        aux = Desc->tail;
        aux->prox = novoNodo;
        aux->prox->ant = aux;
        Desc->tail = novoNodo;
        Desc->tamanho++;
        return Desc;
    }
}
Descritor *delet (Descritor *Desc){
    Desc->tamanho = 0;
    Desc->head = NULL;
    Desc->tail = NULL;
    printf("\n\nLista limpa com sucesso.\n");
    return Desc;
}
Descritor * dequeue(Descritor * Desc){
    imprimeMusica(Desc->head);
    Desc->head = Desc->head->prox;
    Desc->head->ant = NULL;
    Desc->tamanho--;
    return Desc;
}
void * imprimeLista(Descritor *Desc){
    printf("\ntitulo - artista - letra - codigo\n");
    Nodo *aux = Desc->head;
    while (aux != NULL){
        imprimeMusica(aux);
        aux = aux->prox;
    }
    return 0;
}
int empty(Descritor *Desc){
    if((Desc->tamanho==0) && (Desc->head==NULL) && (Desc->tail==NULL)){
        return 1;
    }else{
        return 0;
    }
}
void lenght(Descritor *Desc){
    printf("\nTamanho: %d\n", Desc->tamanho);
}
void * imprimeMusica(Nodo *aux){
    printf("%s - ", aux->info->titulo);
    printf("%s - ", aux->info->artista);
    printf("%s - ", aux->info->letra);
    printf("%s - ", aux->info->genero);
    printf("%d - ", aux->info->ano);
    printf("%d\n", aux->info->execucoes);
    return 0;
}
