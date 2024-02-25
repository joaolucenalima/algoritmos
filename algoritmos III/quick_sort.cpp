#include <iostream>

using namespace std;

struct Inseto
{
  string nome;
  float tamanho;
};

void swap(Inseto &a, Inseto &b)
{
  Inseto temp = a;
  a = b;
  b = temp;
}

int particiona(Inseto insetos[], int inicio, int fim)
{
  int pivo = insetos[fim].tamanho;
  int i = inicio - 1;

  for (int j = inicio; j < fim; j++)
  {
    if (insetos[j].tamanho <= pivo)
    {
      i++;
      swap(insetos[i], insetos[j]);
    }
  }

  swap(insetos[i + 1], insetos[fim]);
  return i + 1;
}

void quick_sort(Inseto insetos[], int inicio, int fim)
{
  if (inicio < fim)
  {
    int pivo = particiona(insetos, inicio, fim);
    quick_sort(insetos, inicio, pivo - 1);
    quick_sort(insetos, pivo + 1, fim);
  }
}

int main()
{
  int n;
  cin >> n;

  Inseto insetos[n];

  for (int i = 0; i < n; i++)
  {
    getline(cin >> ws, insetos[i].nome);
    cin >> insetos[i].tamanho;
  }

  quick_sort(insetos, 0, n - 1);

  for (int i = 0; i < n; i++)
    cout << insetos[i].nome << endl;

  return 0;
}