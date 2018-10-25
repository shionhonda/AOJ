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

Node *find(Node *v, int x) {
  if (v==NIL || v->key==x) {
    return v;
  }
  if (v->key < x) {
    return find(v->right, x);
  } else{
    return find(v->left, x);
  }
}

Node *minLeft(Node *v) {
  while (v->left!=NIL) {
    v = v->left;
  }
  return v;
}

void delNode(Node *z) {
  Node *y; // Node to delete
  Node *x; // y's child

  if (z->left==NIL || z->right==NIL) {
    y = z;
  }  else {
    y = minLeft(z->right);
    z->key = y->key;
  }

  // x <- y's child
  if (y->left!=NIL) {
    x = y->left;
  } else {
    x = y->right;
  }

  // x's parent <- y's parent
  if (x!=NIL) {
    x->parent = y->parent;
  }

  // y's parent's child <- x
  if (y->parent==NIL) {
    root = x;
  } else {
    if (y->parent->left==y) {
      y->parent->left = x;
    } else {
      y->parent->right = x;
    }
  }
  free(y);
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
    } else if (com=="find") {
      cin >> x;
      Node *v = find(root, x);
      if (v==NIL) {
        cout << "no" << endl;
      } else {
        cout << "yes" << endl;
      }
    } else if (com=="delete") {
      cin >> x;
      Node *v = find(root, x);
      delNode(v);
    }
  }
  return 0;
}
