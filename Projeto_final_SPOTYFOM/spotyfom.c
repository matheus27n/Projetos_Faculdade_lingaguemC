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

Descritor *CriadescLISTA(){ //INICIAR O DESCRITOR DA LISTA ENCADEADA
    Descritor *Desc_lista = (Descritor*)malloc(sizeof(Descritor));
    Desc_lista->Lista = NULL;
    Desc_lista->tamanho = 0;
    return Desc_lista;
};

Nodo *CrianodoLISTA(Musica *novamusica){///INICIAR O NO DA LISTA ENCADEADA
    Nodo *novoNo = (Nodo*)malloc(sizeof(Nodo));
    novoNo->info = novamusica;
    novoNo->prox = NULL;
    return novoNo;
};

Musica *CriamusicaLISTA(char *novotitulo, char *novoartista, char *novaletra, int codigo, int execucoes){ // INICIA A MUSICA PELA LISTA ENCADEADA
   Musica *novamusica = (Musica*)malloc(sizeof(Musica));
   strcpy(novamusica->titulo, novotitulo);
   strcpy(novamusica->artista, novoartista);
   strcpy(novamusica->letra, novaletra);
   novamusica->codigo = codigo;
   novamusica->execucoes = execucoes;
   return novamusica;
};

//INSERIR LISTA ENCADEADA
void insere(Descritor *Desc_lista, Nodo *novoNo, int posicao){ // INSERIR NA LISTA ENCADEACA 
    if((Desc_lista->Lista == NULL) || (posicao == 0)){ //INICIO
        Desc_lista->Lista = novoNo;
        Desc_lista->tamanho++;
    }else{
        Nodo *aux = Desc_lista->Lista;
        int listaPos = 0;
        if(Desc_lista->tamanho < posicao){
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novoNo;
            Desc_lista->tamanho++;
            return;
        }else{
            Nodo *anterior;
            while(aux != NULL){
                anterior = aux;
                aux = aux->prox;
                listaPos++;
                if(listaPos == posicao){
                    novoNo->prox = aux;
                    anterior->prox = novoNo;
                    Desc_lista->tamanho++;
                    return;
                }

            }
        }
    }
};

//IMPRIMIR LISTA ENCADEADA
void imprime(Descritor *Desc_lista){ // IMPRIME A LISTA QUE CONTEM O ARCEVO 
  Nodo *aux = Desc_lista->Lista;
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
  printf("A lista tem [%d] elementos", Desc_lista->tamanho);
  printf("\n");
};



//CARREGAR ARQUIVO TXT
Descritor *Carregartxt(){   //CODIGO BASE DO PROFESSOR
    int tamanhotxt;
    Nodo *nodotemp = NULL;
    Musica *musicatemp = NULL;
    Descritor *Acervo = NULL;
    Acervo = CriadescLISTA();
    char caractere;
    char frase[256];
    int n=0;
    FILE* arquivo;
    arquivo = fopen("musicas.txt", "r");

    if(arquivo == NULL){
       printf("não foi possivel abrir o arquivo\n");
       exit(-1);
    }
    fscanf(arquivo, "%d", &tamanhotxt);
    printf("Arquivo TXT importato com sucesso!\n");
    printf("tamanho do acervo sera de %d\n", tamanhotxt);
    //aloca a struct musica com o tamanho do acervo

    while((caractere = fgetc(arquivo))!= EOF){
        if(caractere != '\n'){ //caractere diferente de \n guarda em frase
            frase[n]=caractere;
            n++;
        }
        else{//encontrou \n
            if(n > 0){
                frase[n]='\0';
                musicatemp = LinhaMusica(frase,n);
                nodotemp = CrianodoLISTA(musicatemp);
                insere(Acervo, nodotemp, Acervo->tamanho+1);
            }
            n=0;
            frase[n]='\0';
        }
    }
    return Acervo;
};

//QUEBRA CACARTERES DE CADA LINHA DO ACERVO
Musica *LinhaMusica(char *frase, int n){
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    Musica *nodotemp = NULL;
     
    strcpy(artista, strtok(frase,";"));
    codigo = atoi(strtok(NULL,";"));
    strcpy(titulo, strtok(NULL,";"));
    strcpy(letra, strtok(NULL,";"));
    nodotemp = CriamusicaLISTA( titulo, artista,  letra,  codigo,  0);

   return nodotemp;
   
};


//BUSCA POR NOME 
void * buscarNome(Descritor *Desc_lista){
    Nodo *aux = Desc_lista->Lista;
    Musica *novamusica;
    char artista[256];
    printf("\nQual artista voce procura: ");
    scanf("%[^\n]s", artista);
    while (aux != NULL){
        if (strcmp(artista, aux->info->artista) == 0){
            printf("\n");
            printf(" Nome do Artista: [%s] ", aux->info->artista);
            printf("\n Nome da Musica: [%s] ", aux->info->titulo);
            printf("\n Letra da Musica: [%s] ", aux->info->letra);
            printf("\n Codigo da Musica: [%d] ", aux->info->codigo);
            printf("\n Quantas vezes ouviu: [%d] ", aux->info->execucoes);
            printf("\n");
        }
        aux = aux->prox;
    }
    return 0;
}

//BUSCA POR CODIGO
void * buscaCodigo(Descritor *Desc_lista ,int codigo){
    Nodo *aux = Desc_lista->Lista;
    while (aux != NULL){
        if (aux->info->codigo == codigo){
            printf("\n");
            printf(" Nome do Artista: [%s] ", aux->info->artista);
            printf("\n Nome da Musica: [%s] ", aux->info->titulo);
            printf("\n Letra da Musica: [%s] ", aux->info->letra);
            printf("\n Codigo da Musica: [%d] ", aux->info->codigo);
            printf("\n Quantas vezes ouviu: [%d] ", aux->info->execucoes);
            printf("\n");
        }
        aux = aux->prox;
    }
    return 0;
}

//BUSCAR POR TITULO
void * buscarTitulo(Descritor *Desc_lista){
    Nodo *aux = Desc_lista->Lista;
    Musica *novamusica;
    char titulo[256];
    printf("\nQual titulo voce procura: ");
    scanf("%[^\n]s", titulo);
    while (aux != NULL){
        if (strcmp(titulo, aux->info->titulo) == 0){
            printf("\n");
            printf(" Nome do Artista: [%s] ", aux->info->artista);
            printf("\n Nome da Musica: [%s] ", aux->info->titulo);
            printf("\n Letra da Musica: [%s] ", aux->info->letra);
            printf("\n Codigo da Musica: [%d] ", aux->info->codigo);
            printf("\n Quantas vezes ouviu: [%d] ", aux->info->execucoes);
            printf("\n");
        }
        aux = aux->prox;
    }
    return 0;
}









//////////////AQUI É TUDO SOBRE A FILA////////////////////

//DESCRITOR DA FILA
Descritorfila *CriadescritorFILA(){// CRIA UMA DESCRITOR SEPARADO PARA UTILIZAR A FILA
    Descritorfila * DescFILA =(Descritorfila*)malloc(sizeof(Descritorfila));
    DescFILA->tamanho = 0;
    DescFILA->head = NULL;
    DescFILA->tail = NULL;
    printf("FILA criada com sucesso!!\n");
    return DescFILA;
}

//NO DA FILA 
Nodofila * CrianodoFILA(Musica *novamusicafila){// CRIA O NÓ PARA CONSEGUIR COLOCAR AS INFO MUSICA
    Nodofila * Nofila = (Nodofila*)malloc(sizeof(Nodofila));
    Nofila->info = novamusicafila;
    Nofila->prox = NULL;
    Nofila->ant = NULL;
    return Nofila;
}

Musica *CriamusicaFILA(char *novotitulo, char *novoartista, char *novaletra, int codigo, int execucoes){ // // CRIA UMA MUSICA COM AS INFO
   Musica *novamusicafila = (Musica*)malloc(sizeof(Musica));
   strcpy(novamusicafila->titulo, novotitulo);
   strcpy(novamusicafila->artista, novoartista);
   strcpy(novamusicafila->letra, novaletra);
   novamusicafila->codigo = codigo;
   novamusicafila->execucoes = execucoes;
   return novamusicafila;
};

Descritorfila *InsereFILA(Nodofila * Nofila, Descritorfila * DescFILA){ //INSERE O NO COM A INFO JÁ DENTRO, NA FILA
    Nodofila * aux = NULL;
    if((DescFILA->tamanho  ==0) && (DescFILA->head)==NULL){
        DescFILA->head = Nofila;
        DescFILA->tail = Nofila;
        DescFILA->tamanho++;
        return DescFILA;
    }else{
        aux = DescFILA->tail;
        aux->prox = Nofila;
        aux->prox->ant = aux;
        DescFILA->tail = Nofila;
        DescFILA->tamanho++;
        return DescFILA;
    }
}

void *imprimeFILA(Descritorfila *DescFILA){ // ACESSA O DESCRITOR FILA ONDE CONHECE TODOS OS NÓS E IMPRIME TODOS ATÉ CHEGAR A NULL
    Nodofila *aux = DescFILA->head;
    while (aux != NULL){
        printf("\n");
            printf(" Nome do Artista: [%s] ", aux->info->artista);
            printf("\n Nome da Musica: [%s] ", aux->info->titulo);
            printf("\n Letra da Musica: [%s] ", aux->info->letra);
            printf("\n Codigo da Musica: [%d] ", aux->info->codigo);
            printf("\n Quantas vezes ouviu: [%d] ", aux->info->execucoes);
            printf("\n");
        aux = aux->prox;
    }
    return 0;
}

///////////GET
Musica *get(Descritor *Desc_lista, int posicao){ // ULTILIZO UMA FUNÇÃO GET PARA ENCONTRAR A POSIÇÃO DESEJADA DA MINHA MUSICA NO ACERVO
    Nodo *aux = NULL;
    if(Desc_lista->tamanho == 0){
        return NULL;
    }else{
         aux = Desc_lista->Lista;
        while((posicao>1) && (aux != NULL)){
         aux = aux->prox;
         posicao--;
        }
        return aux->info;
    }
}

//////////UMA COPIA DA MUSICA DO ACERVO
Musica *copiamusica(Musica *novamusica){
   
    Musica *copiamusica =  CriamusicaFILA(novamusica->titulo, novamusica->artista, novamusica->letra, novamusica->codigo, novamusica->execucoes);

    return copiamusica;
}









/////////////////////////////////////AQUI PRA BAIXO É TUDO PILHA\\\\\\\\\\\\\\\\\\\\\\\\\\\

DescritorPILHA* CriaDescritorPILHA(){ // CRIA UMA DESCRITOR SEPARADO PARA UTILIZAR A PILHA 
	DescritorPILHA* DescPILHA=(DescritorPILHA *)malloc(sizeof(DescritorPILHA));
	DescPILHA->tamanho = 0;
	DescPILHA->Pilha = NULL;
    printf("PILHA criada com sucesso!!\n");
	return DescPILHA;
};

NodoPILHA* CrianodoPILHA(Musica *novamusicaPILHA){ // CRIA O NÓ PARA CONSEGUIR COLOCAR AS INFO MUSICA
    NodoPILHA * NoPILHA = (NodoPILHA*)malloc(sizeof(NodoPILHA));
	NoPILHA->info = novamusicaPILHA;
	NoPILHA->prox = NULL;
	return NoPILHA;
};

Musica * Criamusica(char *tituloInfo, char *artistaInfo, char *letraInfo, char *generoInfo, int codigoInfo, int execucoesInfo){ // CRIA UMA MUSICA COM AS INFO
	Musica * novamusicaPILHA = (Musica*)malloc(sizeof(Musica));
     strcpy(novamusicaPILHA->titulo, tituloInfo);
     strcpy(novamusicaPILHA->artista, tituloInfo);
     strcpy(novamusicaPILHA->letra, tituloInfo);
     novamusicaPILHA->codigo = codigoInfo;
    novamusicaPILHA->execucoes = execucoesInfo;
   return novamusicaPILHA;
}

DescritorPILHA * InserirPILHA(DescritorPILHA *DescPILHA, NodoPILHA *NoPILHA){ // INSERE O NO COM A INFO JÁ DENTRO NA PILHA 
	NodoPILHA * aux = NULL;
	if((DescPILHA->tamanho==0) && (DescPILHA->Pilha==NULL)){
		DescPILHA->Pilha = NoPILHA;
		DescPILHA->tamanho++;
		return DescPILHA;
	}else{
        aux = DescPILHA->Pilha;
        DescPILHA->Pilha = NoPILHA;
        NoPILHA->prox = aux;
        DescPILHA->tamanho++;
        return DescPILHA;
	}
};

void * imprimePILHA(DescritorPILHA *DescPILHA){ // ACESSA O DESCRITOR PILHA ONDE CONHECE TODOS OS NÓS E IMPRIME TODOS ATÉ CHEGAR A NULL

    NodoPILHA*aux = DescPILHA->Pilha;
    	while (aux != NULL){
            printf("\n");
            printf(" Nome do Artista: [%s] ", aux->info->artista);
            printf("\n Nome da Musica: [%s] ", aux->info->titulo);
            printf("\n Letra da Musica: [%s] ", aux->info->letra);
            printf("\n Codigo da Musica: [%d] ", aux->info->codigo);
            printf("\n Quantas vezes ouviu: [%d] ", aux->info->execucoes);
            printf("\n");
        aux = aux->prox;
    }
    return 0;
};



/////////////////////////////////////////FUNÇÕES REMOVER PARA ULTILIZAR NA EXECUCAO DE CADA PLAYLIST///////////////////////////////////

DescritorPILHA * deletarpilha(DescritorPILHA *DescPILHA, int codigo, Descritor *Desc_lista){ //REMOVER PILHA 
    if(DescPILHA->tamanho == 0){
        printf("A PILHA esta vazia.\n");
        return DescPILHA;
    }else{
     NodoPILHA * aux = NULL;
     DescPILHA->Pilha = DescPILHA->Pilha->prox;
     DescPILHA->tamanho--;
     }
     Desc_lista->Lista->info->execucoes++;
    return DescPILHA;
    }


Descritorfila* deletfila(Descritorfila * DescFILA, int codigo, Descritor *Desc_lista){//REMOVE FILA
   if(DescFILA->tamanho == 0){
        printf("A PILHA esta vazia.\n");
        return DescFILA;
    }else{
    Nodofila *aux = DescFILA->head->prox;
    DescFILA->head->prox = aux->prox;
    DescFILA->head->ant = NULL;
    DescFILA->tamanho--;
    }
     Desc_lista->Lista->info->execucoes++;
    return DescFILA;
}