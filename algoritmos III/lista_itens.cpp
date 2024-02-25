#include <iostream>
#include <list>

using namespace std;

struct Itens
{
  string nome;
  int codigo;
  int preco;
};

int hash_linear(int k, int colisoes, int m)
{
  return k % m + colisoes;
}

int buscar_codigo(int codigo, int m, Itens tabela_hash[])
{
  int colisoes = 0;
  do
  {
    int pos = hash_linear(codigo, colisoes, m);

    if (tabela_hash[pos].codigo == codigo)
    {
      return pos;
    }

    colisoes++;
  } while (colisoes < m);

  return -1;
}

int main()
{
  int m = 43;
  int quantidade_itens;

  cin >> quantidade_itens;

  Itens tabela_hash[m];

  for (int i = 0; i < m; i++)
    tabela_hash[i].codigo = -1;

  int colisoes;

  for (int i = 0; i < quantidade_itens; i++)
  {
    int codigo;
    cin >> codigo;

    colisoes = 0;
    do
    {
      int pos = hash_linear(codigo, colisoes, m);

      if (tabela_hash[pos].codigo == -1)
      {
        tabela_hash[pos].codigo = codigo;
        cin >> tabela_hash[pos].nome;
        cin >> tabela_hash[pos].preco;
        break;
      }
      colisoes++;
    } while (colisoes < m);
  }

  list<int> fila_vendas, pilha_compras;

  int vi;
  cin >> vi;

  while (vi != -1)
  {
    fila_vendas.push_back(vi);
    cin >> vi;
  }

  int ci;
  cin >> ci;

  while (ci != -1)
  {
    pilha_compras.push_back(ci);
    cin >> ci;
  }

  int vendas, compras;
  int lucro = 0;

  cin >> vendas >> compras;

  for (int i = 0; i < vendas; i++)
  {
    int codigo = fila_vendas.front();
    fila_vendas.pop_front();

    int pos = buscar_codigo(codigo, m, tabela_hash);
    if (pos != -1)
    {
      cout << tabela_hash[pos].preco << endl;
      lucro += tabela_hash[pos].preco;
    }
  }

  for (int i = 0; i < compras; i++)
  {
    int codigo = pilha_compras.back();
    pilha_compras.pop_back();

    int pos = buscar_codigo(codigo, m, tabela_hash);
    if (pos != -1)
    {
      lucro -= tabela_hash[pos].preco;
    }
  }

  cout << lucro << " moedas." << endl;

  return 0;
}