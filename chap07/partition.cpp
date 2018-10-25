#include<stdio.h>
using namespace std;

int A[100000];

int partition(int p, int r) {
  int x = A[r];
  int i = p-1;
  for (int j=p; j<r; j++) {
    if (A[j]<=x) {
      i++;
      int tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  int tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
  return i+1;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &A[i]);
  }
  int idx = partition(0, n-1);
  for (int i=0; i<n; i++) {
    if (i>0) {
      printf(" ");
    }
    if (i==idx) {
      printf("[");
    }
    printf("%d", A[i]);
    if (i==idx) {
      printf("]");
    }
  }
  printf("\n");
}
