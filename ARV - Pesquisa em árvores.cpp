#include <iostream>
using namespace std;

// Defini��o da estrutura para representar um n� da �rvore
struct No {
    int valor;
    No* esquerda;
    No* direita;

    No(int val) : valor(val), esquerda(NULL), direita(NULL) {}
};

// Fun��o para inserir um n�mero na �rvore
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return new No(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

// Fun��o para buscar um n�mero na �rvore
bool buscar(No* raiz, int valor) {
    if (raiz == NULL) {
        return false;
    }
    if (raiz->valor == valor) {
        return true;
    } else if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

int main() {
    int N, X;
    cin >> N;
    No* raiz = NULL;

    // Inserindo os N n�meros na �rvore
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        raiz = inserir(raiz, num);
    }

    // Lendo o n�mero X a ser procurado
    cin >> X;

    // Verificando se X est� na �rvore
    if (buscar(raiz, X)) {
        cout << "Encontrado" << endl;
    } else {
        cout << "Nao encontrado" << endl;
    }

    return 0;
}
