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
    inicializa();
	while(1) {
        system("cls");
        int op = menu();
        switch (op) {
            case 2:
                cidade = cadastrarCidade(cidade);
                break;
            case 9:
                return 0;
                break;
            default:
                break;
        }
    }
	return 0;
}
