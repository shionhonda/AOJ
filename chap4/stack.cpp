#include<iostream>
#include<string>
using namespace std;

int S[3];
int top = 0;

void push(int x) {
  top += 1;
  S[top] = x;
}

int pop() {
  top -= 1;
  return S[top+1];
}

int main() {
  string c;
  int a, b;
  while(cin >> c){
    if (c=="+") {
      a = pop();
      b = pop();
      push(a+b);
    } else if (c=="-") {
      a = pop();
      b = pop();
      push(a-b);
    } else if (c=="*") {
      a = pop();
      b = pop();
      push(a*b);
    } else {
      push(stoi(c));
    }
  }
  cout << pop() << endl;;
  return 0;
}
