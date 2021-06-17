#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool enoughcoupans(ll n, ll mid, ll m, ll x, ll y) {
  ll present_coupan = m + (n - mid) * y;
  ll used_coupan = mid * x;
  if (present_coupan >= used_coupan)
    return true;
  else
    return false;
}
ll max_students(ll n, ll m, ll x, ll y) {
  ll s = 0;
  ll e = n;
  ll ans = 0;
  while (s <= e) {
    ll mid = (s + e) / 2;
    if (enoughcoupans(n, mid, m, x, y)) {
      ans = mid;
      s = mid + 1;
    }
    else
      e = mid - 1;
  }
  return ans;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ll n, m, x, y;
  cin >> n >> m >> x >> y;
  cout << max_students(n, m, x, y);
}