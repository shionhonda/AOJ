#include<iostream>
using namespace std;

int n, A[20];

bool solve(int i, int m){
  if (m==0){
    return true;
  }
  if (i>=n) {
    return false;
  }
  return solve(i+1, m) || solve(i+1, m-A[i]);
}

int main(){
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> A[i];
  }
  int q, m;
  cin >> q;
  for (int i=0; i<q; i++) {
    cin >> m;
    if (solve(0, m)){
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
