#include <iostream>

using namespace std;

struct Ponto
{
  int x, y;
};

float calcular_area(Ponto a, Ponto b, Ponto c)
{
  // produto vetorial
  float area_palaralelogramo = (a.x * b.y + a.y * c.x + b.x * c.y) - (c.x * b.y + c.y * a.x + b.x * a.y);
  return area_palaralelogramo / 2.0;
}

// calcula se o triangulo formado pelos 3 pontos é positivo (curva para esquerda), negativo (curva para direita) ou nulo
// usa p como ponto de referência
int lado_ponto(Ponto a, Ponto b, Ponto p)
{
  float area_triangulo = calcular_area(a, b, p);

  if (area_triangulo > 0)
    return 1; // curva para direita

  if (area_triangulo < 0)
    return -1; // curva para esquerda

  return 0; // colineares
}

int main()
{
  int n_pontos;
  cin >> n_pontos;

  Ponto pontos[n_pontos];

  for (int i = 0; i < n_pontos; i++)
    cin >> pontos[i].x >> pontos[i].y;

  return 0;
}