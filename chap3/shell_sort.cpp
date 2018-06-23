#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int cnt;
vector<int> G;

void insertionSort(int A[], int n, int g) {
  for (int i=g; i<n; i++){
    int v = A[i];
    int j = i-g;
    while (j>=0 && A[j]>v) {
      A[j+g] = A[j];
      j = j-g;
      cnt ++;
    }
    A[j+g] = v;
  }
}

void shellSort(int A[], int n){
  int h = 1;
  while (h<=n) {
    G.push_back(h);
    h = 3*h+1;
  }

  for (int i=G.size()-1; i>=0; i--) {
    insertionSort(A, n, G[i]);
  }
}

int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i=0; i<n; i++) {
    scanf("%d", &A[i]);
  }

  cnt = 0;
  shellSort(A, n);

  cout << G.size() << endl;
  for (int i=G.size()-1; i>=0; i--) {
    printf("%d", G[i]);
    if (i>0) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
  cout << cnt << endl;
  for (int i=0; i<n; i++) {
    printf("%d\n", A[i]);
  }

  return 0;
}
