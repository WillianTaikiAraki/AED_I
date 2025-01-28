#include <stdlib.h>
#include <stdio.h>

struct NoPilha {
    int dado;
    struct NoPilha* abaixo;
};

struct Pilha {
    int qtd;
    struct NoPilha* topo;
};

void empilhar(struct Pilha* p, int dado) {
    p->qtd += 1;
    struct NoPilha* novoTopo = (struct NoPilha*) malloc(sizeof(struct NoPilha));

    novoTopo->dado = dado;
    novoTopo->abaixo = p->topo;
    p->topo = novoTopo;
}

void desempilhar(struct Pilha* p) {
    if (p->qtd > 0) {
        p->qtd -= 1;
        struct NoPilha* topoAntigo = p->topo;
        p->topo = p->topo->abaixo;
        free(topoAntigo);
    }
}

int topo(struct Pilha* p) {
    return p->topo->dado;
}

int tamanho(struct Pilha* p) {
    return p->qtd;
}

int vazia(struct Pilha* p) {
    return p->qtd == 0;
}

void inicializar(struct Pilha* p) {
    p->qtd = 0;
    p->topo = NULL;
}

void destruir(struct Pilha* p) {
    while (!vazia(p)) {
        desempilhar(p);
    }
}

int main() {
    int totalVagoes, v;
    struct Pilha entrada, estacao, saida;

    while (scanf("%d", &totalVagoes) != EOF) {
        if (!totalVagoes) break;

        while (scanf("%d", &v)) {
            if (!v) {
                printf("\n");
                break;
            }

            inicializar(&entrada);
            inicializar(&estacao);
            inicializar(&saida);

            empilhar(&entrada, v);
            empilhar(&saida, 1);
            for (int i = 2; i <= totalVagoes; ++i) {
                scanf("%d", &v);
                empilhar(&entrada, v);
                empilhar(&saida, i);
            }

            while (!vazia(&entrada) || !vazia(&estacao) || !vazia(&saida)) {
                if (!vazia(&entrada) && !vazia(&saida) && topo(&entrada) == topo(&saida)) {
                    desempilhar(&entrada);
                    desempilhar(&saida);
                } else if (!vazia(&estacao) && !vazia(&saida) && topo(&estacao) == topo(&saida)) {
                    desempilhar(&estacao);
                    desempilhar(&saida);
                } else if (!vazia(&entrada)) {
                    empilhar(&estacao, topo(&entrada));
                    desempilhar(&entrada);
                } else {
                    break;
                }
            }

            if (vazia(&entrada) && vazia(&estacao) && vazia(&saida)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            destruir(&entrada);
            destruir(&estacao);
            destruir(&saida);
        }
    }

    return 0;
}
