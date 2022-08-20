struct musica{
  char titulo[256];
  char artista[256];
  char letra[256];
  int codigo;
  int execucoes;
};

struct desc_LSE{
  struct nodo *LSE;
  int tamanho;
};

struct nodo{
  struct nodo *prox;
  struct musica *info;
};

struct desc_LSE *criaDesc(void);
struct nodo *criaNodo(struct musica * minhaMusica);
struct musica *iniciaMusica(char *novotitulo, char *novoartista, char *novaletra, int codigo, int execucoes);

struct nodo *removeLista(struct desc_LSE *minha_LSE, int posicao);
void insere(struct desc_LSE *minha_LSE, struct nodo *novoelemento, int posicao);
int tamanho(struct desc_LSE *minha_LSE);
void libera(struct desc_LSE *minha_LSE);
void imprime(struct desc_LSE *minha_LSE);
struct nodo *removeLista(struct desc_LSE *minhaLSE, int posicao);
void Consulta(struct desc_LSE *minha_LSE);

