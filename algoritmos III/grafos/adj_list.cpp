#include <iostream>
#include <list>

using namespace std;

struct no
{
  int v;
  int peso;
};

void cria_aresta(list<no> adj[], int u, int v, int p, int orientado)
{
  no no_aux1;
  no_aux1.v = v;
  no_aux1.peso = p;
  adj[u].push_back(no_aux1);

  if (orientado == 0)
  {
    no no_aux2;
    no_aux2.v = u;
    no_aux2.peso = p;
    adj[v].push_back(no_aux2);
  }
}

int main()
{
  int vertices;
  int orientado;

  cin >> vertices >> orientado;

  list<no> adj[vertices];

  int origem, destino, peso;

  cin >> origem >> destino >> peso;

  while (origem != -1 && destino != -1 && peso != -1)
  {
    cria_aresta(adj, origem, destino, peso, orientado);
    cin >> origem >> destino >> peso;
  }

  list<no>::iterator it;

  for (int i = 0; i < vertices; i++)
  {
    for (it = adj[i].begin(); it != adj[i].end(); it++)
    {
      cout << i << " ";
      cout << it->v << " " << it->peso << endl;
    }
  }

  return 0;
}