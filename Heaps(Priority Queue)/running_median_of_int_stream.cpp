#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  sync;
  priority_queue<int> leftheap;   //by defualt max heap
  priority_queue<int, vector<int>, greater<int>> rightheap;
  int d; cin >> d;
  float med = d;
  leftheap.push(d);
  cout << "Median " << med << endl;
  cin >> d;
  while (d != -1) {
    if (leftheap.size() > rightheap.size()) {
      if (d < med) {
        rightheap.push(leftheap.top());
        leftheap.pop();
        leftheap.push(d);
      }
      else {
        rightheap.push(d);
      }
      med = (rightheap.top() + leftheap.top()) / 2.0;
    }
    else if (leftheap.size() == rightheap.size()) {
      if (d < med) {
        leftheap.push(d);
        med = leftheap.top();
      }
      else {
        rightheap.push(d);
        med = rightheap.top();
      }
    }
    else {
      if (d > med) {
        leftheap.push(rightheap.top());
        rightheap.pop();
        rightheap.push(d);
      }
      else {
        leftheap.push(d);
      }
      med = (rightheap.top() + leftheap.top()) / 2.0;
    }
    cout << "Median " << med << endl;
    cin >> d;
  }

}