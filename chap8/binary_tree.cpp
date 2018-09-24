#include<iostream>
#include<string>
using namespace std;
#define MAX 25
#define NIL -1

struct Node {
  int parent;
  int left;
  int right;
};

Node T[MAX];
int n, D[MAX], H[MAX];

void setDepth(int v, int d){
  if (v==NIL) {
    return;
  }
  D[v] = d;
  setDepth(T[v].left, d+1);
  setDepth(T[v].right, d+1);
}

int setHeight(int v) {
  if (v==NIL) {
    return -1;
  }
  int h1 = setHeight(T[v].left)+1;
  int h2 = setHeight(T[v].right)+1;
  return H[v] = max(h1, h2);
}

int getSibling(int v) {
  if (T[v].parent==NIL) {
    return NIL;
  } else {
    int l = T[T[v].parent].left;
    if (l!=v) {
      return l;
    } else {
      return T[T[v].parent].right;
    }
  }
}

int getDegree(int v) {
  if (T[v].left!=NIL && T[v].right!=NIL) {
    return 2;
  } else if (T[v].left!=NIL || T[v].right!=NIL) {
    return 1;
  } else {
    return 0;
  }
}

string attr(int v) {
  if (T[v].parent==NIL) {
    return "root";
  } else if (T[v].left==NIL && T[v].right==NIL) {
    return "leaf";
  } else {
    return "internal node";
  }
}

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    T[i].parent = T[i].left = T[i].right = NIL;
  }

  int id, l, r;
  for (int i=0; i<n; i++) {
    cin >> id >> l >> r;
    T[id].left = l;
    T[id].right = r;
    if (l!=NIL) {
      T[l].parent = id;
    }
    if (r!=NIL) {
      T[r].parent = id;
    }
  }

  int root;
  for (int i=0; i<n; i++) {
    if (T[i].parent == NIL) {
      root = i;
    }
  }

  setDepth(root, 0);
  setHeight(root);

  for (int i=0; i<n; i++) {
    cout << "node " << i << ": ";
    cout  << "parent = " << T[i].parent << ", ";
    cout << "sibling = " << getSibling(i) << ", ";
    cout << "degree = " << getDegree(i) << ", ";
    cout << "depth = " << D[i] << ", ";
    cout << "height = " << H[i] << ", ";
    cout << attr(i) << endl;
  }

  return 0;
}
