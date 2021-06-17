#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;
int minStepsTo1(int n, int dp[]) {
	if (n == 1)
		return 0;
	if (dp[n] != 0) {
		return dp[n];
	}
	int opt1, opt2, opt3;
	opt1 = opt2 = opt2 = INT_MAX;
	if (n % 3 == 0) {
		opt1 = minStepsTo1(n / 3, dp) + 1;
	}
	if (n % 2 == 0) {
		opt2 = minStepsTo1(n / 2, dp) + 1;
	}
	opt3 = minStepsTo1(n - 1, dp) + 1;
	int ans = min({opt2, opt3, opt1});
	return dp[n] = ans;
}
int minStepsTo1BU(int n) {
	int *dp = new int[n + 1]();
	memset(dp, 0, 200);
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		int opt1, opt2, opt3;
		opt1 = opt2 = opt3 = INT_MAX;
		if (i % 3 == 0) {
			opt1 = dp[i / 3] + 1;
		}
		if (i % 2 == 0) {
			opt2 = dp[i / 2] + 1;
		}
		opt3 = dp[i - 1] + 1;
		dp[i] = min({opt1, opt2, opt3});
	}
	return dp[n];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int *dp = new int[200000000]();
	memset(dp, 0, 200000000);
	cout << minStepsTo1(1201, dp) << endl;
	cout << minStepsTo1BU(1201);
}