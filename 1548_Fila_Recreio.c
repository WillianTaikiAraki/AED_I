#include <stdio.h>
#include <stdlib.h>


//Estrutura de nós da fila encadeada
typedef struct No{
    int nota_aluno;
    struct No *prox;
} No;


//Funcao para criar um novo Nó
No* criarNo(int nota_aluno){
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->nota_aluno = nota_aluno;
    novoNo->prox = NULL;
    return novoNo;
}


//Funcao para adicionar um nó no final da lista
void adicionarNo(No **cabeca, int nota_aluno){
    No *novoNo = criarNo(nota_aluno);
    if (*cabeca == NULL){
        *cabeca = novoNo;
    } else {
        No *noAtual = *cabeca;
        while (noAtual->prox != NULL){
            noAtual = noAtual->prox;
        }
        noAtual->prox = novoNo;
    }
}


//Funcao para copiar uma lista encadeada
No* copiarLista(No *cabeca){
    No *novaCabeca = NULL;
    No *noAtual = cabeca;
    while(noAtual != NULL){
        adicionarNo(&novaCabeca, noAtual->nota_aluno);
        noAtual = noAtual->prox;
    }
    return novaCabeca;
}



//Funcao para ordenar uma lista encadeada de forma decrescente (maior nota para a menor)
void sortListaDecrescente(No **cabeca){
    if (*cabeca == NULL || (*cabeca)->prox == NULL) return;

    No *noAtual, *index;
    int temp;

    for (noAtual = *cabeca; noAtual != NULL; noAtual = noAtual->prox){
        for (index = noAtual->prox; index != NULL; index = index->prox){
            if (noAtual->nota_aluno < index->nota_aluno){
                // Ocorre a troca dos valores
                temp = noAtual->nota_aluno;
                noAtual->nota_aluno = index->nota_aluno;
                index->nota_aluno = temp;
            }
        }
    }
}


//Funcao para contar quantos alunos (nós) nao tiveram mudanca de posicao 
int contagemMudancaPos(No *listaOriginal, No *sorted){
    int contagem = 0;

    while (listaOriginal != NULL && sorted != NULL){
        if (listaOriginal->nota_aluno == sorted->nota_aluno){
            contagem++;
        }
        listaOriginal = listaOriginal->prox;
        sorted = sorted->prox;
    }
    return contagem;
}


// Função para liberar a memória de uma lista encadeada
void freeLista(No *cabeca) {
    No *temp;
    while (cabeca != NULL) {
        temp = cabeca;
        cabeca = cabeca->prox;
        free(temp);
    }
}


int main(){
    int casos_teste;
    scanf("%d", &casos_teste);

    for (int i = 0; i < casos_teste; i++){
        int num_alunos;
        scanf("%d", &num_alunos);

        No *listaOriginal = NULL;

        //Lê as notas dos alunos e adiciona a lista
        for (int j = 0; j < num_alunos; j++){
            int nota;
            scanf("%d", &nota);
            adicionarNo(&listaOriginal, nota);
        }

        // Copia a lista original
        No *sorted = copiarLista(listaOriginal);

        // Ordena a cópia da lista em ordem decrescente
        sortListaDecrescente(&sorted);

        // Conta quantos alunos não mudaram de posição
        int naoMudanca = contagemMudancaPos(listaOriginal, sorted);

        // Imprime o resultado
        printf("%d\n", naoMudanca);

        // Libera a memória das listas
        freeLista(listaOriginal);
        freeLista(sorted);

    }

    return 0;
}
