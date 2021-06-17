#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll  long long
#define endl '\n'
using namespace std;
int main() {
  sync;
  while (1) {
    int n; cin >> n;
    if (n == -1) {
      break;
    }
    vector<int> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      sum += v[i];
    }
    if (sum % n) {
      cout << -1 << endl ;
    }
    else {
      ll mx = 0, have = sum / n;
      sum = 0;
      for (int i = 0; i < n; i++) {
        sum += v[i];
        mx = max(mx, abs(sum - (i + 1) * have));
      }
      cout << mx << endl ;
    }
  }

}