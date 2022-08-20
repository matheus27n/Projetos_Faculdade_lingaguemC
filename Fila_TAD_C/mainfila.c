/*
FILA COM TAD
Data 06/05/2022
Matheus Fagundes de Oliveira (matheusoliveira.aluno@unipampa.edu.br)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fila.h"

int main(void){
     Descritor *minhalista;
     Musica *inMusica;
     Nodo*noMusica;

    char titulo[256];
    char artista[256];
    char letra[256];
    char genero[10];
    int menu, posicao, ano;
    menu = posicao = 0;

    while(menu!=8){
        printf("\n###### Menu ##########\n1 - CriaFIla\n2 – DeletaFila\n3 – EMPTYFila \n4 – ENQUEUEFila\n5 - DEQUEUEFila\n6 - TamanhoFila\n7 - ImprimeFila\n8 - Sair\n : ");
        setbuf(stdin, NULL);
        scanf("%d", &menu);
        switch (menu){
            case 1:
                minhalista = Criadescritor();
                break;
            case 2:
                minhalista = delet(minhalista);
                break;
            case 3:
                if(empty(minhalista)){
                    printf("\nTrue\n");
                }else{
                    printf("\nFalse\n");
                }
                break;
            case 4:
                printf("Nome da musica: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", titulo);
                printf("Nome do artista: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", artista);
                printf("Trecho da musica: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", letra);
                setbuf(stdin, NULL);
                printf("Genero da musica: ");
                scanf("%[^\n]s", genero);
                printf("Ano da musica: ");
                scanf("%i", &ano);

                inMusica = Criamusica(titulo,artista,letra,genero, ano,0);
                noMusica = Crianodo(inMusica);
                minhalista = enqueue( noMusica, minhalista);
                break;
            case 5:
                minhalista = dequeue(minhalista);
                break;
            case 6:
                lenght(minhalista);
                break;
            case 7:
                imprimeLista(minhalista);
                break;
            case 8:
                menu = 8;
                break;
        }
    }
  return 0;
}
