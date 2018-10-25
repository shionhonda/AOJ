#include<stdio.h>
#include<limits>
using namespace std;

int cnt;

void merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1], R[n2+1];
  for (int i=0; i<n1; i++) {
    L[i] = A[left+i];
  }
  L[n1] = numeric_limits<int>::max();
  for (int i=0; i<n2; i++) {
    R[i] = A[mid+i];
  }
  R[n2] = numeric_limits<int>::max();
  int i=0, j=0;
  for (int k=left; k<right; k++) {
    cnt++;
    if (L[i]<R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int left, int right) {
  if (left+1 < right) {
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  cnt = 0;
  int n;
  scanf("%d", &n);
  int A[n];
  for (int i=0; i<n; i++) {
    scanf("%d", &A[i]);
  }
  mergeSort(A, 0, n);
  for (int i=0; i<n; i++) {
    if (i<n-1) {
      printf("%d ", A[i]);
    } else {
      printf("%d", A[i]);
    }

  }
  printf("\n%d\n", cnt);
  return 0;
}
