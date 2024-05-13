#include <iostream>

using namespace std;

struct treenode
{
  int info;
  struct treenode *left;
  struct treenode *right;
};

void binaryTreeInsert(treenode *root, int value)
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
    binaryTreeInsert(root->left, value);
  }
  else
  {
    binaryTreeInsert(root->right, value);
  }
}

treenode *binaryTreeSearch(treenode *root, int value)
{
  if (root == NULL)
    return NULL;

  if (root->info == value)
    return root;

  if (value < root->info)
    return binaryTreeSearch(root->left, value);

  return binaryTreeSearch(root->right, value);
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
    binaryTreeInsert(root, value);
  }

  int searchedElement;
  cin >> searchedElement;

  treenode *searchedNode = binaryTreeSearch(root, searchedElement);

  if (searchedNode != NULL)
    cout << "Encontrado!" << endl;
  else
    cout << "Nao encontrado" << endl;

  return 0;
}