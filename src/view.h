/*
 *  Funções com as interfaces gráficas
 */
int menu() {

    int op;
    printf("\tROTAS\n");
    printf("1 - CADASTRAR CIDADE\n");
    printf("2 - CADASTRAR ROTA\n");
    printf("3 - CONSULTAR CIDADE / ROTA\n");
    // printf("4 - REMOVER CIDADE / ROTA");
    // printf("5 - ALTERAR CIDADE");
    // printf("6 - VISUALIZAR CIDADE");
    // printf("7 - VISUALIZAR ROTAS");
    // printf("8 - DIJKSTRA");
    printf("9 - SAIR\n");
    printf("> ");
    scanf("%d", &op);
    return op;
}

Cidade *consultarCidades(Cidade *cidade) {
    Cidade *p;
    printf("NOME\n\n");
    for(p=cidade;p!=NULL;p=p->prox) {
        puts(p->nome);
    }
    return cidade;
}