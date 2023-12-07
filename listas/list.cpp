#include <iostream>
#include <list>

using namespace std;

int main()
{
  int vetor[2];
  list<int> lista;

  vetor[0] = 33;
  lista.push_back(33);

  vetor[1] = 44;
  lista.push_back(44);

  cout << lista.size() << endl;

  list<int>::iterator it;

  for (it = lista.begin(); it != lista.end(); it++)
  {
    cout << *it << endl;
  }

  return 0;
}