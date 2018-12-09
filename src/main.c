/*
 * Trabalho 2 - Estrutura de Dados
 * CSI - UFSM - 2018/2
 * Prof: Jonas Gassen
 * Aluno: William Trindade
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "view.h"
#include "entrada.h"
int main(void) {
    // Cidade
    Cidade *cidade = NULL;
    cidade = inicializa(cidade);
    cidade = cadastrarRota("Passo Fundo", "POA", 289, cidade);
    cidade = cadastrarRota("POA", "Pelotas", 261, cidade);
    cidade = cadastrarRota("Pelotas", "Bage", 189, cidade);
    cidade = cadastrarRota("Bage", "Sao Gabriel", 268, cidade);
    cidade = cadastrarRota("Sao Gabriel", "Alegrete", 204, cidade);
    cidade = cadastrarRota("Alegrete", "Sao Borja", 315, cidade);
    cidade = cadastrarRota("Sao Borja", "Santiago", 141, cidade);
    cidade = cadastrarRota("Santiago", "Cruz Alta", 242, cidade);
    cidade = cadastrarRota("Cruz Alta", "Passo Fundo", 149, cidade);
    cidade = cadastrarRota("Cruz Alta", "SM", 134, cidade);
    cidade = cadastrarRota("SM", "Santiago", 152, cidade);
    cidade = cadastrarRota("SM", "Alegrete", 258, cidade);
    cidade = cadastrarRota("SM", "Sao Gabriel", 182, cidade);
    cidade = cadastrarRota("SM", "Bage", 239, cidade);
    cidade = cadastrarRota("SM", "POA", 291, cidade);
    cidade = cadastrarRota("POA", "Bage", 377, cidade);
	while(1) {
        system("cls");
        int op = menu();
        system("cls");
        switch(op) {

            case 1: {
                printf("\tROTAS > CADASTRAR CIDADE\n");
                // pergunta o nome enquanto o nome for nulo ou vazio
                char nome[50];
                do{
                    printf("NOME: ");
                    fflush(stdin);
                    gets(nome);
                }while(strcmp(nome, "") == 0);
                cidade = cadastrarCidade(cidade, nome);
                break;
            }

            case 2: {
                printf("\tROTAS > CADASTRAR CAMINHO\n");
                printf("\nDIGITE NOME DA ORIGEM : \n");
                char nomeUm[50], nomeDois[50];
                do {
                    printf("NOME: ");
                    fflush(stdin);
                    gets(nomeUm);
                }while(strcmp(nomeUm, "") == 0);
                int x = verificarCidade(cidade, nomeUm); // verifica se o nome da cidade existe
                if(x == 1) {
                    printf("\nDIGITE NOME DO DESTINO : \n");
                    do {
                        printf("NOME: ");
                        fflush(stdin);
                        gets(nomeDois);
                    }while(strcmp(nomeDois, "") == 0);
                    int x  = verificarCidade(cidade, nomeDois); // verifica se o nome da cidade existe
                    if(x == 1){
                        printf("\nDIGITE A DISTANCIA : \n");
                        int dist;
                        fflush(stdin);
                        scanf("%d", &dist);
                        cidade = cadastrarRota(nomeUm, nomeDois, dist, cidade);// duas cidade encontradas
                        printf("\nROTA CADASTRADA!: \n");
                        system("pause");
                    }else {
                        printf("\nESSA CIDADE NAO EXISTE\n");
                        system("pause");
                    }
                }else {
                    printf("\nESSA CIDADE NAO EXISTE\n");
                    system("pause");
                }
                break;
            }

            case 3: {
                printf("\tROTAS > CONSULTAR CIDADE\n");
                cidade = consultarCidades(cidade);
                printf("\nDIGITE UM NOME PARA CONSULTAR: \n");
                char nome[50];
                do {
                    printf("NOME: ");
                    fflush(stdin);
                    gets(nome);
                }while(strcmp(nome, "") == 0);
                break;
            }

            case 9: {
                return 0;
                break;
            }

            default:
                break;
        }

    }
	return 0;
}
