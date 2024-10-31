#include <stdio.h>
#include <stdlib.h>

// Estrutura do n� da �rvore
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Fun��o para criar um novo n�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fun��o para inserir um novo valor na �rvore
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Fun��o para calcular a soma de todos os elementos da �rvore
int somaElementos(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + somaElementos(root->left) + somaElementos(root->right);
}

// Fun��o para contar a quantidade total de n�s na �rvore
int contarNos(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + contarNos(root->left) + contarNos(root->right);
}

// Fun��o para calcular a m�dia dos elementos da �rvore
float media(Node* root) {
    int soma = somaElementos(root);
    int quantidade = contarNos(root);
    if (quantidade == 0) {
        return 0;
    }
    return (float)soma / quantidade;
}

// Fun��o principal
int main() {
    Node* root = NULL;
    int value;

    // Leitura dos valores de entrada at� -1
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        root = insert(root, value);
    }

    // Calcular e imprimir a m�dia
    printf("Media: %.2f\n", media(root));

    return 0;
}
