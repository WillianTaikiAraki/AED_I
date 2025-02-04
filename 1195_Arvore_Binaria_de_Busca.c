#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *leftChild, *rightChild;
} TreeNode;

TreeNode* createTreeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->leftChild = newNode->rightChild = NULL;
    return newNode;
}

void insertIntoTree(TreeNode** root, int data) {
    if (!(*root)) { 
        *root = createTreeNode(data);
        return;
    }
    if (data < (*root)->data) {
        insertIntoTree(&((*root)->leftChild), data);
    } else {
        insertIntoTree(&((*root)->rightChild), data);
    }
}

void traversePreorder(TreeNode* root) {
    if (root) {
        printf(" %d", root->data);
        traversePreorder(root->leftChild);
        traversePreorder(root->rightChild);
    }
}

void traverseInorder(TreeNode* root) {
    if (root) {
        traverseInorder(root->leftChild);
        printf(" %d", root->data);
        traverseInorder(root->rightChild);
    }
}

void traversePostorder(TreeNode* root) {
    if (root) {
        traversePostorder(root->leftChild);
        traversePostorder(root->rightChild);
        printf(" %d", root->data);
    }
}

void deallocateTree(TreeNode* root) {
    if (root) {
        deallocateTree(root->leftChild);
        deallocateTree(root->rightChild);
        free(root);
    }
}

int main() {
    int numCases, numElements, elementValue;
    scanf("%d", &numCases);

    for (int caseNum = 1; caseNum <= numCases; ++caseNum) {
        scanf("%d %d", &numElements, &elementValue);
        TreeNode* root = createTreeNode(elementValue);

        for (int i = 1; i < numElements; ++i) {
            scanf("%d", &elementValue);
            insertIntoTree(&root, elementValue);
        }

        printf("Case %d:\n", caseNum);
        printf("Pre.:");
        traversePreorder(root);
        printf("\nIn..:");
        traverseInorder(root);
        printf("\nPost:");
        traversePostorder(root);
        printf("\n\n");

        deallocateTree(root);
    }

    return 0;
}
