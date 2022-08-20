/*
PROJETO MERCADO COM TAD
Data 06/05/2022
Matheus Fagundes de Oliveira (matheusoliveira.aluno@unipampa.edu.br)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mercado.h"

//INSERIR PRODUTO
 struct produto *inserirproduto(struct produto *novoproduto, int quantidadeProdutosMaxima, int  quantidadeAtual, int  quantidadeprodutoinserir){
  int i;
   
   if((quantidadeAtual == quantidadeProdutosMaxima) || (quantidadeAtual + quantidadeprodutoinserir > quantidadeProdutosMaxima)){
	   printf("ESTOQUE CHEIO!!\n");
	  }else
		for(i=quantidadeAtual; (i<quantidadeAtual+quantidadeprodutoinserir); i++){
	    printf("\n---NOVO PRODUTO---\n");
		setbuf(stdin,NULL);
		printf("digite o nome do produto: ");
		scanf("%[^\n]s", novoproduto[i].nomeproduto);
        printf("digite o valor do produto: R$ ");
        scanf("%f", &novoproduto[i].preco);
	 	printf("digite a quantidade desse produto no estoque: ");
		setbuf(stdin,NULL);
		scanf("%d", &novoproduto[i].quant);
		printf("digite o setor do produto [alimentos=1, carnes=2, padaria=3, bebidas=4, limpeza=5]: ");
		int tipoDigitado;
		setbuf(stdin,NULL);		
		scanf("%d",&tipoDigitado);
		novoproduto[i].tipo = tipoDigitado;	  
	  } 
       quantidadeAtual = quantidadeAtual + quantidadeprodutoinserir;
      
      return novoproduto;
};
//CADA PRODUTO
void imprimeumproduto(struct produto novoproduto){
        printf("\nProduto \n");
        printf("+++++++++++++++++++++++\n");
        printf("Nome do produto:        %s\n",novoproduto.nomeproduto);
        printf("Quantidade no estoque:  %d\n",novoproduto.quant);
        printf("Valor do produto:       R$ %.2f\n",novoproduto.preco);
        printf("Setor:\t\t\t\t\t");

			switch(novoproduto.tipo){
				case 1:
					printf("Alimentos\n");
					break;
				case 2:
					printf("carnes\n");
					break;
				case 3:
					printf("padaria\n");
					break;
				case 4:
					printf("bebidas\n");
					break;
				case 5:
					printf("limpeza\n");
					break;
	        }
				printf("TIPO : %d\n",novoproduto.tipo);	
       printf("\n");
 };
//IMPRIMIR PRODUTO
void imprimeproduto(struct produto *novoproduto, int quantidadeAtual){	
	int  i;
	if(quantidadeAtual == 0){
		printf("ESTOQUE VAZIO!!\n");
	}else
	for(i=0;i<quantidadeAtual;i++){
		imprimeumproduto(novoproduto[i]);
	}	
      printf("\n");
};
//BUSCA POR PRODUTO
void BuscarProduto(struct produto *novoproduto, int quantidadeAtual){
  int i;
  char nomeprod[15];
	  
				printf("NOME DO PRODUTO: ");
				fflush(stdin);
				scanf("%s", nomeprod);
				fflush(stdin);
				for(i=0;i<quantidadeAtual;i++){
					if(strcmp(nomeprod, novoproduto[i].nomeproduto) == 0){
              imprimeumproduto(novoproduto[i]);
		        }else{
            printf("\nNÃO TEM NO ESTOQUE!!\n");
            }
        }
      printf("\n");
  };
  //BUSCA POR SETOR
 void BuscarSetor(struct produto *novoproduto, int quantidadeAtual){
 int i;
 int a;
  
printf("ESCOLHA SETOR DOS PRODUTOS[alimentos=1, carnes=2, padaria=3, bebidas=4, limpeza=5]: ");
		 fflush(stdin);
		 scanf("%d", &a);
		 fflush(stdin);
		 for(i=0;i<quantidadeAtual;i++){
          if(a == novoproduto[i].tipo){
            imprimeumproduto(novoproduto[i]);
          }else{
            printf("\nNÃO TEM NO ESTOQUE!!\n");
            }
  }
      printf("\n");
} 
//VENDAS
void VenderProduto(struct produto *novoproduto, int quantidadeAtual){
    int produtovendido;
    char nomeprod[15];
		printf("\nVender Qual produto: ");
		scanf("%s", nomeprod);
		
		for(int i=0;i<quantidadeAtual; i++){
			if(strcmp(nomeprod, novoproduto[i].nomeproduto) == 0){
				printf("Quant no estoque: %d\n Preco: R$%.2f\n", novoproduto[i].quant, novoproduto[i].preco);
				printf("\nQuantos do estoque sera vendido: ");
				scanf("%d", &produtovendido);	  
			    if(novoproduto[i].quant >= produtovendido){
				novoproduto[i].quant -= produtovendido;
        }else{
        printf("\nQuantidade maior de vendas que possuiu no estoque!!\n");
        }
      }
}
}

//BALANÇO
float somatoria(struct produto *novoproduto, int quantidadeAtual, float soma){
 soma += novoproduto[quantidadeAtual].quant *novoproduto[quantidadeAtual].preco;
 if(quantidadeAtual==0){
	 return soma;
 }else{
	 return somatoria(novoproduto, quantidadeAtual-1, soma);
 }
 } 


