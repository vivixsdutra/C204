#include <iostream>
#include <list>

using namespace std;

// Estrutura para representar um n� da lista de adjac�ncias
struct No {
    int v;    // V�rtice adjacente
    int peso; // Peso da aresta
};

// Fun��o para criar uma aresta na lista de adjac�ncias
void cria_aresta(list<No>& adj, int u, int v, int p, int orientado) {
    // Adiciona a aresta do v�rtice u para o v�rtice v com o peso p
    No novo;
    novo.v = v;
    novo.peso = p;
    adj.push_back(novo);
    // Se o grafo n�o � orientado, adiciona a aresta do v�rtice v para o v�rtice u com o mesmo peso
    if (!orientado) {
        novo.v = u;
        adj.push_back(novo);
    }
}

int main() {
    int num_vertices, orientado;
    cin >> num_vertices >> orientado;

    // Lista de adjac�ncias para representar o grafo
    list<No> adj[num_vertices];

    // Leitura das arestas do grafo
    int origem, destino, peso;
    while (cin >> origem >> destino >> peso) {
        if (origem == -1 && destino == -1 && peso == -1) {
            break; // Fim da entrada
        }
        // Cria a aresta
        cria_aresta(adj[origem], origem, destino, peso, orientado);
    }

    // Mostra a lista de adjac�ncias gerada
    for (int i = 0; i < num_vertices; ++i) {
        for (list<No>::iterator it = adj[i].begin(); it != adj[i].end(); ++it) {
            cout << i << " " << it->v << " " << it->peso << endl;
        }
    }

    return 0;
}
