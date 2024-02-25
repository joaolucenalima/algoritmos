#include <iostream>
#include <list>

using namespace std;

int h1(int k, int m)
{
  return k % m;
}

int h2(int k, int m)
{
  return 1 + (k % (m - 1));
}

int hash_duplo(int k, int colisoes, int m)
{
  return (h1(k, m) + colisoes * h2(k, m)) % m;
}

int main()
{
  int m, numeros_a_inserir;
  cin >> m;

  list<int> pilha;

  int tabela_hash[m];

  cin >> numeros_a_inserir;

  // inicializando valores com -1
  for (int i = 0; i < m; i++)
    tabela_hash[i] = -1;

  // inserindo elementos na pilha
  for (int i = 0; i < numeros_a_inserir; i++)
  {
    int novo_num;
    cin >> novo_num;
    pilha.push_front(novo_num);
  }

  int colisoes;
  // retirando elementos da pilha e colocando na tabela hash
  for (int i = 0; i < numeros_a_inserir; i++)
  {
    int elemento_pilha = pilha.front();
    pilha.pop_front();

    colisoes = 0;
    do
    {
      int pos = hash_duplo(elemento_pilha, colisoes, m);

      if (tabela_hash[pos] == -1)
      {
        tabela_hash[pos] = elemento_pilha;
        break;
      }

      colisoes++;
    } while (colisoes < m);
  }

  for (int i = 0; i < m; i++)
    cout << tabela_hash[i] << " ";

  return 0;
}