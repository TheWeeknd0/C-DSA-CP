#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;
int minsteps(int n, int x, int y, int z) {
  int *dp = new int[n + 1];
  //Bottom Up DP
  dp[0] = 0 ;
  dp[1] = 0 ;

  for (int i = 2; i <= n; i++) {

    if (i % 2 == 0) {
      dp[i] = min(dp[i / 2] + x , dp[i - 1] + y);
    }
    else {
      dp[i] = min(dp[i - 1] + y, dp[(i + 1) / 2] + x + z);
    }

  }

  return dp[n];

}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int a = 10;
  int b = 5;
  int c = 1;
  cout << minsteps(17, a, b, c);
}