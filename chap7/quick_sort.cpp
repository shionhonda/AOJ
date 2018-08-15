#include<stdio.h>
#include<algorithm>
#include<limits>
using namespace std;

struct Card {
  char suit;
  int value;
};

void merge(struct Card A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  struct Card L[n1+1], R[n2+1];
  for (int i=0; i<n1; i++) {
    L[i] = A[left+i];
  }
  L[n1].value = numeric_limits<int>::max();
  for (int i=0; i<n2; i++) {
    R[i] = A[mid+i];
  }
  R[n2].value = numeric_limits<int>::max();
  int i=0, j=0;
  for (int k=left; k<right; k++) {
    if (L[i].value<=R[j].value) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(struct Card A[], int left, int right) {
  if (left+1 < right) {
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}


int partition(struct Card A[], int p, int r) {
  struct Card x;
  x = A[r];
  int i = p-1;
  for (int j=p; j<r; j++) {
    if (A[j].value<=x.value) {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i+1], A[r]);
  return i+1;
}

void quickSort(struct Card A[], int p, int r) {
  if (p<r) {
    int q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

bool isStable(struct Card A[], struct Card B[], int n) {
  for (int i=0; i<n; i++) {
    if (A[i].suit != B[i].suit) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  struct Card A[n], B[n];
  char suit[2];
  int value;
  for (int i=0; i<n; i++) {
    scanf("%s %d", suit, &value);
    A[i].suit = B[i].suit = suit[0];
    A[i].value = B[i].value = value;
  }

  mergeSort(A, 0, n);
  quickSort(B, 0, n-1);

  if (isStable(A, B, n)) {
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }
  for (int i=0; i<n; i++) {
    printf("%c %d\n", B[i].suit, B[i].value);
  }
  return 0;
}
