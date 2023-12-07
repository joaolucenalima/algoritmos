#include <iostream>

using namespace std;

int main()
{
  int a;
  int *p;

  p = &a;
  a = 10;

  // endereço de a
  cout << p << endl;

  // 10
  cout << (*p) << endl;
  // endereço de p
  cout << (&p) << endl;

  // alterando conteúdo de p (a)
  *p = 20;

  // 20
  cout << a << endl;

  return 0;
}