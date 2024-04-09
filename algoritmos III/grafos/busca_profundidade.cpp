#include <iostream>

using namespace std;

// Depth-First Search (DFS)
void dfs(int grafos[][], int atual, int tamanho, bool visitados[])
{
  visitados[atual] = true;

  for (int i = 0; i < tamanho; i++)
  {
    if (grafos[atual][i] != -1 && visitados[i] == false)
      dfs(grafos, i, tamanho, visitados);
  }
}

int main()
{
  int numVertices, direcionada;
  cin >> numVertices >> direcionada;

  int grafo[numVertices][numVertices];

  for (int i = 0; i < numVertices; i++)
  {
    for (int j = 0; j < numVertices; j++)
    {
      grafo[i][j] = -1;
    }
  }

  int origem, destino, peso;
  cin >> origem >> destino >> peso;

  while (origem != -1 && destino != -1 && peso != -1)
  {
    grafo[origem][destino] = peso;
    if (!direcionada)
      grafo[destino][origem] = peso;
  }

  bool visitados[numVertices];

  dfs(grafo, 0, numVertices, visitados);

  return 0;
}