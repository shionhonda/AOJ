#include<iostream>
using namespace std;
#define MAX 100000

typedef struct Process_ {
  char name[10];
  int tm;
} Process;


int head, tail;
Process P[MAX];

void enqueue(Process pc) {
  P[tail] = pc;
  tail = (tail+1)%MAX;
}

Process dequeue() {
  Process pc = P[head];
  head = (head+1)%MAX;
  return pc;
}

int min(int a, int b) {
  if (a<b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  int N, qt, a;
  Process q;
  int elapse = 0;

  cin >> N >> qt;
  for (int i=0; i<N; i++) {
    cin >> P[i].name >> P[i].tm;
  }
  head = 0;
  tail = N;

  while (head != tail) {
    q = dequeue();
    a = min(q.tm, qt);
    q.tm = q.tm - a;
    elapse += a;
    if (q.tm>0) {
      enqueue(q);
    } else {
      cout << q.name << " " << elapse << endl;
    }
  }


  return 0;

}
