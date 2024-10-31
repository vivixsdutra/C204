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

// Fun��o para contar o n�mero de folhas da �rvore
int contaFolhas(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1; // O n� � uma folha
    }
    return contaFolhas(root->left) + contaFolhas(root->right);
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

    // Contar o n�mero de folhas da �rvore
    printf("%d\n", contaFolhas(root));

    return 0;
}
