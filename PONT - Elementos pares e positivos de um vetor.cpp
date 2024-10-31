#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    // Alocando dinamicamente o vetor de inteiros com tamanho N
    int *vetor = new int[N];

    // Lendo os elementos e inserindo no vetor
    for (int i = 0; i < N; ++i) {
        cin >> vetor[i];
    }

    // Inicializando o contador de elementos pares e positivos
    int pares_positivos = 0;

    // Varrendo o vetor usando um ponteiro e contando os elementos pares e positivos
    for (int i = 0; i < N; ++i) {
        if (vetor[i] > 0 && vetor[i] % 2 == 0) {
            pares_positivos++;
        }
    }

    // Exibindo o n�mero de elementos pares e positivos
    cout << pares_positivos << endl;

    // Liberando a mem�ria alocada
    delete[] vetor;

    return 0;
}
