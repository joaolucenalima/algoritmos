#include <iostream>

using namespace std;

struct Produto
{
  string nome;
  int quantidade;
};

int main()
{
  int n;
  cin >> n;

  Produto produtos[n];

  for (int i = 0; i < n; i++)
  {
    cin >> produtos[i].nome;
    cin >> produtos[i].quantidade;
  }

  string produto_buscado;

  cin >> produto_buscado;

  for (int i = 0; i < n; i++)
  {
    if (produtos[i].nome == produto_buscado)
    {
      cout << produtos[i].nome << " em estoque!" << endl;
      return 0;
    }
  }

  cout << "Nao existe " << produto_buscado << " em estoque!" << endl;

  return 0;
}