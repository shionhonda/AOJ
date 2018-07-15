#include<iostream>
using namespace std;

// Binary search
int search(int A[], int n, int key) {
  int start = 0;
  int end = n;
  while (start<end) {
    int mid = (start+end)/2; // Floor
    if (key == A[mid]) {
      return 1;
    } else if (key < A[mid]) {
      end = mid;
    } else {
      start = mid+1;
    }
  }
  return 0;
}

int main() {
  int n, q, key, sum = 0;
  cin >> n;
  int S[n];
  for (int i=0; i<n; i++) {
    cin >> S[i];
  }
  cin >> q;
  for (int i=0; i<q; i++) {
    cin >> key;
    if (search(S, n, key)) {
        sum++;
    }
  }
  cout << sum << endl;
  return 0;
}
