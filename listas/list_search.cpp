#include <iostream>
#include <list>

using namespace std;

bool encontrar(list<int> lista, int x)
{
  list<int>::iterator it;

  for (it = lista.begin(); it != lista.end(); it++)
  {
    if (*it == x)
    {
      return true;
    }
  }

  return false;
}

int main()
{
  int num;
  list<int> lista;

  cin >> num;

  while (num != 0)
  {
    lista.push_back(num);
    cin >> num;
  }

  int n;

  cin >> n;

  if (encontrar(lista, n))
  {
    cout << "Encontrado" << endl;
  }
  else
  {
    cout << "Nao encontrado" << endl;
  }

  return 0;
}