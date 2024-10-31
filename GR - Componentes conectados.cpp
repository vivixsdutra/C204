#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Estrutura para representar uma aresta
struct Aresta {
    int destino;
};

// Lista de adjac�ncia para representar o grafo
vector<vector<Aresta> > adj_list;

// Fun��o para verificar se o grafo � conexo usando busca em largura
bool bfs(int start) {
    // Vetor para marcar os v�rtices visitados
    vector<bool> visitado(adj_list.size(), false);

    // Fila para a busca em largura
    queue<int> fila;

    // Inicia a busca a partir do v�rtice inicial
    fila.push(start);
    visitado[start] = true;

    // Processa todos os v�rtices alcan��veis a partir do v�rtice inicial
    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        // Percorre todos os v�rtices adjacentes ao v�rtice atual
        for (int i = 0; i < adj_list[u].size(); ++i) {
            int v = adj_list[u][i].destino;
            // Se o v�rtice adjacente ainda n�o foi visitado, marca como visitado e adiciona � fila
            if (!visitado[v]) {
                visitado[v] = true;
                fila.push(v);
            }
        }
    }

    // Verifica se todos os v�rtices foram visitados
    for (int i = 0; i < visitado.size(); ++i) {
        if (!visitado[i]) {
            return false; // Se algum v�rtice n�o foi visitado, o grafo n�o � conexo
        }
    }
    return true; // Se todos os v�rtices foram visitados, o grafo � conexo
}

int main() {
    int num_vertices, start;
    cin >> num_vertices >> start;

    // Inicializa��o da lista de adjac�ncia
    adj_list.resize(num_vertices);

    // Leitura das arestas do grafo
    int origem, destino;
    while (cin >> origem >> destino) {
        if (origem == -1 && destino == -1) {
            break; // Fim da entrada
        }
        adj_list[origem].push_back({destino});
        adj_list[destino].push_back({origem}); // Grafo n�o direcionado
    }

    // Verifica se o grafo � conexo a partir do v�rtice inicial
    if (bfs(start)) {
        cout << "Conexo" << endl;
    } else {
        cout << "Nao conexo" << endl;
    }

    return 0;
}
