//
resolu��o achar o caminho menor usando dijkstra 

ShortestPath_Dijkstra(G,start)
    para cada u em V[G]
        intree[u] = false
        distance[u] = INT_MAX
        parent[u] = -1
    distance[start] = 0
    v = start
    enquanto(intree[v]==false)
        intree[v] = true
        para cada p em adj[v]
            destino = p->v
            weight = p->peso
            se distance[destino]>distance[v]+weight
                distance[destino] = distance[v]+weight
                parent[destino] = v
        v = 0
        dist = INT_MAX
        para cada u em V[G]
            se(intree[u]==false && dist>distance[u])
                dist = distance[u]
                v=u

para grafos direcionados e ponderados 
vai ter 3 vetores 
distancia 
parent 
visitado 
				
				
				
				
				
				
				
				
O objetivo � calcular o menor caminho a partir do v�rtice 1 para todos os outros v�rtices, seguindo o algoritmo de Dijkstra. O gr�fico fornecido tem 6 v�rtices e v�rias arestas com pesos, conforme indicado pelas setas no diagrama.

2. Inicializa��o
No algoritmo de Dijkstra:

Iniciamos o vetor distance com 8 (ou INT_MAX) para todos os v�rtices, exceto o v�rtice de origem (neste caso, o v�rtice 1), que ser� inicializado com 0.
Criamos tamb�m um vetor intree que indica se o v�rtice j� foi visitado ou n�o (todos come�am como false).
Come�amos o c�lculo a partir do v�rtice 1.
3. Adjac�ncias e pesos
O grafo fornecido tem as seguintes arestas com pesos:

1 ? 2 com peso 1
1 ? 4 com peso 4
2 ? 3 com peso 5
2 ? 5 com peso 1
3 ? 6 com peso 3
4 ? 5 com peso 3
5 ? 3 com peso 1
5 ? 6 com peso 4
4. Execu��o do algoritmo de Dijkstra
Vamos come�ar a partir do v�rtice 1 e atualizar as dist�ncias para seus vizinhos.

Itera��o 1 (v�rtice 1):
Dist�ncias iniciais: [0, 8, 8, 8, 8, 8]
Atualizamos as dist�ncias para os v�rtices adjacentes ao 1:
1 ? 2: distance[2] = 0 + 1 = 1
1 ? 4: distance[4] = 0 + 4 = 4
Dist�ncias agora: [0, 1, 8, 4, 8, 8]
Itera��o 2 (v�rtice 2):
Menor dist�ncia dispon�vel � do v�rtice 2 com distance[2] = 1.
Atualizamos as dist�ncias para os vizinhos de 2:
2 ? 3: distance[3] = 1 + 5 = 6
2 ? 5: distance[5] = 1 + 1 = 2
Dist�ncias agora: [0, 1, 6, 4, 2, 8]
Itera��o 3 (v�rtice 5):
Menor dist�ncia agora � do v�rtice 5 com distance[5] = 2.
Atualizamos as dist�ncias para os vizinhos de 5:
5 ? 3: distance[3] = min(6, 2 + 1) = 3
5 ? 6: distance[6] = 2 + 4 = 6
Dist�ncias agora: [0, 1, 3, 4, 2, 6]
Itera��o 4 (v�rtice 4):
Menor dist�ncia agora � do v�rtice 4 com distance[4] = 4.
Atualizamos as dist�ncias para os vizinhos de 4:
4 ? 5: distance[5] = min(2, 4 + 3) = 2 (n�o muda)
Dist�ncias agora: [0, 1, 3, 4, 2, 6]
Itera��o 5 (v�rtice 3):
Menor dist�ncia agora � do v�rtice 3 com distance[3] = 3.
Atualizamos as dist�ncias para os vizinhos de 3:
3 ? 6: distance[6] = min(6, 3 + 3) = 6 (n�o muda)
Dist�ncias agora: [0, 1, 3, 4, 2, 6]
Itera��o 6 (v�rtice 6):
O v�rtice 6 j� est� com sua menor dist�ncia final: distance[6] = 6






//