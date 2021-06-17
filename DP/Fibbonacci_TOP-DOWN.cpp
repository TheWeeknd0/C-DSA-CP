#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;
int fib(int n, int dp[]) {
  if (n == 1 or n == 0)
    return n;
  if (dp[n] != 0) {
    return dp[n];
  }
  int ans;
  ans = fib(n - 1, dp) + fib(n - 2, dp);
  return dp[n] = ans;
}

int fibBU(int n) {
  int *dp = new int[200]();
  memset(dp, 0, 200);
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
    dp[i] = dp[i - 1] + dp[i - 2];
  return dp[n];
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int *arr = new int[200]();
  memset(arr, 0, sizeof(arr));
  cout << fib(46, arr) << endl;
  cout << INT_MAX << endl;
  cout << fibBU(46);
}