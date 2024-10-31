#include <iostream>

using namespace std;

int main() {
    const int num_terras = 5; // N�mero fixo de terras
    int terras[num_terras];   // Vetor para armazenar os artefatos m�gicos das terras

    // Leitura dos valores dos artefatos m�gicos para cada terra
    for (int i = 0; i < num_terras; ++i) {
        cin >> terras[i];
    }

    // Inicializa��o do ponteiro para percorrer o vetor de terras
    int *p = terras;

    // Vari�vel para armazenar a soma total dos artefatos coletados
    int soma_total = 0;

    // Percorre o vetor de terras usando o ponteiro
    for (int i = 0; i < num_terras; ++i) {
        cout << "Artefato coletado na terra " << i << ": " << *p << endl;
        soma_total += *p;
        p++; // Avan�a o ponteiro para a pr�xima terra
    }

    // Exibe a soma total dos artefatos coletados
    cout << "Fim da jornada! Soma total dos artefatos: " << soma_total << endl;

    return 0;
}

