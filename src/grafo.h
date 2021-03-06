/*
 * Funções e estruturas relacionadas aos grafos
 */
typedef struct y {
    int distancia;    // distancia entra as cidade
    struct x *cidade; // cidade que é apontada
    struct y *prox;   // proxima aresta
}Caminho;

typedef struct x {
    int visitado;
    char nome[50];
    struct y *aresta; // cidades que ela tem caminho
    struct x *prox;   // proxima cidade
}Cidade;

void mensagem(char msg[50]) {
    printf("\n%s\n", msg);
    system("pause");
}

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

// remove as arestas
Caminho *removerCaminho(Caminho *arestas, char nome[]) {
    Caminho *cam, *ant;
    ant = NULL;
    cam = arestas;
    if(arestas->prox == NULL) {
        free(arestas);
        return NULL;
    }
    while(cam != NULL && strcmp(cam->cidade->nome, nome)!=0){
		ant = cam;
		cam = cam->prox;
	}
	if(cam == NULL) {
		return arestas;
	}
	if(ant == NULL){
		arestas = cam->prox;
	}else{
		ant->prox = cam->prox;
	}
    free(cam);
    return arestas;
}

// remove da lista de cidades
Cidade *removerCidade(Cidade *cidade, char nome[]) {
    Cidade *p;
    Caminho *k;
    for(p=cidade;p!=NULL;p=p->prox) {
        for(k=p->aresta;k!=NULL;k=k->prox){
            if(strcmp(k->cidade->nome, nome) == 0) {
                p->aresta = removerCaminho(p->aresta, k->cidade->nome);
            }
        }
    }
    Cidade *cid, *ant;
    ant = NULL;
    cid=cidade;
    Caminho *cam;
    while(cid != NULL && strcmp(cid->nome, nome)!=0){
		ant = cid;
		cid = cid->prox;
	}
	if(cid == NULL) {
		return cidade;
	}
	if(ant == NULL){
		cidade = cid->prox;
	}else{
		ant->prox = cid->prox;
	}
	free(cid);
    return cidade;
}

Cidade *alterarCidade(Cidade *cidade, char nome[], char novoNome[]) {
    Cidade *cid;
    cid = buscaCidade(cidade, nome);
    strcpy(cid->nome, novoNome);
    return cidade;
}

Cidade *alterarRota(Cidade *cidade, char nomeUm[], char nomeDois[], int distancia) {
    Cidade *cid;
    Caminho *c;
    cid = buscaCidade(cidade, nomeUm);
    for(c=cid->aresta;c!=NULL;c=c->prox) {
        if(strcmp(c->cidade->nome, nomeDois) == 0) {
            c->distancia = distancia;
        }
    }
    return cidade;
}

// busca caminho
Cidade *buscaCaminho(Cidade *origem, Cidade *destino) { // passa a origem e destino
    puts(origem->nome); // imprime a origem
    origem->visitado=1;
    Caminho *c;
    if(origem->aresta == NULL || origem == NULL) return NULL; // se a origem for NULL ou nao tiver arestas(caminhos) sai
    if(origem == destino) return destino; // verifica se achou se sim desempilha

    Caminho *v;
    for(v=origem->aresta;v!=NULL;v=v->prox) {
        if(v->cidade->visitado!=1) {
            origem = buscaCaminho(v->cidade, destino);
        }
    }   
    return origem;
}

void marcaNaoVisitado(Cidade *cidade) {
    Cidade *c;
    for(c=cidade;c!=NULL;c=c->prox) c->visitado = 0;
}