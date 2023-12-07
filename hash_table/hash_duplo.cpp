#include <iostream>

using namespace std;

int h1(int k, int m)
{
  return k % m;
}

int h2(int k, int m)
{
  return 1 + (k % (m - 1));
}

int hash_duplo(int k, int i, int m)
{
  return (h1(k, m) + i * h2(k, m)) % m;
}

int main()
{

  int m = 13;
  int k, pos;
  int colisoes;
  int tabela_hash[m];

  for (int i = 0; i < m; i++)
  {
    tabela_hash[i] = -1;
  }

  for (int i = 0; i < m; i++)
  {
    cin >> k;
    colisoes = 0;
    do
    {
      pos = hash_duplo(k, colisoes, m);
      if (tabela_hash[pos] == -1)
      {
        tabela_hash[pos] = k;
        break;
      }
      colisoes++;
    } while (colisoes < m);
  }

  return 0;
}