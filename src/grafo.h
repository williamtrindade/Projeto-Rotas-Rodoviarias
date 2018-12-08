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

void cadastrarRota(char origem[], char destino[], int distancia, Cidade *cidade) {
    Caminho *novo;
    novo = (Caminho*) malloc(sizeof(Caminho));

    Cidade *o, *d;
    Caminho *c;
    for(o=cidade;o!=NULL;o=o->prox) { // procura a origem
        // encontrada a origem
        if(strcmp(o->nome, origem) == 0) {
            // encontra o destino
            for(d=cidade;d!=NULL && (strcmp(d->nome, destino) != 0); d=d->prox);
            if(o->areste==NULL) {
                novo->prox = NULL;
                novo->cidade = d; // coloca o destino na aresta(caminho)
                novo->distancia = distancia;
                o->areste = novo; // coloco a nova cidade(destino) na lista de arestas no p(origem)
            } else {
                for(c=o->areste;c->prox!=NULL;c=c->prox) {
                    novo->prox = NULL;
                    novo->cidade = d; 
                    novo->distancia = distancia;
                    c->prox = novo;
                }
            }
            
        }
    }
}