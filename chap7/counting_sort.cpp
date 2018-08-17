#include<stdio.h>
#define k 10000
using namespace std;

void countingSort(int A[], int B[], int n) {
  int C[k];
  for (int i=0; i<k; i++) {
    C[i] = 0;
  }
  // Count A[j]
  for (int j=0; j<n; j++) {
    C[A[j]] ++;
  }
  // Accumulate
  for (int i=1; i<k; i++) {
    C[i] += C[i-1];
  }
  // Sort
  for (int j=n-1; j>=0; j--) {
    B[--C[A[j]]] = A[j];
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int A[n], B[n];
  for (int i=0; i<n; i++) {
    scanf("%d", &A[i]);
  }
  countingSort(A, B, n);
  for (int i=0; i<n; i++) {
    if (i<n-1) {
      printf("%d ", B[i]);
    } else {
      printf("%d\n", B[i]);
    }

  }
  return 0;
}
