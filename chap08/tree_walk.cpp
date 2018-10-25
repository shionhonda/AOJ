#include<iostream>
using namespace std;
#define MAX 25
#define NIL -1

struct Node {
  int parent;
  int left;
  int right;
};

Node T[MAX];
int n;

void preorder(int v) {
  if (v==NIL) {
    return;
  }
  cout << " " << v;
  preorder(T[v].left);
  preorder(T[v].right);
}

void inorder(int v) {
  if (v==NIL) {
    return;
  }
  inorder(T[v].left);
  cout << " " << v;
  inorder(T[v].right);
}

void postorder(int v) {
  if (v==NIL) {
    return;
  }
  postorder(T[v].left);
  postorder(T[v].right);
  cout << " " << v;
}

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    T[i].parent = T[i].left = T[i].right = NIL;
  }

  int v, l, r;
  for (int i=0; i<n; i++) {
    cin >> v >> l >> r;
    T[v].left = l;
    T[v].right = r;
    if (l!=NIL) {
      T[l].parent = v;
    }
    if (r!=NIL) {
      T[r].parent = v;
    }
  }

  int root;
  for (int i=0; i<n; i++) {
    if (T[i].parent == NIL) {
      root = i;
    }
  }

  cout << "Preorder" << endl;
  preorder(root);
  cout << endl;
  cout << "Inorder" << endl;
  inorder(root);
  cout << endl;
  cout << "Postorder" << endl;
  postorder(root);
  cout << endl;

  return 0;
}
