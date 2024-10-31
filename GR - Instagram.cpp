#include <iostream>
#include <list>

using namespace std;

// Fun��o para imprimir os seguidores de um usu�rio
void imprimirSeguidores(string nomes[], const list<int> grafo[], int usuario, int N) {
    // Verifica se o usu�rio existe
    if (usuario >= N) {
        cout << "Usu�rio n�o encontrado" << endl;
        return;
    }

    // Imprime os nomes dos seguidores do usu�rio
    cout << "Seguidores de " << nomes[usuario] << ":" << endl;
    for (list<int>::const_iterator it = grafo[usuario].begin(); it != grafo[usuario].end(); ++it) {
        cout << nomes[*it] << endl;
    }
}

int main() {
    int N;
    cin >> N;

    // Vetor para armazenar os nomes dos usu�rios
    string nomes[N];
    for (int i = 0; i < N; ++i) {
        cin.ignore(); // Limpa o buffer de entrada
        getline(cin, nomes[i]);
    }

    // Vetor de listas para representar o grafo
    list<int> grafo[N];

    // Leitura dos seguidores de cada usu�rio
    int seguidor;
    for (int i = 0; i < N; ++i) {
        while (true) {
            cin >> seguidor;
            if (seguidor == -1) {
                break;
            }
            grafo[seguidor].push_back(i); // i segue seguidor
        }
    }

    // Usu�rio para verificar os seguidores
    int usuario_desejado;
    cin >> usuario_desejado;

    // Imprime os seguidores do usu�rio desejado
    imprimirSeguidores(nomes, grafo, usuario_desejado, N);

    return 0;
}
