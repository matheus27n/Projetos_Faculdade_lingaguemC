enum setor{Alimentos = 1, Carnes, Padaria, Bebidas, Limpeza};

struct produto{
    char nomeproduto[15];
    float preco;
    int quant;
    enum setor tipo;
};

 struct produto *inserirproduto(struct produto *novoproduto, int quantidadeProdutosMaxima, int  quantidadeAtual, int  quantidadeprodutoinserir);
 void imprimeumproduto(struct produto novoproduto);
 void imprimeproduto(struct produto *novoproduto, int quantidadeAtual);
 void BuscarProduto(struct produto *novoproduto, int quantidadeAtual);
 void BuscarSetor(struct produto *novoproduto, int quantidadeAtual);
 void VenderProduto(struct produto *novoproduto, int quantidadeAtual);
 float somatoria(struct produto *novoproduto, int quantidadeAtual, float soma);
