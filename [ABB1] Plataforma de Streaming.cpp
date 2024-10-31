#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura para armazenar informa��es do filme
typedef struct Filme {
    char nome[100];
    char genero[50];
    int duracao;
    int classificacao;
    int ano;
} Filme;

// Estrutura do n� da �rvore
typedef struct Node {
    Filme filme;
    struct Node* left;
    struct Node* right;
} Node;

// Fun��o para criar um novo n�
Node* createNode(Filme filme) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->filme = filme;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fun��o para inserir um novo filme na �rvore
Node* insert(Node* root, Filme filme) {
    if (root == NULL) {
        return createNode(filme);
    }
    if (strcmp(filme.nome, root->filme.nome) < 0) {
        root->left = insert(root->left, filme);
    } else if (strcmp(filme.nome, root->filme.nome) > 0) {
        root->right = insert(root->right, filme);
    }
    return root;
}

// Fun��o para buscar um filme na �rvore pelo nome
Node* search(Node* root, char* nome) {
    if (root == NULL || strcmp(root->filme.nome, nome) == 0) {
        return root;
    }
    if (strcmp(nome, root->filme.nome) < 0) {
        return search(root->left, nome);
    } else {
        return search(root->right, nome);
    }
}

// Fun��o para imprimir as informa��es de um filme
void printFilme(Filme filme) {
    printf("Nome: %s\n", filme.nome);
    printf("Genero: %s\n", filme.genero);
    printf("Duracao: %d mins\n", filme.duracao);
    printf("Classificacao: %d\n", filme.classificacao);
    printf("Ano: %d\n", filme.ano);
}

// Fun��o principal
int main() {
    setlocale(LC_ALL, "");

    Node* root = NULL;
    int opcao;
    
    do {
        scanf("%d", &opcao);
        if (opcao == 1) {
            Filme filme;
            getchar(); // Consome o newline ap�s a leitura do inteiro
            fgets(filme.nome, 100, stdin);
            filme.nome[strcspn(filme.nome, "\n")] = '\0'; // Remove o newline do final
            fgets(filme.genero, 50, stdin);
            filme.genero[strcspn(filme.genero, "\n")] = '\0'; // Remove o newline do final
            scanf("%d", &filme.duracao);
            scanf("%d", &filme.classificacao);
            scanf("%d", &filme.ano);
            root = insert(root, filme);
        } else if (opcao == 2) {
            char nome[100];
            getchar(); // Consome o newline ap�s a leitura do inteiro
            fgets(nome, 100, stdin);
            nome[strcspn(nome, "\n")] = '\0'; // Remove o newline do final
            Node* resultado = search(root, nome);
            if (resultado != NULL) {
                printFilme(resultado->filme);
            } else {
                printf("Filme nao encontrado\n");
            }
        } else if (opcao != 0) {
            printf("Operacao invalida\n");
        }
    } while (opcao != 0);
    
    return 0;
}
