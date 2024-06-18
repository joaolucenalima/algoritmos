#include <iostream>
#include <math.h>

using namespace std;

typedef int KeyType;
typedef double ValueType;

struct Data
{
  KeyType key;
  ValueType value;
};

typedef struct Data DataType;

typedef struct Node
{
  DataType data;
  Node *right;
  Node *left;
} Node;

void insert(Node *&curr, DataType data)
{
  if (curr == NULL)
  {
    curr = new Node;
    curr->data = data;
    curr->right = NULL;
    curr->left = NULL;
    return;
  }

  if (data.value >= curr->data.value)
    insert(curr->right, data);
  else if (data.value < curr->data.value)
    insert(curr->left, data);
}

void show_ordered(Node *curr)
{
  if (curr->left != NULL)
    show_ordered(curr->left);

  cout << curr->data.key << ":" << curr->data.value << endl;

  if (curr->right != NULL)
    show_ordered(curr->right);
}

// Funções para Algoritmos Geométricos ----------------------------------------

typedef struct
{
  int x;
  int y;
} Ponto;

double area_triangulo(
    Ponto a,
    Ponto b,
    Ponto c)
{
  return ((a.x * b.y) - (a.y * b.x) +
          (a.y * c.x) - (a.x * c.y) +
          (b.x * c.y) - (b.y * c.x)) /
         2.0;
}

double distancia(Ponto p1, Ponto p2)
{
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
              (p1.y - p2.y) * (p1.y - p2.y));
}

int orientacao(Ponto a, Ponto b, Ponto c)
{
  double area = area_triangulo(a, b, c);
  if (area > 0)
    return 1;

  if (area < 0)
    return -1;

  return 0;
}
// ----------------------------------------------------------------------------

int main()
{
  int peixes;
  cin >> peixes;

  Node *root = NULL;

  Ponto ponto1, ponto2, ponto3;

  for (int i = 0; i < peixes; i++)
  {
    cin >> ponto1.x >> ponto1.y;
    cin >> ponto2.x >> ponto2.y;
    cin >> ponto3.x >> ponto3.y;

    double comprimento1_2 = distancia(ponto1, ponto2);
    double comprimento1_3 = distancia(ponto1, ponto3);

    DataType aux;

    aux.key = i;

    if (comprimento1_2 > comprimento1_3)
      aux.value = comprimento1_2;
    else
      aux.value = comprimento1_3;

    insert(root, aux);
  }

  show_ordered(root);

  return 0;
}