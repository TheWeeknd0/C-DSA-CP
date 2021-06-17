#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;

int MultChainTD(int m[], int i, int j, int dp[][100]) {
	if (i == j) {
		dp[i][j] = 0;
		return 0;
	}
	if (dp[i][j] != -1)
		return dp[i][j];
	int ans = INT_MAX;
	for (int k = i; k < j; k++) {
		int temp = MultChainTD(m, i, k, dp) + MultChainTD(m, k + 1, j, dp) + m[i - 1] * m[k] * m[j];
		ans = min(ans, temp);
	}
	return dp[i][j] = ans;
}

int MultChainBU(int m[], int n) {
	int dp[100][100];
	memset(dp, 0, sizeof dp);

	for (int L = 2; L < n; L++) {
		for (int i = 1; i <= n - L; i++) {
			int j = i + L - 1;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[k + 1][j] + dp[i][k] + m[i - 1] * m[k] * m[j]);
			}
		}
	}
	return dp[1][n - 1];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int m[] = {1, 2, 3, 4};
	int dp[100][100];
	memset(dp, -1, sizeof dp);
	int n = sizeof(m) / sizeof(int);
	cout << MultChainTD(m, 1, n - 1, dp);
	cout << endl;
	//for (int i = 1; i < n; i++) {
	//for (int j = 1; j < n; j++) {
	//cout << dp[i][j] << ' ';
	//}
	//cout << endl;
	//}
	cout << MultChainBU(m, n);
}