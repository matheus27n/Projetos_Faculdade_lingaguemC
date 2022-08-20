/*
PROJETO MERCADO COM TAD
Data 06/05/2022
Matheus Fagundes de Oliveira (matheusoliveira.aluno@unipampa.edu.br)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mercado.h"

int main(void){
  struct produto *novoproduto = NULL;
  int quantidadeProdutosMaxima = 0, quantidadeAtual = 0, quantidadeprodutoinserir = 0;
  int op;



 printf("Total de produtos no mercado: ");
 setbuf(stdin,NULL); //limpa o buffer da entrada
 scanf("%d", &quantidadeProdutosMaxima);
 novoproduto = (struct produto*)malloc(quantidadeProdutosMaxima * sizeof(struct produto));
  
  while(op!=0){
    printf("\n--MENU DO MERCADO--\n");
    printf("---------------------\n");
    printf("1: Inserir produtodos: \n");
    printf("2: Todos produtos estoque: \n");
    printf("3: Procurar por nome: \n");
    printf("4: Buscar por setor: \n");
    printf("5: vendas: \n");
    printf("6: balanco: \n");
    printf("0.Encerrar sistema\n");
    printf("OPCAO: ");

    setbuf(stdin,NULL); //limpa o buffer da e'ntrada
		scanf("%d", &op);

    switch(op){
			case 0:
					return 0;
			case 1: //INSERIR PRODUTO
		    printf("Quando produtos voce quer inserir: ");
            scanf("%d", &quantidadeprodutoinserir);
            novoproduto = inserirproduto(novoproduto, quantidadeProdutosMaxima, quantidadeAtual, quantidadeprodutoinserir);
            quantidadeAtual = quantidadeAtual + quantidadeprodutoinserir;
			break;
			
			case 2: //IMPRIMIR PRODUTOS
			imprimeproduto(novoproduto, quantidadeAtual);
			break;
			
			case 3: //BUSCAR POR NOME
			BuscarProduto(novoproduto, quantidadeAtual);
			break;
			
			case 4://BUSCAR POR SETOR
			BuscarSetor(novoproduto, quantidadeAtual);
			break;
			
			case 5: //VENDER PRODUTO
			VenderProduto(novoproduto, quantidadeAtual);
			break;
			
			case 6: //BALANÇO DE VENDAS
			printf("\nValor em estoque do mercado: R$%.2f\n", somatoria(novoproduto, quantidadeAtual, 0));
			break;

    }
  }
 
    return 0;
}
