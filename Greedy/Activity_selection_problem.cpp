#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2) {
  return p1.second < p2.second;
}
int MaxActivity(vector< pair<int, int> > v) {
  int ans = 1;
  sort(v.begin(), v.end(), compare);
  int endtime = v[0].second;
  for (int i = 1; i < v.size(); i++) {
    if (v[i].first >= endtime) {
      endtime = v[i].second;
      ans++;
    }
  }
  return ans;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  vector< pair<int, int> > v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].first >> v[i].second;
  cout << MaxActivity(v);
  v.clear();

}