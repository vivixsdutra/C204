#include <iostream>
#include <vector>

using namespace std;

// Fun��o para criar a matriz de adjac�ncia
vector<vector<int> > criarMatrizAdjacencia(int N, const vector<pair<int, int> >& caminhos) {
    vector<vector<int> > matrizAdjacencia(N, vector<int>(N, 0)); // Inicializa a matriz com 0s
    for (int i = 0; i < caminhos.size(); ++i) {
        int A = caminhos[i].first;
        int B = caminhos[i].second;
        matrizAdjacencia[A - 1][B - 1] = 1; // Marca o caminho entre A e B como 1
        matrizAdjacencia[B - 1][A - 1] = 1; // Considerando os caminhos como bidirecionais
    }
    return matrizAdjacencia;
}

// Fun��o para imprimir a matriz de adjac�ncia
void imprimirMatrizAdjacencia(const vector<vector<int> >& matrizAdjacencia) {
    for (int i = 0; i < matrizAdjacencia.size(); ++i) {
        for (int j = 0; j < matrizAdjacencia[i].size(); ++j) {
            cout << matrizAdjacencia[i][j];
            if (j < matrizAdjacencia[i].size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int> > caminhos(M);
    for (int i = 0; i < M; ++i) {
        cin >> caminhos[i].first >> caminhos[i].second;
    }

    // Criar matriz de adjac�ncia
    vector<vector<int> > matrizAdjacencia = criarMatrizAdjacencia(N, caminhos);

    // Imprimir matriz de adjac�ncia
    imprimirMatrizAdjacencia(matrizAdjacencia);

    return 0;
}
