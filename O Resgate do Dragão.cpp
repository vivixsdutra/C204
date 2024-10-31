#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Fun��o para adicionar uma aresta ao grafo n�o direcionado
void adicionarAresta(vector<int>* adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Fun��o para encontrar o menor caminho entre a sala de entrada e a sala do drag�o
int menorCaminho(vector<int>* adj, int N, int entrada, int dragao) {
    vector<bool> visitado(N + 1, false);
    vector<int> distancia(N + 1, 0);

    queue<int> fila;
    fila.push(entrada);
    visitado[entrada] = true;

    while (!fila.empty()) {
        int salaAtual = fila.front();
        fila.pop();

        if (salaAtual == dragao) {
            return distancia[salaAtual] + 1;
        }

        for (int i = 0; i < adj[salaAtual].size(); ++i) {
            int salaAdjacente = adj[salaAtual][i];
            if (!visitado[salaAdjacente]) {
                visitado[salaAdjacente] = true;
                distancia[salaAdjacente] = distancia[salaAtual] + 1;
                fila.push(salaAdjacente);
            }
        }
    }

    return -1; // N�o h� caminho poss�vel
}

int main() {
    int N, M;
    cin >> N >> M;

    // Inicializa��o da lista de adjac�ncias
    vector<int>* adj = new vector<int>[N + 1];

    // Leitura das arestas
    int u, v;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        adicionarAresta(adj, u, v);
    }

    // Leitura da sala de entrada e sala do drag�o
    int entrada, dragao;
    cin >> entrada >> dragao;

    // Encontrar o menor caminho entre a sala de entrada e a sala do drag�o
    int menorDistancia = menorCaminho(adj, N, entrada, dragao);

    // Imprimir resultado
    if (menorDistancia == -1) {
        cout << "IMPOSSIVEL" << endl;
    } else {
        cout << menorDistancia << endl;
    }

    delete[] adj; // Liberar mem�ria alocada para a lista de adjac�ncias

    return 0;
}
