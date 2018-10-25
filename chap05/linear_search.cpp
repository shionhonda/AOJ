#include<iostream>
using namespace std;

// Linear search with sentinel
int search(int A[], int n, int key) {
  A[n] = key;
  int i = 0;
  while(A[i]!=key) {
    i++;
  }
  return i!=n;
}

int main() {
  int n, q, key, sum = 0;
  cin >> n;
  int S[n+1];
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
