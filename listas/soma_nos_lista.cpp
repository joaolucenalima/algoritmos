#include <iostream>
#include <list>

using namespace std;

int soma(list<int> lista)
{
  int result = 0;
  list<int>::iterator it;

  for (it = lista.begin(); it != lista.end(); it++)
  {
    result += *it;
  }

  return result;
}

int main()
{
  list<int> lista;
  int num;

  cin >> num;

  while (num != 0)
  {
    lista.push_back(num);
    cin >> num;
  }

  int result = soma(lista);

  cout << result;

  return 0;
}