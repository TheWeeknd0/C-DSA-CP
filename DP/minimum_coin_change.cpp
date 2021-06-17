#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;

int mincoins(int n, int coins[], int T, int dp[]) {
	if (n == 0) {
		return 0;
	}
	//Look up if min coins to any sub problem is already solved
	if (dp[n] != 0)
		return dp[n];
	// recursive case ..
	int ans = INT_MAX;
	for (int i = 0; i < T; i++) {
		cout << coins[i] << endl;
		if (n - coins[i] >= 0) {
			int subproblem = mincoins(n - coins[i], coins, T, dp);
			ans = min(ans, subproblem + 1);
		}
	}
	return dp[n] = ans;
}

int mincoinsBU(int n, int coins[], int T) {
	int *dp = new int[1000]();
	memset(dp, 0, 1000);
	for (int i = 1; i <= n; i++) {
		int ans = n - 1;
		for (int j = 0; j < T; j++) {
			if (i - coins[j] < 0)
				break;
			else
				ans = min(ans, dp[i - coins[j]]);
		}
		dp[i] = ans + 1;
	}
	return dp[n];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n = 9;
	int coins[] = {1, 3, 2, 4};
	int *dp = new int[1000]();
	memset(dp, 0, 1000);
	dp[0] = 0;
	sort(coins, coins + 4);
	//cout << mincoinsBU(n, coins, 4) << endl;
	cout << mincoins(n, coins, 4, dp);
}