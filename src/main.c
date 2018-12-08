/*
 * Trabalho 2 - Estrutura de Dados
 * CSI - UFSM - 2018/2
 * Prof: Jonas Gassen
 * Aluno: William Trindade
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"
#include "grafo.h"

int main(void) {
    // Cidade
    Cidade *cidade = NULL;
    cidade = inicializa(cidade);
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
                break;
            }
            case 3: {
                printf("\tROTAS > CONSULTAR CIDADE\n");
                cidade = consultarCidade(cidade);
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
