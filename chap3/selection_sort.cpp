#include<iostream>
using namespace std;

/* Select minimum and swap */
int selectionSort(int A[], int n) {
  int cnt = 0;
  for (int i=0; i<n; i++) {
    int minj = i;
    for (int j=i; j<n; j++) {
      if (A[j] < A[minj]){
        minj = j;
      }
    }
    if (i < minj){
      swap(A[i], A[minj]);
      cnt ++;
    }
  }
  return cnt;
}

int main() {
  int n, cnt;
  cin >> n;
  int A[n];
  for (int i=0; i<n; i++) {
    cin >> A[i];
  }
  cnt = selectionSort(A, n);
  for (int i = 0; i<n; i++) {
    if (i>0) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}
