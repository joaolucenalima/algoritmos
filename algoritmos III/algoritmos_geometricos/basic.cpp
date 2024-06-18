#include <iostream>

using namespace std;

struct ponto
{
  int x, y;
};

float calcular_area(ponto a, ponto b, ponto c)
{
  float area_palaralelogramo = (a.x * b.y + a.y * c.x + b.x * c.y) - (c.x * b.y + c.y * a.x + b.x * a.y);
  return area_palaralelogramo / 2.0;
}

void coordenadas_baricentricas(ponto a, ponto b, ponto c, ponto p)
{
  float area_total = calcular_area(a, b, c);

  float lambda_1 = calcular_area(p, b, c) / area_total;
  float lambda_2 = calcular_area(a, p, c) / area_total;
  float lambda_3 = calcular_area(a, b, p) / area_total;

  cout << "lambda_1: " << lambda_1 << endl;
  cout << "lambda_2: " << lambda_2 << endl;
  cout << "lambda_3: " << lambda_3 << endl;
}

int lado_ponto(ponto a, ponto b, ponto p)
{
  float area_triangulo = calcular_area(a, b, p);

  if (area_triangulo > 0)
    return 1;

  if (area_triangulo < 0)
    return -1;

  return 0;
}

int main()
{
  ponto a = {1, 2};
  ponto b = {4, 4};
  ponto c = {4, 1};

  cout << calcular_area(a, b, c) << endl;

  ponto p = {3, 2};

  coordenadas_baricentricas(a, b, c, p);

  /*
  lados = {
    1: 'esquerda',
    0: 'sobre',
    -1: 'direita'
  }
  */

  cout << lado_ponto(a, b, c) << endl;

  return 0;
}

// | Xa  Ya  1 |
// | Xb  Yb  1 |
// | Xc  Yc  1 |