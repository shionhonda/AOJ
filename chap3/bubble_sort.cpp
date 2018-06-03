#include<iostream>
using namespace std;

/* Swap and count its number */
int bubbleSort(int A[], int n) {
  int sw = 0;
  bool flg = 1;
  for (int i=0; i<n-1; i++) {
    for (int j=n-1; j>i; j--) {
      if (A[j-1] > A[j]) {
        swap(A[j-1], A[j]);
        sw ++;
      }
    }  
  }
  return sw;
}

int main() {
  int n, sw;
  cin >> n;
  int A[n];
  for (int i=0; i<n; i++) {
    cin >> A[i];
  }
  sw = bubbleSort(A, n);
  for (int i = 0; i<n; i++) {
    if (i>0) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
  cout << sw << endl;
  return 0;
}
