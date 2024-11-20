#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID 1000000

typedef struct Node {
    int id;
    struct Node *prox;
} Node;

typedef struct {
    Node *inicio;
    Node *fim;
} Lista;

void inicializaLista(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

void insereFim(Lista *lista, int id) {
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo == NULL) {
        exit(EXIT_FAILURE);
    }
    novo->id = id;
    novo->prox = NULL;
    if (lista->fim == NULL) {
        lista->inicio = novo;
    } else {
        lista->fim->prox = novo;
    }
    lista->fim = novo;
}

void removeIds(Lista *lista, int *tabelaRemocoes) {
    Node *atual = lista->inicio;
    Node *anterior = NULL;

    while (atual != NULL) {
        if (tabelaRemocoes[atual->id]) {
            if (anterior == NULL) {
                lista->inicio = atual->prox;
                if (lista->inicio == NULL) {
                    lista->fim = NULL;
                }
            } else {
                anterior->prox = atual->prox;
                if (atual == lista->fim) {
                    lista->fim = anterior;
                }
            }
            Node *temp = atual;
            atual = atual->prox;
            free(temp);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

void imprimeLista(Lista *lista) {
    Node *atual = lista->inicio;
    int primeiro = 1;
    while (atual != NULL) {
        if (!primeiro) {
            printf(" ");
        }
        printf("%d", atual->id);
        primeiro = 0;
        atual = atual->prox;
    }
    printf("\n");
}

void limpaLista(Lista *lista) {
    Node *atual = lista->inicio;
    while (atual != NULL) {
        Node *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->inicio = lista->fim = NULL;
}

int main() {
    int n, m, id;

    scanf("%d", &n);
    Lista fila;
    inicializaLista(&fila);

    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        if (id < 0 || id > MAX_ID) {
            return 1;
        }
        insereFim(&fila, id);
    }

    scanf("%d", &m);
    int *tabelaRemocoes = (int *)calloc(MAX_ID + 1, sizeof(int));
    if (tabelaRemocoes == NULL) {
        return 1;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &id);
        if (id < 0 || id > MAX_ID) {
            free(tabelaRemocoes);
            return 1;
        }
        tabelaRemocoes[id] = 1;
    }

    removeIds(&fila, tabelaRemocoes);
    imprimeLista(&fila);

    limpaLista(&fila);
    free(tabelaRemocoes);

    return 0;
}
