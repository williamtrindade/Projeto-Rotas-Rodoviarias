/*
 * Funções e estruturas relacionadas aos grafos
 */
typedef struct y {
    int distancia;    // distancia entra as cidade
    struct x *cidade; // cidade que é apontada
    struct y *prox;   // proxima aresta
}Caminho;

typedef struct x {
    char nome[50];
    struct y *aresta; // cidades que ela tem caminho
    struct x *prox;   // proxima cidade
}Cidade;



Cidade *cadastrarCidade(Cidade *cidade, char nome[]) {
    Cidade *novo;
    novo = (Cidade*) malloc(sizeof(Cidade));
    strcpy(novo->nome, nome);
    // percorre a lista de cidade
    if(cidade == NULL) {
        novo->prox = NULL;
        novo->aresta = NULL;
        return novo;
    }else {
        Cidade *p;
        for(p=cidade;p->prox!=NULL;p=p->prox);
        p->prox = novo;
        novo->prox = NULL;
        novo->aresta=NULL;
        return cidade;
    }
}

Cidade *buscaCidade(Cidade *cidade, char nome[]) {
    Cidade *p;
    for(p=cidade;p!=NULL;p=p->prox) {
        if (strcmp(p->nome, nome) == 0) return p; 
    }
    return NULL;
}

int verificarCidade(Cidade *cidade, char nome[]) {
    Cidade *p;
    for(p=cidade;p!=NULL;p=p->prox) {
        if (strcmp(p->nome, nome) == 0) return 1; 
    }
    return 0;
}

Cidade *cadastrarRota(char origem[], char destino[], int distancia, Cidade *cidade) {
    Caminho *novo;
    novo = (Caminho*) malloc(sizeof(Caminho));

    Cidade *o, *d;
    Caminho *c;
    
    o = buscaCidade(cidade, origem);
    d = buscaCidade(cidade, destino);

    if(o->aresta == NULL) {
        novo->prox=NULL;
        novo->cidade=d;
        novo->distancia=distancia;
        o->aresta = novo;
        return cidade;
    }else {
        for(c=o->aresta;c->prox!=NULL;c=c->prox);
        novo->prox=NULL;
        novo->cidade=d;
        novo->distancia=distancia;
        c->prox = novo;
        return cidade;
    }    
}

Cidade *cadastrarRotaIniciais(char origem[], char destino[], int distancia, Cidade *cidade) {
    cidade = cadastrarRota(origem, destino, distancia, cidade);
    cidade = cadastrarRota(destino, origem, distancia, cidade);
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