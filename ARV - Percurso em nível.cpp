#include <stdio.h>
#include <stdlib.h>

// Estrutura do n� da �rvore
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Estrutura para representar um n� na fila
typedef struct QueueNode {
    Node* node;
    struct QueueNode* next;
} QueueNode;

// Estrutura para representar a fila
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Fun��o para criar um novo n� da �rvore
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fun��o para enfileirar um n� na fila
void enqueue(Queue* queue, Node* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Fun��o para desenfileirar um n� da fila
Node* dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    QueueNode* temp = queue->front;
    Node* node = temp->node;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return node;
}

// Fun��o para percorrer a �rvore em n�vel
void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    Queue queue;
    queue.front = queue.rear = NULL;
    enqueue(&queue, root);

    while (queue.front != NULL) {
        Node* current = dequeue(&queue);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(&queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(&queue, current->right);
        }
    }
}

// Fun��o para liberar a mem�ria da �rvore
void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
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
        if (root == NULL) {
            root = createNode(value);
        } else {
            Node* current = root;
            while (1) {
                if (value < current->data) {
                    if (current->left == NULL) {
                        current->left = createNode(value);
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == NULL) {
                        current->right = createNode(value);
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    // Percurso em n�vel
    levelOrderTraversal(root);
    printf("\n");

    // Liberar mem�ria da �rvore
    freeTree(root);

    return 0;
}
