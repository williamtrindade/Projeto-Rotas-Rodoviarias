/*
 *  Funções com as interfaces gráficas
 */
int menu() {

    int op;
    printf("\tROTAS\n");
    printf("1 - CADASTRAR CIDADE\n\n");
    printf("2 - CADASTRAR CAMINHO\n\n");
    printf("3 - CONSULTAR CIDADE / CAMINHO\n\n");
    printf("4 - REMOVER CIDADE\n\n"); // remove os caminhos tambem
    printf("5 - REMOVER CAMINHO\n\n"); 
    printf("6 - EDITAR CIDADE\n\n");
    printf("7 - EDITAR ROTA\n\n");
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
    
    if(cidade->aresta != NULL) {
        for(c=cidade->aresta;c!=NULL;c=c->prox){
            puts(c->cidade->nome);
            printf("%d\n\n", c->distancia);
        }
    }else{
        printf("NADA PARA MOSTRAR!\n\n");
    }

    system("pause");
    return cidade;
}