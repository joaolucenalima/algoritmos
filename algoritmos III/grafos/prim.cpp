#include <iostream>
#include <list>

using namespace std;

#define INT_MAX 1000000

struct no
{
  int destino;
  int peso;
};

void prim(list<no> adj[], int nVertices, int start)
{
  int intree[nVertices];
  int distance[nVertices];
  int parent[nVertices];

  for (int i = 0; i < nVertices; i++)
  {
    intree[i] = 0;
    distance[i] = INT_MAX;
    parent[i] = -1;
  }
  distance[start] = 0;

  int vertice_atual = start;
  while (intree[vertice_atual] == 0)
  {
    intree[vertice_atual] = 1;

    list<no>::iterator i;

    for (i = adj[vertice_atual].begin(); i != adj[vertice_atual].end(); i++)
    {
      if (distance[i->destino] > i->peso && intree[i->destino] == 0)
      {
        distance[i->destino] = i->peso;
        parent[i->destino] = vertice_atual;
      }
    }
    vertice_atual = 0;
    int dist_min = INT_MAX;
    for (int i = 0; i < nVertices; i++)
    {
      if (intree[i] == 0 && dist_min > distance[i])
      {
        dist_min = distance[i];
        vertice_atual = i;
      }
    }
  }

  cout << "Arvore geradora minima: " << endl;
  int custo = 0;
  for (int i = 0; i < nVertices; i++)
  {
    if (distance[i] != INT_MAX)
      custo += distance[i];

    if (parent[i] == -1)
      continue;

    cout << parent[i] << " " << i << endl;
  }

  cout << "Custo: " << custo << endl;
}

int main()
{
  int nVertices, direcionado, verticeInicial;
  cin >> nVertices >> direcionado >> verticeInicial;

  list<no> adj[nVertices];

  int origem, destino, peso;
  cin >> origem >> destino >> peso;

  while (origem != -1 && destino != -1 && peso != -1)
  {
    no no_aux;
    no_aux.destino = destino;
    no_aux.peso = peso;
    adj[origem].push_back(no_aux);

    if (direcionado == 1)
    {
      no_aux.destino = origem;
      no_aux.peso = peso;
      adj[destino].push_back(no_aux);
    }

    cin >> origem >> destino >> peso;
  }

  prim(adj, nVertices, verticeInicial);

  return 0;
}