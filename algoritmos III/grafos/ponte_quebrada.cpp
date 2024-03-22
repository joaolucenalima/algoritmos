#include <iostream>
#include <list>

using namespace std;

bool *bfs(bool matriz[][100], int vertices, int origem)
{
  list<int> fila;
  bool *visitados = new bool[vertices];
  for (int i = 0; i < vertices; i++)
    visitados[i] = false;

  fila.push_back(origem);
  int atual;
  while (!fila.empty())
  {
    atual = fila.front();
    visitados[atual] = true;
    for (int i = 0; i < vertices; i++)
    {
      if (matriz[atual][i] == true && visitados[i] == false)
        fila.push_back(i);
    }
    fila.pop_front();
  }

  return visitados;
}

int main()
{
  int n, m;
  cin >> n >> m;

  n++;

  bool matriz[n][100];

  int saida1, saida2;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      matriz[i][j] == false;

  for (int i = 0; i < m; i++)
  {
    cin >> saida1 >> saida2;
    matriz[saida1][saida2] = true;
    matriz[saida2][saida1] = true;
  }

  int x, y;
  cin >> x >> y;

  bool *visitados = bfs(matriz, n, x);

  matriz[x][y] = false;
  matriz[y][x] = false;

  bool *visitados2 = bfs(matriz, n, x);

  for (int i = 0; i < n; i++)
    if (visitados[i] && !visitados2[i])
      cout << i << endl;

  return 0;
}