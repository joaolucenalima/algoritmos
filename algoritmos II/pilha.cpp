#include <iostream>

using namespace std;

struct node
{
  int info;
  struct node *prox;
};

typedef node *nodePtr;

void push(int info, nodePtr &lista)
{
  node *p = new node;
  p->info = info;
  if (lista == NULL)
  {
    p->prox = NULL;
  }
  else
  {
    p->prox = lista;
  }
  lista = p;
}

int pop(int &x, nodePtr &lista)
{
  if (lista == NULL)
  {
    return -1;
  }
  else
  {
    node *p;
    p = lista;

    lista = p->prox;
    x = p->info;
    delete p;

    return 0;
  }
}

void insertAfterElement(int x, int y, nodePtr &lista)
{
  node *p = new node;
  p->info = y;

  node *q = lista;

  while (q != NULL)
  {
    if (q->info == x)
    {
      p->prox = q->prox;
      q->prox = p;
      return;
    }
    q = q->prox;
  }
}

int main()
{
  nodePtr lista = NULL;
  int num;

  cin >> num;

  while (num != -1)
  {
    push(num, lista);
    cin >> num;
  }

  // x = elemento da lista
  // y = elemento a ser inserido após o x
  int x, y;

  cin >> x >> y;

  insertAfterElement(x, y, lista);

  while (lista != NULL)
  {
    pop(num, lista);
    cout << num << " ";
  }

  return 0;
}