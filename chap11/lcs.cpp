#include<iostream>
#include<string>
using namespace std;

int lcs(string X, string Y) {
  int m = X.size();
  int n = Y.size();
  int c[m+1][n+1];
  X = ' ' + X;
  Y = ' ' + Y;
  for (int i=0; i<m+1; i++) {
    c[i][0] = 0;
  }
  for (int j=0; j<n+1; j++) {
    c[0][j] = 0;
  }

  int max_lcs = 0;
  for (int i=1; i<m+1; i++) {
    for (int j=1; j<n+1; j++) {
      if (X[i]==Y[j]) {
        c[i][j] = c[i-1][j-1] + 1;
      } else {
        c[i][j] = max(c[i-1][j], c[i][j-1]);
      }
      max_lcs = max(max_lcs, c[i][j]);
    }
  }

  return max_lcs;
}


int main() {
  int N;
  string X, Y;
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> X >> Y;
    cout << lcs(X, Y) << endl;
  }
  return 0;
}
