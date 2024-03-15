#include <iostream>

using namespace std;

int calcular_potencia(int base, int expoente)
{
  if (expoente == 0)
    return 1;
  else
    return base * calcular_potencia(base, expoente - 1);
}

int main()
{
  int base, expoente;

  cin >> base >> expoente;

  int resultado = calcular_potencia(base, expoente);

  cout << resultado;

  return 0;
}