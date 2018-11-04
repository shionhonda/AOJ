#include<iostream>
using namespace std;

int main() {
  int FB[45];
  FB[0] = FB[1] = 1;
  int n;
  cin >> n;
  if (n>1) {
    for (int i=2; i<=n; i++) {
      FB[i] = FB[i-1] + FB[i-2];
    }
  }
  cout << FB[n] << endl;
}
