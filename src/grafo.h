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

Cidade *cadastrarCidade(Cidade *cidade, char nome[]) {
    Cidade *novo;
    novo = (Cidade*) malloc(sizeof(Cidade));
    strcpy(novo->nome, nome);
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
}

Cidade *inicializa(Cidade *cidade) {
    cidade = cadastrarCidade(cidade, "Passo Fundo");
    cidade = cadastrarCidade(cidade, "POA");
    cidade = cadastrarCidade(cidade, "Pelotas");
    cidade = cadastrarCidade(cidade, "Bage");
    cidade = cadastrarCidade(cidade, "Sao Gabriel");
    cidade = cadastrarCidade(cidade, "Alegrete");
    cidade = cadastrarCidade(cidade, "Sao Borja");
    cidade = cadastrarCidade(cidade, "Santiago");
    cidade = cadastrarCidade(cidade, "Cruz Alta");
    cidade = cadastrarCidade(cidade, "SM");  
    return cidade;
}

int verificarCidade(Cidade *cidade, char nome[]) {
    Cidade *p;
    for(p=cidade;p!=NULL;p=p->prox) {
        if (strcmp(p->nome, nome) == 0) return 1; 
    }
    return 0;
}