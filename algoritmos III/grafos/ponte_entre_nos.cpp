#include <iostream>
#include <list>

using namespace std;

void bfs(bool matriz_adj[][100], int inicial, int vertices, bool cidades_acessiveis[])
{
  list<int> fila;

  fila.push_back(inicial);
  cidades_acessiveis[inicial] = true;

  while (!fila.empty())
  {
    int cidade_a_verificar = fila.front();
    fila.pop_front();

    for (int j = 0; j < vertices; j++)
      if (matriz_adj[cidade_a_verificar][j] == true && !cidades_acessiveis[j])
      {
        cidades_acessiveis[j] = true;
        fila.push_back(j);
      }
  }
}

int main()
{
  int vertices, arestas;
  cin >> vertices >> arestas;

  vertices++;

  bool matriz_adj[vertices][100] = {false};

  int origem, destino;

  for (int i = 0; i < arestas; i++)
  {
    cin >> origem >> destino;
    matriz_adj[origem][destino] = true;
    matriz_adj[destino][origem] = true;
  }

  int x, y;
  cin >> x >> y;

  bool cidades_acessiveis[vertices];
  bfs(matriz_adj, x, vertices, cidades_acessiveis);

  matriz_adj[x][y] = false;
  matriz_adj[y][x] = false;

  bool cidades_access_sem_ponte[vertices];
  bfs(matriz_adj, x, vertices, cidades_access_sem_ponte);

  for (int i = 1; i < vertices; i++)
  {
    if (cidades_acessiveis[i] && !cidades_access_sem_ponte[i])
    {
      cout << i << " ";
    }
  }

  return 0;
}