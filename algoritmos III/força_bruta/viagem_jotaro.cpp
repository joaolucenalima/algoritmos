#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
  int n;
  cin >> n;

  int distancias[n][n];

  // preenchendo matriz de distancias entre cidades
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        distancias[i][j] = 0;
        continue;
      }

      if (i > j)
        distancias[i][j] = distancias[j][i];
      else
        cin >> distancias[i][j];
    }
  }

  unordered_map<int, bool> visitados;

  int menor_custo = 0;
  int cidade = 0;

  for (int cont = 0; cont < n - 1; cont++)
  {
    int menor = __INT_MAX__;

    visitados[cidade] = true;

    for (int j = 0; j < n; j++)
    {
      if (distancias[cidade][j] < menor && !visitados[j])
      {
        menor = distancias[cidade][j];
        cidade = j;
      }
    }

    cout << cidade << endl;
    menor_custo += menor;
  }

  cout << "Menor custo: " << menor_custo << endl;

  return 0;
}