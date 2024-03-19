#include <iostream>

using namespace std;

int inversoes = 0;

void merge_arrays(int vetor[], int inicio, int meio, int fim)
{
  int i = inicio;
  int j = meio + 1;
  int k = inicio;

  int temp[fim - inicio + 1];

  for (i; i <= fim; i++)
    temp[i] = vetor[i];

  i = inicio;

  while (i <= meio && j <= fim)
  {
    if (temp[i] <= temp[j])
    {
      vetor[k] = temp[i];
      i++;
    }
    else
    {
      vetor[k] = temp[j];
      j++;
      inversoes += meio - i + 1;
    }
    k++;
  }

  // se sobraram elementos faz o append deles
  while (i <= meio)
  {
    vetor[k] = temp[i];
    k++;
    i++;
  }

  while (j <= fim)
  {
    vetor[k] = temp[j];
    k++;
    j++;
  }
}

void merge_sort(int vetor[], int inicio, int fim)
{
  if (inicio >= fim)
    return;

  int meio = inicio + (fim - inicio) / 2;
  merge_sort(vetor, inicio, meio);
  merge_sort(vetor, meio + 1, fim);
  merge_arrays(vetor, inicio, meio, fim);
}

int main()
{
  int n;
  cin >> n;

  int vetor[n];

  for (int i = 0; i < n; i++)
    cin >> vetor[i];

  merge_sort(vetor, 0, n - 1);

  cout << inversoes << endl;

  return 0;
}