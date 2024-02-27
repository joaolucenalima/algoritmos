#include <iostream>

using namespace std;

struct Pedra
{
  string nome;
  float volume;
  int peso;
  int preco;
};

int max_peso = 400;
float max_volume = 1.0;

Pedra pedras[] = {
    {"Esmeralda", 0.521, 127, 410},
    {"Topazio", 0.857, 254, 320},
    {"Diamante", 0.455, 263, 500},
    {"Rubi", 0.065, 134, 315},
    {"Jade", 0.012, 111, 280}};

int estrategia_gulosa() // ESTRATÉGIA GULOSA - O(n) (se não precisar ordenar, senão O(nlogn)
{
  int preco_total = 0;
  int peso_total = 0;
  float volume_total = 0;

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

int solve(int i, int peso, float volume, int preco, int &maior_preco) // FORÇA BRUTA - O(2^n)
{
  if (i == 5)
  {
    if (preco > maior_preco)
    {
      maior_preco = preco;
    }
    return 0;
  }

  // para otimização
  // if (solucao[i][peso][volume] != -1) return solucao[i][peso][volume];

  int solve1 = solve(i + 1, peso, volume, preco, maior_preco);
  int solve2;

  if (peso + pedras[i].peso <= max_peso && volume + pedras[i].volume <= max_volume)
    solve2 = solve(i + 1, peso + pedras[i].peso, volume + pedras[i].volume, preco + pedras[i].preco, maior_preco);

  // solucao[i][peso][volume] = max(solve1, solve2);
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