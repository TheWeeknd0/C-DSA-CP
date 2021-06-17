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
  int n, d; cin >> n >> d;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  sort(v.begin(), v.end());
  int count = 0;
  for (int i = 1; i < n; i++) {
    if (v[i] - v[i - 1] <= d) {
      i++;
      count++;
    }
  }
  cout << count;

}
