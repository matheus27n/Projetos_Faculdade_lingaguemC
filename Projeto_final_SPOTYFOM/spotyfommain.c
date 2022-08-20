/*  
SPOTYFOM
Data 15/08/2022
Matheus Fagundes de Oliveira (matheusoliveira.aluno@unipampa.edu.br)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "spotyfom.h"
#include<time.h>

int main(void){
	char titulo[256],artista[256],letra[256],genero[10];
	int op = 0, cont = 0, posicao = 0, codigo= 0, execucoes = 0, tamanho = 0, i = 0, codigor = 0, op1 = 0; 

    Descritor *novodesc;
	Nodo *novoNo;
	Descritorfila * novodescFILA;
	Nodofila *nodofila;
	DescritorPILHA *novodescPILHA;
	NodoPILHA * nodopilha;
	Musica *MUSICA, *MUSICAFILA, *MUSICACOPIA, *MUSICAPILHA, *MUSICACOPIAPILHA;

	novodesc = Carregartxt();
	novodescFILA = CriadescritorFILA();
	novodescPILHA = CriaDescritorPILHA();

  do{
    setbuf(stdin,NULL);// O PROGRAMA ESTÁ COM ALGUNS ERROS DE LOGICA, MAS DE CERTA FORMA ESTÁ FUNCIONANDO
		setbuf(stdin,NULL);
		printf("\t\t--------Menu--------");
		printf("\n[1]-Execucoes Pessoal (PILHA)"); //FUNCIONANDO 100%
		printf("\n[2]-Execucoes Aleatoria(FILA)"); // QUEBRA EM CERTAS CONDIÇÕES (POR ENQUANTO)
		printf("\n[3]-Criar Playlist"); //FILA - FUNCIONANDO POR SRAND // PILHA - FUNCIONANDO POR POSIÇÃO [1-5000]   ///AMBOS FUNCIONANDO
		printf("\n[4]-Busca por Artista");//FUNCIONANDO
	    printf("\n[5]-Busca por Codigo");//FUNCIONANDO
		printf("\n[6]-Busca por Titulo");//FUNCIONANDO
		printf("\n[7]-Impressao todo Acervo");//FUNCIONANDO
		printf("\n[8]-Imprimir FILA");//FUNCIONANDO - COM EXECUÇÕES AUMENTANDO +1  //EXECUÇÕES MANUAIS // MODIFICAR LOGICA QUANDO DER 
		printf("\n[9]-Imprimir PILHA");//FUNCIONANDO - COM EXECUÇÕES AUMENTANDO +1 //EXECUÇÕES MANUAIS // MODIFICAR LOGICA QUANDO DER 
		printf("\n[10]-Sair");
		printf("\nescolha a opcao: ");
		scanf("%d",&op);
		setbuf(stdin,NULL);
		switch(op){		
		case 1:

		printf("\nQuantas musicas voce quer ouvir: ");
		scanf("%d", &codigo);
        novodescPILHA = deletarpilha(novodescPILHA, codigo, novodesc);//DELETA UM ELEMENTO COM CODIGO DA PILHA
        MUSICACOPIAPILHA->execucoes++; // LOGO EM SEGUIDA É ACRESCENTADO +1 NA EXECUÇÃO DA MUSICA OUVIDA/EXCLUIDA
		break;

		case 2:
        printf("\nDigite o codigo da musica para ouvir: ");
		scanf("%d", &codigo);
        deletfila(novodescFILA, codigo, novodesc);//DELETA UM ELEMENTO COM CODIGO DA FILA // PROVAVELMENTE ERRO NA LOGICA, DELET QUEBRANDO EM CERTAS CONDIÇÕES 
		MUSICAFILA->execucoes++; // LOGO EM SEGUIDA É ACRESCENTADO +1 NA EXECUÇÃO DA MUSICA OUVIDA/EXCLUIDA
		break;
		break;

		case 3:	
        printf("\n[1]-Playist Aleatoria (FILA)");
		printf("\n[2]-Playlista Pessoal (PILHA)");
		printf("\nEscolha a opcao: ");
		scanf("%d", &op1);
		switch(op1){

		       case 1:
		       printf("\nQual o tamanho da sua playlist(ALEATORIA): ");
               scanf("%d", &tamanho);//TAMANHO QUE VAI SER A PLAYLIST
		       srand(time(NULL));
		       for(i = 0; i<tamanho; i++){// UM FOR COM O TAMANHO ESCOLHIDO PELO USUARIO
               codigor=(rand()%5000);// FAZ UM SRAND DO TAMANHO TOTAL DO ACERVO ( 5000)
		       MUSICACOPIA = get(novodesc, codigor); // FAZ UM COPIA DO STRUCT MUSICA USANDO UM FUNÇÃO (get) ONDE ELA AS POSIÇÕES
                
		       MUSICAFILA = copiamusica(MUSICACOPIA);// AQUI CHAMA FUNÇÃO COPIA STRUCT
               nodofila = CrianodoFILA(MUSICAFILA); // CRIA OS NO COM CADA COPIA DA MUSICA SELECIONADA COM SRAND
               novodescFILA = InsereFILA( nodofila, novodescFILA); // INSERE OS NO NO DESCRITOR DA FILA
		        }
		        break;

		        case 2:
                printf("\nQual o tamanho da sua Playlist(PESSOAL): "); //PLAYLIST NÃO ALEATORIA
                scanf("%d", &tamanho); //RECEBE O VALOR DO PLAYLISTA NESSA ENTRADA DO CASE
		        for(i=0; i<tamanho; i++){ // FOR NO TAMANHO ESCOLHIDO
                printf("\nDIGITE POSICAO DA SUA MUSICA[1-5000]:");   // ESCOLHER A POSIÇÃO DA SUA MUSICS (1~5000)
		        scanf("%d", &codigo);// RECEBE POSIÇÃO SELECIONADA
		 
		        MUSICACOPIAPILHA= get(novodesc, codigo); // UMA STRUCT COPIAMUSICA É FEITO USANDO AS INFORMAÇÕES TRAZIDA PELO GET (POISÇÕES)
		        MUSICAPILHA = copiamusica(MUSICACOPIAPILHA); // CHAMA FUNÇÃO COM AS INFORMAÇÕES ORIGNAIS E FAZ UMA COPIA 
		        nodopilha = CrianodoPILHA(MUSICAPILHA); // INSERE AS INFORMAÇÕES STRUCT MUSICA EM NÓS
		        novodescPILHA = InserirPILHA(novodescPILHA, nodopilha); // AQUI ENTRA NO DESCRITOR E AMARRA OS NÓS COM AS INFO MUSICA
		         }
		         break;
		       }
		      break;

		case 4:
		    buscarNome(novodesc); //CRIADO UMA FUNÇÃO PARA BUSCAR UMA MUSICA POR NOME NO ACERVO ORIGNAL
	   
        break;

		case 5:	
		  printf("\nInsira o codigo da musica: ");
          scanf("%d", &codigo);
          buscaCodigo(novodesc, codigo); // CRIADO UMA FUNÇÃO PARA BUSCAR QUALQUER MUSICA DO ACERVO COM O CODIGO ESPECIFICO
	     break;

		case 6:	
  			buscarTitulo(novodesc); // FUNÇÃO CRIADA PARA BUSCAR POR TITULO NO ACERVO
		  break;

		case 7:	
			  imprime(novodesc); // IMPRIME O ACERVO TOTAL DAS MUSICAS (5000) ELEMENTOS
		  break;

        case 8:
          imprimeFILA(novodescFILA); // IMPRIME A PLAYLISTA FEITA COM FILA (ALEATORIA USANDO SRAND)
		break;
    

		case 9:
          imprimePILHA(novodescPILHA);// IMPRIME A PLAYLISTA FEITA COM PILHA ( ESCOLHA PESSOAL USANDO A POSIÇÕES DAS MUSICAS DO ACERVO ORIGNAL) (1~5000)
					break;			

		case 10:
		printf("SAINDO DO SISTEMA!\n");					
					break;			
								
		default :
		printf("OPÇÃO INVALIDA!");
		break ;
		
		}
	}while(op != 10);

	return 0;
}
