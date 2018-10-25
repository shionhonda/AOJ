#include<iostream>
#include<string>
using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z;
  z = (Node*)malloc(sizeof(Node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while (x!=NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y==NIL) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void preorder(Node *v) {
  if (v==NIL) {
    return;
  }
  cout << " " << v->key;
  preorder(v->left);
  preorder(v->right);
}

void inorder(Node *v) {
  if (v==NIL) {
    return;
  }
  inorder(v->left);
  cout << " " << v->key;
  inorder(v->right);
}

int main() {
  int n;
  cin >> n;
  int x;
  string com;
  for (int i=0; i<n; i++) {
    cin >> com;
    if (com=="insert") {
      cin >> x;
      insert(x);
    } else if (com=="print") {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;

    }
  }
  return 0;
}
