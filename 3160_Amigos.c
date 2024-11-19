//nomes das funcoes e variaveis em PT para facilitar entendimento

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAX_NOME 51

// Estrutura do nó da lista encadeada
typedef struct No {
    char nome[TAMANHO_MAX_NOME];
    struct No* proximo;
} No;

// Função para criar um novo nó
No* criarNo(const char* nome) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->nome, nome);
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para adicionar um nó ao final da lista
void adicionarNo(No** cabeca, const char* nome) {
    No* novoNo = criarNo(nome);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        No* atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

// Função para inserir uma lista de nós antes de um nó específico
void inserirAntes(No** cabeca, const char* nomeAlvo, No* novaListaCabeca) {
    if (*cabeca == NULL) return;

    // Caso o nó alvo seja o primeiro nó da lista
    if (strcmp((*cabeca)->nome, nomeAlvo) == 0) {
        No* temp = *cabeca;
        *cabeca = novaListaCabeca;
        
        // Encontrar o último nó da nova lista e conectá-lo ao restante da lista
        No* atual = novaListaCabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = temp;
        return;
    }

    // Procurar pelo nó alvo e inserir antes dele
    No* atual = *cabeca;
    while (atual->proximo != NULL && strcmp(atual->proximo->nome, nomeAlvo) != 0) {
        atual = atual->proximo;
    }

    if (atual->proximo != NULL) {
        No* temp = atual->proximo;
        atual->proximo = novaListaCabeca;
        
        // Encontrar o último nó da nova lista e conectá-lo ao restante da lista
        No* ultimoNo = novaListaCabeca;
        while (ultimoNo->proximo != NULL) {
            ultimoNo = ultimoNo->proximo;
        }
        ultimoNo->proximo = temp;
    }
}

// Função para imprimir a lista de amigos
void imprimirLista(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        printf("%s", atual->nome);
        if (atual->proximo != NULL) printf(" ");
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para liberar a memória da lista
void liberarLista(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

int main() {
    char nome[TAMANHO_MAX_NOME];
    No* listaAmigos = NULL;
    No* novaListaAmigos = NULL;
    char amigoAlvo[TAMANHO_MAX_NOME];
    
    // Leitura da lista atual de amigos
    while (scanf("%s", nome) == 1) {
        adicionarNo(&listaAmigos, nome);
        if (getchar() == '\n') break;
    }

    // Leitura da nova lista de amigos
    while (scanf("%s", nome) == 1) {
        adicionarNo(&novaListaAmigos, nome);
        if (getchar() == '\n') break;
    }

    // Leitura do nome do amigo alvo para indicação
    scanf("%s", amigoAlvo);
    
    // Atualizar a lista de amigos conforme a indicação
    if (strcmp(amigoAlvo, "nao") == 0) {
        // Caso não haja indicação, adiciona os novos amigos ao final da lista original
        No* atual = listaAmigos;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novaListaAmigos;
    } else {
        // Caso haja indicação, insere os novos amigos antes do amigo indicado
        inserirAntes(&listaAmigos, amigoAlvo, novaListaAmigos);
    }

    // Imprimir a lista de amigos atualizada
    imprimirLista(listaAmigos);

    // Liberar a memória alocada para as listas
    liberarLista(listaAmigos);

    return 0;
}
