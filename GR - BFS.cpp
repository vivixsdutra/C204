#include <iostream>
#include <list>
#include <queue>

using namespace std;

// Estrutura para representar um n� do grafo
struct no {
    int v; // v�rtice adjacente
    int peso; // peso da aresta (opcional)
};

// Fun��o para realizar o percurso em largura (BFS)
void bfs(list<no> adj[], int nVertices, int s) {
    char state[nVertices]; // estado de cada v�rtice: 'u' (n�o descoberto), 'd' (descoberto), 'p' (processado)
    int pai[nVertices]; // pai de cada v�rtice no percurso

    // Inicializa os estados e os pais de todos os v�rtices
    for (int u = 0; u < nVertices; ++u) {
        if (u != s) {
            state[u] = 'u'; // undiscovered
            pai[u] = -1; // sem pai
        }
    }

    state[s] = 'd'; // descobre o v�rtice inicial
    pai[s] = -1;

    // Fila para armazenar os v�rtices a serem processados
    queue<int> Q;
    Q.push(s);

    // Realiza o percurso em largura
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        cout << u << endl; // Imprime o v�rtice atual

        // Processa todos os v�rtices adjacentes a u
        for (list<no>::iterator p = adj[u].begin(); p != adj[u].end(); ++p) {
            int v = p->v; // V�rtice adjacente

            // Se o v�rtice adjacente ainda n�o foi descoberto, o descobre e o adiciona � fila
            if (state[v] == 'u') {
                state[v] = 'd';
                pai[v] = u;
                Q.push(v);
                cout << u << " " << v << endl; // Imprime a aresta (u, v)
            }
        }

        state[u] = 'p'; // Marca o v�rtice como processado
    }
}

int main() {
    int nVertices, verticeInicial;
    cin >> nVertices >> verticeInicial;

    // Lista de adjac�ncias para representar o grafo
    list<no> adj[nVertices];

    // Leitura das arestas do grafo
    int origem, destino, peso;
    while (true) {
        cin >> origem >> destino >> peso;
        if (origem == -1 && destino == -1 && peso == -1) {
            break; // Condi��o de sa�da
        }
        // Adiciona a aresta (origem, destino) ao grafo
        no novaAresta;
        novaAresta.v = destino;
        novaAresta.peso = peso;
        adj[origem].push_back(novaAresta);
        novaAresta.v = origem;
        adj[destino].push_back(novaAresta); // Se o grafo � n�o direcionado, adiciona a aresta no sentido oposto tamb�m
    }

    // Realiza o percurso em largura a partir do v�rtice inicial
    bfs(adj, nVertices, verticeInicial);

    return 0;
}
