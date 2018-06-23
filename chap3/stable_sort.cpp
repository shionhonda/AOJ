#include<iostream>
using namespace std;

struct Card {
  char suit;
  int value;
};

/* Bubble sort */
void bubble(struct Card A[], int n) {
  for (int i=0; i<n-1; i++) {
    for (int j=n-1; j>i; j--) {
      if (A[j-1].value > A[j].value) {
        swap(A[j-1], A[j]);
      }
    }
  }
}

/* Selection sort */
void selection(struct Card A[], int n) {
  for (int i=0; i<n; i++) {
    int minj = i;
    for (int j=i; j<n; j++) {
      if (A[j].value < A[minj].value){
        minj = j;
      }
    }
    if (i < minj){
      swap(A[i], A[minj]);
    }
  }
}

/* Output sort result */
void print(struct Card A[], int n) {
  for (int i=0; i<n; i++) {
    if (i>0) {
      cout << " ";
    }
    cout << A[i].suit << A[i].value;
  }
  cout << endl;
}

bool isStable(struct Card C1[], struct Card C2[], int n) {
  for (int i=0; i<n; i++) {
    if (C1[i].suit != C2[i].suit) {
      return false;
    }
  }
  return true;
}

int main() {
  int N;
  char suit;

  cin >> N;
  Card C1[N], C2[N];
  for (int i=0; i<N; i++) {
    cin >> C1[i].suit >> C1[i].value;
    C2[i] = C1[i];
  }

  bubble(C1, N);
  selection(C2, N);

  print(C1, N);
  cout << "Stable" <<endl;
  print(C2, N);
  if (isStable(C1, C2, N)) {
    cout << "Stable" <<endl;
  } else {
    cout << "Not stable" <<endl;
  }

  return 0;
}
