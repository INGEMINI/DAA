#include <iostream>
using namespace std;

class bt
{

private:
  struct node
  {

    int data;
    node *left, *right;
    node(int val)
    {
      data = val;
      left = NULL;
      right = NULL;
    }
  };

  node *root;

  node *insertrec(node *n, int val)
  {
    if (!n)
    {
      return new node(val);
    }

    if (val <= n->data)
    {
      n->left = insertrec(n->left, val);
    }

    else
    {
      n->right = insertrec(n->right, val);
    }

    return n;
  }

  void inordertraversal(node *n)
  {
    if (!n)
    {
      return;
    }

    inordertraversal(n->left);
    cout << n->data << " ";
    inordertraversal(n->right);
  }

public:
  bt()
  {
    root = NULL;
  }

  void insert(int val)
  {
    root = insertrec(root, val);
  }

  void inorder()
  {
    inordertraversal(root);
    cout << endl;
  }
};

int main()
{
  bt tree;
  tree.insert(50);
  tree.insert(15);
  tree.insert(52);
  tree.insert(25);
  tree.insert(45);

  cout << "inorder traversal ";
  tree.inorder();

  return 0;
}