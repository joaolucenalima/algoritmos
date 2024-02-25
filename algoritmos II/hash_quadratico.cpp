#include <iostream>

using namespace std;

int h(int k, int m)
{
  return k % m;
}

int hash_quadratico(int k, int i, int m)
{
  int c1 = 2;
  int c2 = 3;
  return (h(k, m) + (c1 * i) + (c2 * (i * i))) % m;
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

  cin >> k;
  while (k != 0)
  {
    colisoes = 0;
    do
    {
      pos = hash_quadratico(k, colisoes, m);
      if (tabela_hash[pos] == -1)
      {
        tabela_hash[pos] = k;
        break;
      }
      colisoes++;
    } while (colisoes < m);

    cin >> k;
  }

  for (int i = 0; i < m; i++)
  {
    cout << tabela_hash[i] << ",";
  }

  return 0;
}