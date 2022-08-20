typedef struct musica{
    char titulo[256], artista[256], letra[256];
    char genero[10];
    int ano, execucoes;
}Musica;

typedef struct nodo{
    struct nodo *prox;
    Musica *info;
}Nodo;

typedef struct desc_queue{
    Nodo *Pilha;
    int tamanho;

}Descritor;

Descritor * CriaDescritor();
Nodo* Crianodo(Musica *novamusica);
Musica * Criamusica(char *tituloInf, char *artistaInf, char *letraInf, char *generoInf, int anoInf, int execucoesInf);
Descritor * push(Descritor *Desc, Nodo *noMusica);
Descritor * pop(Descritor *Desc);
int empty(Descritor *Desc);
void * TOP(Descritor *Desc);
void * imprimeLista(Descritor *Desc);
void *imprimeMusica(Nodo *aux);
Descritor * limpalista(Descritor *Desc);