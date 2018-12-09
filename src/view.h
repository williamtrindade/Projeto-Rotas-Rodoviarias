/*
 *  Funções com as interfaces gráficas
 */
int menu() {

    int op;
    printf("\tROTAS\n");
    printf("1 - CADASTRAR CIDADE\n");
    printf("2 - CADASTRAR CAMINHO\n");
    printf("3 - CONSULTAR CIDADE / CAMINHO\n");
    printf("4 - REMOVER CIDADE\n"); // remove os caminhos tambem
    printf("5 - REMOVER CAMINHO"); 
    //  printf("6 - VISUALIZAR CIDADE"); // 
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

Cidade *mostrarRotasCidade(Cidade *cidade) {
    Caminho *c;
    printf("\tROTAS > CONSULTAR CIDADE > %s \n", cidade->nome);
    printf("DESTINOS\n\n");
        printf("NOME DA CIDADE | DISTANCIA\n\n");
    for(c=cidade->aresta;c!=NULL;c=c->prox){
        puts(c->cidade->nome);
        printf("%d\n\n", c->distancia);
    }

    system("pause");
    return cidade;
}