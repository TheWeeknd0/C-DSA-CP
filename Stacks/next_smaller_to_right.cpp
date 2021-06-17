#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  sync
  int n;
  cin >> n;
  int array[n];
  for (int i = 0; i < n; i++)                       //aditya verma
    cin >> array[i];
  stack<int> s1;
  vector<int> v;
  for (int i = n - 1; i >= 0; i--) {
    if (s1.empty())
      v.push_back(-1);

    else if (!s1.empty() and s1.top() < array[i]) {
      v.push_back(s1.top());
    }
    else {
      while (!s1.empty() and s1.top() >= array[i]) {
        s1.pop();
      }
      if (!s1.empty())
        v.push_back(s1.top());
      else
        v.push_back(-1);
    }
    s1.push(array[i]);
  }
  reverse(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
}