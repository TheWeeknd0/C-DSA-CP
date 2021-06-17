#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;
int profit(int wines[], int i, int j, int y, int dp[][100]) {
	if (i > j)
		return 0;
	if (dp[i][j])
		return dp[i][j];

	int op1 = wines[i] * y + profit(wines, i + 1, j, y + 1, dp);
	int op2 = wines[j] * y + profit(wines, i, j - 1, y + 1, dp);
	//cout << wines[i] << ' ' << wines[j] << endl;
	//cout << op1 << ' ' << op2 << endl;
	return dp[i][j] = max(op1, op2);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sync;
	int wines[] = {2, 4, 6, 5};
	int dp[100][100] = {};
	cout << profit(wines, 0, 3, 1, dp);
}