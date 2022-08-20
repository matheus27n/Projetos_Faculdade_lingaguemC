/*  
SPOTYFOM
Data 15/08/2022
Matheus Fagundes de Oliveira (matheusoliveira.aluno@unipampa.edu.br)
*/
//LISTA ENCADEADA
typedef struct Desc_LSE Descritor;
typedef struct nodo Nodo;
typedef struct musica Musica;

//FILA
typedef struct Nodo Nodofila;
typedef struct Desc_queue Descritorfila;

//PILHA
typedef struct nodop NodoPILHA;
typedef struct desc_queue DescritorPILHA;



//LISTA ENCADEADA
typedef struct Desc_LSE{
    Nodo *Lista;
    int tamanho;
}Descritor;

typedef struct nodo{
    Nodo *prox;
    Musica *info;
}Nodo;

typedef struct musica{
    char titulo[256], artista[256], letra[256];
    int codigo, execucoes;
}Musica;


////FILAAAA
typedef struct Nodo{
     Nodofila *prox;
     Musica *info;
     Nodofila *ant;
}Nodofila;

typedef struct Desc_queue{
    Nodofila *head;
    Nodofila *tail;
    int tamanho;
}Descritorfila;


//PILHA
typedef struct nodop{
    NodoPILHA *prox;
    Musica *info;
}NodoPILHA;

typedef struct desc_queue{
    NodoPILHA *Pilha;
    int tamanho;
}DescritorPILHA;




Descritor *CriadescLISTA();
Nodo *CrianodoLISTA(Musica *novamusica);
Musica *CriamusicaLISTA(char *novotitulo, char *novoartista, char *novaletra, int codigo, int execucoes);
void insere(Descritor *Desc_lista, Nodo *novoNo, int posicao);
void imprime(Descritor *Desc_lista);
Descritor *Carregartxt();
Musica *LinhaMusica(char *frase, int n);
void * buscarNome(Descritor *Desc_lista);
void * buscaCodigo(Descritor *Desc_lista ,int codigo);
void * buscarTitulo(Descritor *Desc_lista);



//FILAAA
Descritorfila * CriadescritorFILA();
Nodofila * CrianodoFILA(Musica *novamusica);
Musica *CriamusicaFILA(char *novotitulo, char *novoartista, char *novaletra, int codigo, int execucoes);
Descritorfila *InsereFILA(Nodofila * Nofila, Descritorfila * DescFILA);
void *imprimeFILA(Descritorfila *DescFILA);
//get
Musica *get(Descritor *Desc_lista, int posicao);
Musica *copiamusica(Musica *novamusica);




//PILHA
DescritorPILHA* CriaDescritorPILHA();
NodoPILHA* CrianodoPILHA(Musica *novamusicaPILHA);
Musica * Criamusica(char *tituloInfo, char *artistaInfo, char *letraInfo, char *generoInfo, int codigoInfo, int execucoesInfo);
DescritorPILHA * InserirPILHA(DescritorPILHA *DescPILHA, NodoPILHA *NoPILHA);
void * imprimePILHA(DescritorPILHA *DescPILHA);


//REMOVERES DAS PILHA,FILA E LISTA ENCADEADA
DescritorPILHA * deletarpilha(DescritorPILHA *DescPILHA, int codigo, Descritor *Desc_lista);//REMOVER PILHA 
Descritorfila* deletfila(Descritorfila * DescFILA, int codigo, Descritor *Desc_lista);//REMOVE FILA
