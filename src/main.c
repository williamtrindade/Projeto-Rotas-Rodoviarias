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
                printf("\nCIDADE CADASTRADA COM SUCESSO!: \n");
                system("pause");
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
                        cidade = cadastrarRota(nomeDois, nomeUm, dist, cidade);// duas cidade encontradas
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
                char nome[50];

                do {
                    printf("\nDIGITE UM NOME PARA CONSULTAR: \n");
                    fflush(stdin);
                    gets(nome);
                }while(strcmp(nome, "") == 0);

                Cidade *resultadoBuscaCidade = buscaCidade(cidade, nome);

                if(resultadoBuscaCidade != NULL) {
                    system("cls");
                    resultadoBuscaCidade = mostrarRotasCidade(resultadoBuscaCidade);
                }else {
                    printf("\nCIDADE NAO EXISTE \n");
                    system("pause");
                }
                break;
            }

            case 4:{
                printf("\tROTAS > REMOVER CIDADE\n");
                cidade = consultarCidades(cidade);
                char nome[50];
                do {
                    printf("\nDIGITE UM NOME PARA REMOVER: \n");
                    fflush(stdin);
                    gets(nome);
                }while(strcmp(nome, "") == 0);
                Cidade *resultadoBuscaCidade = buscaCidade(cidade, nome);

                if(resultadoBuscaCidade != NULL) {
                    cidade = removerCidade(cidade, nome);
                    printf("\nCIDADE REMOVIDA!: \n");
                    system("pause");
                }else {
                    printf("\nCIDADE NAO EXISTE \n");
                    system("pause");
                }
                break;
            }
            case 5: {
                printf("\tROTAS > REMOVER CAMINHO\n");
                printf("\nDIGITE NOME DA ORIGEM : \n");
                char nomeUm[50], nomeDois[50];
                do {
                    fflush(stdin);
                    gets(nomeUm);
                }while(strcmp(nomeUm, "") == 0);
                int x = verificarCidade(cidade, nomeUm); // verifica se o nome da cidade existe
                if(x == 1) {
                    printf("\nDIGITE NOME DO DESTINO : \n");
                    do {
                        fflush(stdin);
                        gets(nomeDois);
                    }while(strcmp(nomeDois, "") == 0);
                    int x  = verificarCidade(cidade, nomeDois); // verifica se o nome da cidade existe
                    if(x == 1){
                        Cidade *o, *d;
                        o = buscaCidade(cidade, nomeUm);
                        Caminho *arestas;
                        // verifica se a rota existe
                        for(arestas=o->aresta;arestas!=NULL;arestas=arestas->prox) {
                            if(strcmp(arestas->cidade->nome, nomeDois)==0) {
                                d = buscaCidade(cidade, nomeDois);
                                o->aresta = removerCaminho(o->aresta, d->nome);
                                d->aresta = removerCaminho(d->aresta, o->nome);
                                printf("\nROTA REMOVIDA COM SUCESSO\n");
                                system("pause");
                            }
                        }
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
            case 6: {
                printf("\tROTAS > ALTERAR CIDADE\n");
                char nome[50];
                do {
                    printf("\nDIGITE NOME DA CIDADE QUE QUER ALTERAR : \n");
                    fflush(stdin);
                    gets(nome);
                }while(strcmp(nome, "") == 0);
                int x = verificarCidade(cidade, nome); // verifica se o nome da cidade existe
                if(x == 1) {    
                    char novoNome[50];
                    printf("\nDIGITE SEU NOVO NOME : \n");
                    gets(novoNome);
                    cidade = alterarCidade(cidade, nome, novoNome);
                    printf("\nCIDADE EDITADA!: \n");
                    system("pause");
                }else {
                    printf("\nESSA CIDADE NAO EXISTE\n");
                    system("pause");
                }
                break;
            }
            case 7: {
                printf("\tROTAS > ALTERAR ROTA\n");
                printf("\nDIGITE NOME DA ORIGEM : \n");
                char nomeUm[50], nomeDois[50];
                do {
                    fflush(stdin);
                    gets(nomeUm);
                }while(strcmp(nomeUm, "") == 0);
                int x = verificarCidade(cidade, nomeUm); // verifica se o nome da cidade existe
                if(x == 1) {
                    printf("\nDIGITE NOME DO DESTINO : \n");
                    do {
                        fflush(stdin);
                        gets(nomeDois);
                    }while(strcmp(nomeDois, "") == 0);
                    int x  = verificarCidade(cidade, nomeDois); // verifica se o nome da cidade existe
                    if(x == 1){
                        printf("\nDIGITE A DISTANCIA : \n");
                        int dist;
                        fflush(stdin);
                        scanf("%d", &dist);
                        cidade = alterarRota(cidade, nomeUm, nomeDois, dist);
                        cidade = alterarRota(cidade, nomeDois, nomeUm, dist);
                        printf("\nROTA EDITADA!: \n");
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
