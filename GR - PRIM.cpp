#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;

// Estrutura para representar uma aresta
struct Aresta {
    int origem;
    int destino;
    int peso;
};

// Fun��o para adicionar uma aresta ao grafo n�o direcionado
void adicionarAresta(list<Aresta>* adj, int origem, int destino, int peso) {
    Aresta a;
    a.origem = origem;
    a.destino = destino;
    a.peso = peso;
    adj[origem].push_back(a);
    a.origem = destino; // Para grafo n�o direcionado
    a.destino = origem;
    adj[destino].push_back(a);
}

// Fun��o para encontrar a �rvore geradora m�nima usando o algoritmo de Prim
vector<Aresta> prim(list<Aresta>* adj, int nVertices, int start) {
    vector<bool> intree(nVertices, false);
    vector<int> distance(nVertices, INT_MAX);
    vector<int> parent(nVertices, -1);

    distance[start] = 0;
    int v = start;

    while (!intree[v]) {
        intree[v] = true;
        for (int i = 0; i < nVertices; ++i) {
            for (list<Aresta>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
                int destino = it->destino;
                int peso = it->peso;
                if (!intree[destino] && distance[destino] > peso) {
                    distance[destino] = peso;
                    parent[destino] = v;
                }
            }
        }
        v = 0;
        int dist = INT_MAX;
        for (int u = 0; u < nVertices; ++u) {
            if (!intree[u] && dist > distance[u]) {
                dist = distance[u];
                v = u;
            }
        }
    }

    // Armazenar as arestas da �rvore geradora m�nima
    vector<Aresta> mst;
    int custoTotal = 0;
    for (int i = 0; i < nVertices; ++i) {
        if (parent[i] != -1) {
            Aresta a;
            a.origem = parent[i];
            a.destino = i;
            a.peso = distance[i];
            mst.push_back(a);
            custoTotal += distance[i];
        }
    }

    // Imprimir as arestas da �rvore geradora m�nima
    cout << "Arvore Geradora Minima:" << endl;
    for (int i = 0; i < mst.size(); ++i) {
        cout << mst[i].origem << " " << mst[i].destino << endl;
    }
    cout << "Custo: " << custoTotal << endl;

    return mst;
}

int main() {
    int numVertices, orientado, start;
    cin >> numVertices >> orientado >> start;

    // Inicializa��o da lista de adjac�ncias
    list<Aresta>* adj = new list<Aresta>[numVertices];

    int origem, destino, peso;
    while (true) {
        cin >> origem >> destino >> peso;
        if (origem == -1 && destino == -1 && peso == -1) {
            break;
        }
        adicionarAresta(adj, origem, destino, peso);
    }

    // Encontrar a �rvore geradora m�nima usando o algoritmo de Prim
    prim(adj, numVertices, start);

    delete[] adj; // Liberar mem�ria alocada para a lista de adjac�ncias

    return 0;
}
