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
    ll n, l, r;
    cin >> n >> l >> r;
    vector< pair<int, int> > p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i].first >> p[i].second;
    }
    ll sumodd = 1, sumeven = 2;
    for (int i = 0; i < n; i++) {
      sumodd = (p[i].first * sumodd + p[i].second);
    }
    for (int i = 0; i < n; i++) {
      sumeven = (p[i].first * sumeven + p[i].second);
    }

    ll totalodd = 0, totaleven = 0;
    if (l % 2 == 1 and r % 2 == 1) {
      totaleven = (r - l + 1) / 2;
      totalodd = (r - l + 1) / 2 + 1 ;
    }
    else if (l % 2 == 0 and r % 2 == 0) {
      totalodd = (r - l + 1) / 2;
      totaleven = (r - l + 1) / 2  + 1;
    }
    else {
      totalodd = (r - l + 1) / 2;
      totaleven = (r - l + 1) / 2 ;
    }
    //cout << "sumodd " << sumodd << " sumeven " << sumeven << endl;
    if (sumodd % 2 == 0 and sumeven % 2 == 0) {
      cout << r - l + 1 << ' ' << 0 << endl;
    }
    else if (sumeven % 2 == 1 and sumodd % 2 == 1) {
      cout << 0 << ' ' << r - l + 1 << endl;
    }
    else if (sumodd % 2 == 0 and sumeven % 2 == 1) {
      cout << totalodd << ' ' << totaleven << endl;
    }
    else if (sumodd % 2 == 1 and sumeven % 2 == 0) {
      cout << totaleven << ' ' << totalodd << endl;
    }
  }
}