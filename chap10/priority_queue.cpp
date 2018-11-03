#include <stdio.h>
#include <string>
using namespace std;
#define MAX 2000000
#define INFTY (1<<30)

int H, A[MAX+1];

void maxHeapify(int i) {
  int argmax = i;
  int l = 2*i;
  int r = 2*i + 1;
  if (l<=H && A[argmax]<A[l]) {
    argmax = l;
  }
  if (r<=H && A[argmax]<A[r]) {
    argmax = r;
  }

  if (argmax!=i) {
    swap(A[i], A[argmax]);
    maxHeapify(argmax);
  }
}

int extract() {
  int maxv;
  if (H<1) {
    return -INFTY;
  }
  maxv = A[1];
  A[1] = A[H--];
  maxHeapify(1);
  return maxv;
}

void increaseKey(int i, int key) {
  if (key<A[i]) {
    return;
  }
  A[i] = key;
  while (i>1 && A[i/2]<A[i]) {
    swap(A[i], A[i/2]);
    i = i/2;
  }
}

void insert(int key) {
  H++;
  A[H] = -INFTY;
  increaseKey(H, key);
}

int main() {
  int key;
  char com[9];
  while (1) {
    scanf("%s", com);
    if (com[0]=='e' && com[1]=='n') {
      break;
    }
    if (com[0]=='i') {
      scanf("%d", &key);
      insert(key);
    }
    if (com[0]=='e') {
      printf("%d\n", extract());
    }
  }
  return 0;
}
