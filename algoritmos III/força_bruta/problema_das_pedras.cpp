#include <iostream>

using namespace std;

struct Pedra
{
  string nome;
  int volume;
  int peso;
  int preco;
};

int max_peso = 400;
float max_volume = 1000;

Pedra pedras[] = {
    {"Esmeralda", 521, 127, 410},
    {"Topazio", 857, 254, 320},
    {"Diamante", 455, 263, 500},
    {"Rubi", 65, 134, 315},
    {"Jade", 12, 111, 280}};

int estrategia_gulosa() // ESTRATÉGIA GULOSA - O(n) (se precisar ordenar então será O(n log n))
{
  int preco_total = 0;
  int peso_total = 0;
  int volume_total = 0;

  for (int i = 0; i < 5; i++)
  {
    if (peso_total + pedras[i].peso <= max_peso && volume_total + pedras[i].volume <= max_volume)
    {
      preco_total += pedras[i].preco;
      peso_total += pedras[i].peso;
      volume_total += pedras[i].volume;
    }
  }

  return preco_total;
}

int solve(int i, int peso, int volume, int preco, int &maior_preco) // FORÇA BRUTA - O(2^n)
{
  if (i == 5)
  {
    if (preco > maior_preco)
    {
      maior_preco = preco;
    }
    return 0;
  }

  int solve1 = solve(i + 1, peso, volume, preco, maior_preco);
  int solve2;

  if (peso + pedras[i].peso <= max_peso && volume + pedras[i].volume <= max_volume)
    solve2 = solve(i + 1, peso + pedras[i].peso, volume + pedras[i].volume, preco + pedras[i].preco, maior_preco);

  return max(solve1, solve2);
}

int main()
{
  int maior_preco = 0;

  solve(0, 0, 0, 0, maior_preco);

  cout << "Maior preço possível com força bruta: " << maior_preco << endl;

  cout << "Maior preço possível com estratégia gulosa: " << estrategia_gulosa() << endl;

  return 0;
}