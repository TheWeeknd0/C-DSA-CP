#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
bool canplacecows(int stalls[], int n, int k, int cows) {
  int last_cow = stalls[0], count = 1;
  for (int i = 1; i < n; i++) {
    if (stalls[i] - last_cow >= k) {
      count++;
      last_cow = stalls[i];
    }
    if (count == cows)
      return true;
  }
  return false;
}
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  sync
  int n, cows;
  cin >> n >> cows;
  int stalls[n];
  for (auto & i : stalls) {
    cin >> i;
  }
  sort(stalls, stalls + n);
  int s = 0;
  int e = stalls[n - 1] - stalls[0], ans = 0;
  while (s <= e) {
    int mid = (s + e) / 2;
    if (canplacecows(stalls, n, mid, cows)) {
      ans = mid;
      s = mid + 1;
    }
    else
      e = mid - 1;
  }
  cout << ans;

}
