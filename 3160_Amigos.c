#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 51

// Estrutura do nó da lista encadeada
typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar um nó ao final da lista
void appendNode(Node** head, const char* name) {
    Node* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Função para inserir uma lista de nós antes de um nó específico
void insertBefore(Node** head, const char* targetName, Node* newListHead) {
    if (*head == NULL) return;

    // Caso o nó alvo seja o primeiro nó da lista
    if (strcmp((*head)->name, targetName) == 0) {
        Node* temp = *head;
        *head = newListHead;
        
        // Encontrar o último nó da nova lista e conectá-lo ao restante da lista
        Node* current = newListHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
        return;
    }

    // Procurar pelo nó alvo e inserir antes dele
    Node* current = *head;
    while (current->next != NULL && strcmp(current->next->name, targetName) != 0) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = newListHead;
        
        // Encontrar o último nó da nova lista e conectá-lo ao restante da lista
        Node* lastNode = newListHead;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = temp;
    }
}

// Função para imprimir a lista de amigos
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s", current->name);
        if (current->next != NULL) printf(" ");
        current = current->next;
    }
    printf("\n");
}

// Função para liberar a memória da lista
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    Node* friendList = NULL;
    Node* newFriendList = NULL;
    char targetFriend[MAX_NAME_LENGTH];
    
    // Leitura da lista atual de amigos
    while (scanf("%s", name) == 1) {
        appendNode(&friendList, name);
        if (getchar() == '\n') break;
    }

    // Leitura da nova lista de amigos
    while (scanf("%s", name) == 1) {
        appendNode(&newFriendList, name);
        if (getchar() == '\n') break;
    }

    // Leitura do nome do amigo alvo para indicação
    scanf("%s", targetFriend);
    
    // Atualizar a lista de amigos conforme a indicação
    if (strcmp(targetFriend, "nao") == 0) {
        // Caso não haja indicação, adiciona os novos amigos ao final da lista original
        Node* current = friendList;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newFriendList;
    } else {
        // Caso haja indicação, insere os novos amigos antes do amigo indicado
        insertBefore(&friendList, targetFriend, newFriendList);
    }

    // Imprimir a lista de amigos atualizada
    printList(friendList);

    // Liberar a memória alocada para as listas
    freeList(friendList);

    return 0;
}
