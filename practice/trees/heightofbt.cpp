#include <iostream>
using namespace std;

struct treenode
{

  int val;
  treenode *left;
  treenode *right;
  treenode(int x)
  {
    val = x;
    left = NULL;
    right = NULL;
  }
};
class solution
{

public:
  int height(treenode *root)
  {
    if (!root)
      return 0;
    return 1 + max(height(root->left), height(root->right));
  }
};

int main()
{

  treenode *root = new treenode(1);
  root->left = new treenode(2);
  root->right = new treenode(3);
  root->left->left = new treenode(4);

  solution sol;
  cout << " height of the tree is " << sol.height(root) << endl;

  return 0;
}