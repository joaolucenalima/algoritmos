#include <iostream>

using namespace std;

struct no
{
  int info;
  struct no *prox;
};

typedef no *noPtr;

void push(int info, noPtr &lista)
{
  no *p = new no;
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

int pop(int &x, noPtr &lista)
{
  if (lista == NULL)
  {
    return -1;
  }
  else
  {
    no *p;
    p = lista;

    lista = p->prox;
    x = p->info;
    delete p;

    return 0;
  }
}

void insertAfterElement(int x, int y, noPtr &lista)
{
  no *p = new no;
  p->info = y;

  no *q = lista;

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
  noPtr lista = NULL;
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