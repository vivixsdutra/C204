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

// Fun��o para encontrar o n� m�nimo na �rvore
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Fun��o para remover um valor da �rvore
Node* removeNode(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        root->left = removeNode(root->left, data);
    } else if (data > root->data) {
        root->right = removeNode(root->right, data);
    } else {
        // N� com apenas um filho ou nenhum
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // N� com dois filhos
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

// Fun��o para buscar um valor na �rvore
int search(Node* root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return 1;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Fun��o para imprimir a �rvore em ordem crescente (ordem sim�trica)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Fun��o principal
int main() {
    Node* root = NULL;
    int value;

    // Leitura dos valores de entrada at� 0
    while (1) {
        scanf("%d", &value);
        if (value == 0) {
            break;
        }
        root = insert(root, value);
    }

    // Leitura do valor a ser removido
    int x;
    scanf("%d", &x);

    // Remover todos os n�s cujo valor � igual a x
    while (search(root, x)) {
        root = removeNode(root, x);
    }

    // Imprimir os elementos restantes em ordem crescente
    inorder(root);
    printf("\n");

    return 0;
}
