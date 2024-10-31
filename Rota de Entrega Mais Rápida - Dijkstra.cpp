#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;

// Estrutura para representar uma aresta
struct Aresta {
    int destino;
    int tempo;
};

// Fun��o para adicionar uma aresta ao grafo direcionado
void adicionarAresta(list<Aresta>* adj, int origem, int destino, int tempo) {
    Aresta a;
    a.destino = destino;
    a.tempo = tempo;
    adj[origem].push_back(a);
}

// Fun��o para implementar o algoritmo de Dijkstra
int dijkstra(list<Aresta>* adj, int nCidades, int origem, int destino) {
    vector<bool> intree(nCidades, false);
    vector<int> tempo(nCidades, INT_MAX);

    tempo[origem] = 0;
    int v = origem;

    while (!intree[v]) {
        intree[v] = true;
        for (int i = 0; i < nCidades; ++i) {
            for (list<Aresta>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
                int destino = it->destino;
                int t = it->tempo;
                if (tempo[destino] > tempo[v] + t) {
                    tempo[destino] = tempo[v] + t;
                }
            }
        }
        v = 0;
        int menorTempo = INT_MAX;
        for (int u = 0; u < nCidades; ++u) {
            if (!intree[u] && menorTempo > tempo[u]) {
                menorTempo = tempo[u];
                v = u;
            }
        }
    }

    return tempo[destino];
}

int main() {
    int N, M;
    cin >> N >> M;

    // Inicializa��o da lista de adjac�ncias
    list<Aresta>* adj = new list<Aresta>[N];

    int u, v, t;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v >> t;
        adicionarAresta(adj, u - 1, v - 1, t); // Ajustar �ndices para come�ar de 0
        adicionarAresta(adj, v - 1, u - 1, t); // Para rede n�o direcionada
    }

    int A, B;
    cin >> A >> B;
    A--; // Ajustar �ndice para come�ar de 0
    B--; // Ajustar �ndice para come�ar de 0

    // Encontrar o tempo m�nimo de viagem de A para B usando Dijkstra
    int tempoMinimo = dijkstra(adj, N, A, B);

    cout << tempoMinimo << endl;

    delete[] adj; // Liberar mem�ria alocada para a lista de adjac�ncias

    return 0;
}
