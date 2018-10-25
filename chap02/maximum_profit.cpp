#include<algorithm>
#include<iostream>
using namespace std;
static const int MAX = 200000;

int main() {
  int R[MAX], n;

  cin >> n;
  for (int i = 0; i < n; i++) cin >> R[i];

  // Initialize maximum profit and minimum value
  int maxp = -1000000000;
  int minv = R[0];

  // Update maximum profit and minimum value
  for (int i = 1; i < n; i++){
    maxp = max(maxp, R[i]-minv);
    minv = min(minv, R[i]);
  }

  cout << maxp << endl;
  return 0;
}
