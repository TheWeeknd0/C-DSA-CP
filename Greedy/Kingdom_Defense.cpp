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
  int t; cin >> t;
  while (t--) {
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
      cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int dx = x[0] - 1;
    int dy = y[0] - 1;
    for (int i = 1; i < n; i++) {
      dx = max(dx, x[i] - x[i - 1] - 1);
      dy = max(dy, y[i] - y[i - 1] - 1);
    }
    dx = max(dx, w - x[n - 1]);
    dy = max(dy, h - y[n - 1]);
    cout << dx*dy << endl;
    x.clear();
    y.clear();
  }
}
