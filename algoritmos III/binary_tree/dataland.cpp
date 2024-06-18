#include <iostream>

using namespace std;

struct TreeNode
{
  int value;
  TreeNode *left;
  TreeNode *right;
};

void insert(TreeNode *&root, int number)
{
  if (root == NULL)
  {
    root = new TreeNode;
    root->value = number;
    root->left = NULL;
    root->right = NULL;
  }
  else if (number < root->value)
  {
    insert(root->left, number);
  }
  else
  {
    insert(root->right, number);
  }
}

TreeNode *search(TreeNode *root, int number)
{
  if (root == NULL)
    return NULL;

  if (root->value == number)
    return root;

  if (root->value > number)
  {
    return search(root->left, number);
  }

  return search(root->right, number);
}

TreeNode *findMinorRoot(TreeNode *root)
{
  if (root->left == NULL)
    return root;

  return findMinorRoot(root->left);
}

int removeNode(TreeNode *&root, int number)
{
  TreeNode *p;

  if (root == NULL)
    return 1;

  if (root->value == number)
  {
    p = root;

    if (root->left == NULL)
    {
      root = root->right;
    }
    else if (root->right == NULL)
    {
      root = root->left;
    }
    else
    {
      p = findMinorRoot(root->right);
      root->value = p->value;
    }

    delete p;
    return 0;
  }

  if (root->value > number)
  {
    return removeNode(root->left, number);
  }

  return removeNode(root->right, number);
}

int main()
{
  TreeNode *root = NULL;

  int n;

  cin >> n;

  char operation;
  int number;

  for (int i = 0; i < n; i++)
  {
    cin >> operation >> number;

    switch (operation)
    {
    case 'i':
      insert(root, number);
      break;
    case 'r':
      removeNode(root, number);
      break;
    case 'b':
      TreeNode *searchedNode = search(root, number);

      if (searchedNode == NULL)
        cout << "Não" << endl;
      else
        cout << "Sim" << endl;

      break;
    }
  }

  return 0;
}