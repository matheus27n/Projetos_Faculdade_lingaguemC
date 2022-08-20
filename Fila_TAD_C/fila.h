typedef struct musica{
    char titulo[256], artista[256], letra[256];
    char genero[10];
    int ano, execucoes;
}Musica;

typedef struct nodo{
    struct nodo *prox;
    struct musica *info;
    struct nodo *ant;
}Nodo;

typedef struct desc_queue{
    struct nodo *head;
    struct nodo *tail;
    int tamanho;

}Descritor;

Descritor * Criadescritor();
Nodo * Crianodo(Musica *novamusica);
Musica * Criamusica(char *tituloInf, char *artistaInf, char *letraInf, char *generoInf, int anoInf, int execucoesInf);
Descritor * enqueue(Nodo * novoNodo, Descritor * Desc);
Descritor * dequeue(Descritor * Desc);
void * imprimeLista(struct desc_queue *base);
void * imprimeMusica(struct nodo *aux);
int empty(struct desc_queue *base);
Descritor *delet (Descritor *Desc);
void lenght(struct desc_queue *base);
