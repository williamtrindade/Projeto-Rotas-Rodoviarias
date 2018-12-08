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
                        cadastrarRota(nomeUm, nomeDois, dist, cidade);// duas cidade encontradas
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
