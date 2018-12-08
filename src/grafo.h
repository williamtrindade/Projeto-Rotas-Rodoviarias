/*
 * Funções e estruturas relacionadas aos grafos
 */
typedef struct x {
    char nome[50];
    struct y *areste; // cidades que ela tem caminho
    struct x *prox;   // proxima cidade
}Cidade;

typedef struct y {
    int distancia;    // distancia entra as cidade
    struct x *cidade; // cidade que é apontada
    struct y *prox;   // proxima aresta
}Caminho;

void inicializa() {
    
}

Cidade *cadastrarCidade(Cidade *cidade) {
    printf("\tROTAS > CADASTRAR CIDADE\n");
    Cidade *novo;
    novo = (Cidade*) malloc(sizeof(Cidade));
    printf("NOME: \n");
    // pergunta o nome enquanto o nome for nulo ou vazio
    do{
        fflush(stdin);
        gets(novo->nome);
        fflush(stdin);
    }while(novo->nome == "");

    // percorre a lista de cidade
    if(cidade == NULL) {
        novo->prox = NULL;
        return novo;
    }else {
        Cidade *p;
        for(p=cidade;p->prox!=NULL;p=p->prox);
        p->prox = novo;
        novo->prox = NULL;
        return cidade;
    }
    system("pause");
}