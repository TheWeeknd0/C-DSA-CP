#include<bits/stdc++.h>
using namespace std;
class Stack {
private:
  int *arr;
  int top;
public:
  Stack(int size) {
    arr = new int [size];
    top = 0;
  }
  void push(int data) {
    top++;
    arr[top] = data;
  }
  bool empty() {
    return top == 0;
  }
  void pop() {
    if (top != 0) {
      arr[top] = 0;
      top--;
    }
  }
  int top1() {
    return arr[top];
  }
};
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cout << "Enter the size of the Stack\n";
  int n; cin >> n;
  Stack s(n);
  for (int i = 1; i <= 5; i++) {
    s.push(i * i);
  }
  while (!s.empty()) {
    cout << s.top1() << " ";
    s.pop();
  }
}