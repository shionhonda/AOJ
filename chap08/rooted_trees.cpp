#include<iostream>
#include<string>
using namespace std;
#define MAX 100000
#define NIL -1

struct Node {
  int parent;
  int left;
  int right;
};

Node T[MAX];
int n, D[MAX];

void setDepth(int u, int p) {
  D[u] = p;
  if (T[u].right != NIL) {
    setDepth(T[u].right, p);
  }
  if (T[u].left != NIL) {
    setDepth(T[u].left, p+1);
  }
}

string attr(int u) {
  if (T[u].parent == NIL) {
    return "root, ";
  } else if (T[u].left == NIL) {
    return "leaf, ";
  } else {
    return "internal node, ";
  }
}

void print(int u) {
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].parent << ", ";
  cout << "depth = " << D[u] << ", ";

  cout << attr(u);

  cout << "[";
  int c = T[u].left;
  int i = 0;
  while (c != NIL) {
    if (i>0) {
      cout << ", ";
    }
    cout  << c;
    c = T[c].right;
    i++;
  }
  cout << "]" << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i=0; i<n; i++) {
    T[i].parent = T[i].left = T[i].right = NIL;
  }

  int id, k, tmp, c;
  for (int i=0; i<n; i++) {
    cin >> id >> k;
    tmp = id;
    for (int j=0; j<k; j++) {
      cin >> c;
      if (j==0) {
        T[id].left = c;
      } else {
        T[tmp].right = c;
      }
      tmp = c;
      T[tmp].parent = id;
    }
  }
  int root;
  for (int i=0; i<n; i++) {
    if (T[i].parent == NIL) {
      root = i;
    }
  }

  setDepth(root, 0);

  for (int i=0; i<n; i++) {
    print(i);
  }

  return 0;
}
