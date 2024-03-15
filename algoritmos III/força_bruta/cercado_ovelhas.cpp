#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int metros_totais;
  cin >> metros_totais;

  int maior_area = 0;
  int maior_altura = 0;

  for (int i = 1; i < (metros_totais / 2); i++)
  {
    int altura = metros_totais - i * 2;

    if (altura * i > maior_area)
    {
      maior_area = altura * i;
      maior_altura = altura;
    }

    // cout << altura << " x " << i << " = " << altura * i << endl;
  }

  cout << maior_altura << " x " << (metros_totais - maior_altura) / 2 << endl;

  return 0;
}