#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float raiz_quadrada(float x, float x0, float i)
{
  if (abs(x0 * x0 - x) <= i)
    return x0;

  return raiz_quadrada(x, ((x0 * x0 + x) / (2 * x0)), i);
}

int main()
{
  float x, x0, i;
  cin >> x >> x0 >> i;

  float resultado = raiz_quadrada(x, x0, i);

  cout << fixed << setprecision(4);
  cout << resultado;

  return 0;
}