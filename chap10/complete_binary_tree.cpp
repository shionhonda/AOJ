#include<iostream>
using namespace std;

int parent(int i) {
  return i/2;
}

int left(int i) {
  return 2*i;
}

int right(int i) {
  return 2*i+1;
}

int main() {
  int H;
  cin >> H;
  int A[H+1];
  for (int i=1; i<=H; i++) {
    cin >> A[i];
  }

  for (int i=1; i<=H; i++) {
    cout << "node " << i << ": key = " << A[i] << ", ";
    if (parent(i)>0) {
      cout << "parent key = " << A[parent(i)] << ", ";
    }
    if (left(i)<=H) {
      cout << "left key = " << A[left(i)] << ", ";
    }
    if (right(i)<=H) {
      cout << "right key = " << A[right(i)] << ", ";
    }
    cout << endl;
  }
  return 0;
}
