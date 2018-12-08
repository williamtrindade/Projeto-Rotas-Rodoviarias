/*
 *  Funções com as interfaces gráficas
 */
int menu() {
    int op;
    printf("\tROTAS\n");
    printf("2 - CADASTRAR CIDADE\n");
    // printf("3 - CONSULTAR CIDADE");
    // printf("4 - REMOVER CIDADE / CAMINHO");
    // printf("5 - ALTERAR CIDADE");
    // printf("6 - VISUALIZAR CIDADE");
    // printf("7 - VISUALIZAR ROTAS");
    // printf("8 - DIJKSTRA");
    printf("9 - SAIR");
    printf("> ");
    scanf("%d", &op);
    return op;
}