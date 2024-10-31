#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    // Alocando dinamicamente o vetor de inteiros com tamanho N
    int *vetor = new int[N];

    // Ponteiro para percorrer o vetor
    int *p = vetor;

    // Lendo os elementos e inserindo no vetor usando o ponteiro
    for (int i = 0; i < N; ++i) {
        cin >> *p;
        p++; // Avan�a o ponteiro para a pr�xima posi��o do vetor
    }

    // Reinicializa o ponteiro para o in�cio do vetor
    p = vetor;

    // Varrendo o vetor usando o ponteiro e exibindo os elementos
    for (int i = 0; i < N; ++i) {
        cout << *p << " ";
        p++; // Avan�a o ponteiro para a pr�xima posi��o do vetor
    }

    // Liberando a mem�ria alocada
    delete[] vetor;

    return 0;
}
