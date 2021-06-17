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
  int n; cin >> n;
  unordered_map<int, int> m;
  int prefix = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    prefix += a;
    if (!a and !mx)
      mx = 1;
    if (prefix == 0)
      mx = i + 1;
    if (m.count(prefix)) {
      mx = max(mx, i - m[prefix]);
    }
    else {
      m[prefix] = i;
    }
  }
  cout << mx;

}