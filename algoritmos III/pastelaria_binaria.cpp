#include <iostream>

using namespace std;

struct Produto
{
  string nome;
  int codigo;
  int quantidade;
};

int busca_binaria(Produto produtos[], int codigo_buscado, int n)
{
  int inicio = 0;
  int fim = n - 1;
  int meio;

  while (inicio <= fim)
  {
    meio = (inicio + fim) / 2;
    if (produtos[meio].codigo < codigo_buscado)
      inicio = meio + 1;
    else if (produtos[meio].codigo > codigo_buscado)
      fim = meio - 1;
    else
      return meio;
  }

  return -1;
}

int main()
{
  int n;
  cin >> n;

  Produto produtos[n];

  for (int i = 0; i < n; i++)
  {
    cin >> produtos[i].codigo;
    cin >> produtos[i].nome;
    cin >> produtos[i].quantidade;
  }

  int codigo_buscado;

  cin >> codigo_buscado;

  int posicao = busca_binaria(produtos, codigo_buscado, n);

  if (posicao != -1)
    cout << produtos[posicao].nome << " em estoque!" << endl;
  else
    cout << "Nao existem produtos com esse codigo em estoque!" << endl;

  return 0;
}