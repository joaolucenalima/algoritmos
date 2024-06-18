#include <iostream>

using namespace std;

struct Peixe
{
  int indice;
  float viscosidade;
  float espessura_cauda;
  float diametro_olho;
  int toxidade;
};

struct TreeNode
{
  Peixe info;
  TreeNode *left;
  TreeNode *right;
};

void insert(TreeNode *&root, Peixe peixe)
{
  if (root == NULL)
  {
    root = new TreeNode;
    root->info = peixe;
    root->left = NULL;
    root->right = NULL;
    return;
  }

  if (peixe.toxidade < root->info.toxidade)
    insert(root->left, peixe);

  if (peixe.toxidade > root->info.toxidade)
    insert(root->right, peixe);
}

void inOrder(TreeNode *root, int tMin, int tMax)
{
  if (root != NULL)
  {

    if (root->left != NULL && root->left->info.toxidade > tMin)
      inOrder(root->left, tMin, tMax);

    cout << root->info.indice << ":" << root->info.toxidade << endl;

    if (root->right != NULL && root->right->info.toxidade < tMax)
      inOrder(root->right, tMin, tMax);
  }
}

int main()
{
  int peixes;
  cin >> peixes;

  int N = 7;

  TreeNode *root = NULL;

  for (int i = 0; i < peixes; i++)
  {
    Peixe aux;

    aux.indice = i;
    cin >> aux.viscosidade;
    cin >> aux.espessura_cauda;
    cin >> aux.diametro_olho;

    aux.toxidade = aux.viscosidade * aux.espessura_cauda * N * aux.espessura_cauda * N * aux.diametro_olho;

    insert(root, aux);
  }

  int tMin, tMax;
  cin >> tMin >> tMax;

  inOrder(root, tMin, tMax);

  return 0;
}