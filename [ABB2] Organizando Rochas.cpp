#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura para armazenar informa��es da rocha
typedef struct Rocha {
    char nome[100];
    char tipo[50];
} Rocha;

// Estrutura do n� da �rvore
typedef struct Node {
    Rocha rocha;
    struct Node* left;
    struct Node* right;
} Node;

// Fun��o para criar um novo n�
Node* createNode(Rocha rocha) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->rocha = rocha;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fun��o para inserir uma nova rocha na �rvore
Node* insert(Node* root, Rocha rocha) {
    if (root == NULL) {
        return createNode(rocha);
    }
    if (strcmp(rocha.nome, root->rocha.nome) < 0) {
        root->left = insert(root->left, rocha);
    } else if (strcmp(rocha.nome, root->rocha.nome) > 0) {
        root->right = insert(root->right, rocha);
    }
    return root;
}

// Fun��o para buscar uma rocha na �rvore pelo nome
Node* search(Node* root, char* nome) {
    if (root == NULL || strcmp(root->rocha.nome, nome) == 0) {
        return root;
    }
    if (strcmp(nome, root->rocha.nome) < 0) {
        return search(root->left, nome);
    } else {
        return search(root->right, nome);
    }
}

// Fun��o para encontrar o n� m�nimo na �rvore
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Fun��o para remover uma rocha da �rvore
Node* removeNode(Node* root, Rocha rocha, int* removed) {
    if (root == NULL) {
        return NULL;
    }
    if (strcmp(rocha.nome, root->rocha.nome) < 0) {
        root->left = removeNode(root->left, rocha, removed);
    } else if (strcmp(rocha.nome, root->rocha.nome) > 0) {
        root->right = removeNode(root->right, rocha, removed);
    } else {
        if (strcmp(rocha.tipo, root->rocha.tipo) != 0) {
            *removed = 0;
            return root;
        }

        *removed = 1;
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
        root->rocha = temp->rocha;
        root->right = removeNode(root->right, temp->rocha, removed);
    }
    return root;
}

// Fun��o para imprimir as informa��es de uma rocha
void printRocha(Rocha rocha) {
    printf("Nome: %s\n", rocha.nome);
    printf("Tipo: %s\n", rocha.tipo);
}

// Fun��o principal
int main() {
    setlocale(LC_ALL, "");

    Node* root = NULL;
    int opcao;
    
    do {
        scanf("%d", &opcao);
        if (opcao == 1) {
            Rocha rocha;
            getchar(); // Consome o newline ap�s a leitura do inteiro
            fgets(rocha.nome, 100, stdin);
            rocha.nome[strcspn(rocha.nome, "\n")] = '\0'; // Remove o newline do final
            fgets(rocha.tipo, 50, stdin);
            rocha.tipo[strcspn(rocha.tipo, "\n")] = '\0'; // Remove o newline do final
            root = insert(root, rocha);
        } else if (opcao == 2) {
            char nome[100];
            getchar(); // Consome o newline ap�s a leitura do inteiro
            fgets(nome, 100, stdin);
            nome[strcspn(nome, "\n")] = '\0'; // Remove o newline do final
            Node* resultado = search(root, nome);
            if (resultado != NULL) {
                printRocha(resultado->rocha);
            } else {
                printf("Rocha nao encontrada\n");
            }
        } else if (opcao == 3) {
            Rocha rocha;
            getchar(); // Consome o newline ap�s a leitura do inteiro
            fgets(rocha.nome, 100, stdin);
            rocha.nome[strcspn(rocha.nome, "\n")] = '\0'; // Remove o newline do final
            fgets(rocha.tipo, 50, stdin);
            rocha.tipo[strcspn(rocha.tipo, "\n")] = '\0'; // Remove o newline do final
            int removed = 0;
            root = removeNode(root, rocha, &removed);
            if (removed) {
                printf("Rocha removida com sucesso\n");
            } else {
                printf("Rocha nao encontrada para remocao\n");
            }
        } else if (opcao != 0) {
            printf("Opera��o inv�lida\n");
        }
    } while (opcao != 0);
    
    return 0;
}
