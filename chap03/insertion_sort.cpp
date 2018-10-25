#include<iostream>
using namespace std;

/* Print table */
void trace(int A[], int n) {
  int i;
  for (i=0; i<n; i++) {
    if (i>0) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
}

int main() {
  int n, i, j, v;
  cin >> n;
  int A[n];
  for (i=0; i<n; i++) {
    cin >> A[i];
  }
  trace(A, n);
  for (i=1; i<n; i++) {
    v = A[i];
    j = i-1;
    while (j>=0 && A[j]>v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    trace(A, n);
    }
  
  return 0;
}
