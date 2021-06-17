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
  int n; cin >> n;
  int array[n + 1] = {0};
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    array[a]++;
  }
  int sum = 0, actual = 1;
  for (int i = 1; i <= n; i++) {
    while (array[i]) {
      array[i]--;
      sum += abs(actual - i);
      actual++;
    }
  }
  cout << sum;
}