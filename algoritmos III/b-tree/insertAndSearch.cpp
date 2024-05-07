#include <iostream>

using namespace std;

struct treenode
{
  int info;
  struct treenode *left;
  struct treenode *right;
};

void bTreeInsert(treenode *root, int value)
{
  if (root == NULL)
  {
    root = new treenode;
    root->info = value;
    root->left = NULL;
    root->right = NULL;
  }
  else if (value < root->info)
  {
    bTreeInsert(root->left, value);
  }
  else
  {
    bTreeInsert(root->right, value);
  }
}

treenode *bTreeSearch(treenode *root, int value)
{
  if (root == NULL)
    return NULL;

  if (root->info == value)
    return root;

  if (value < root->info)
    return bTreeSearch(root->left, value);

  return bTreeSearch(root->right, value);
}

int main()
{
  int n;
  cin >> n;

  treenode *root = new treenode;

  for (int i = 0; i < n; i++)
  {
    int value;
    cin >> value;
    bTreeInsert(root, value);
  }

  int searchedElement;
  cin >> searchedElement;

  treenode *searchedNode = bTreeSearch(root, searchedElement);

  if (searchedNode != NULL)
    cout << "Encontrado!" << endl;
  else
    cout << "Nao encontrado" << endl;

  return 0;
}